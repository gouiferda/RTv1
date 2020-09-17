#include "headers.h"



int			solve_quadratic(t_quadratic *q, double *t)
{
	double	discr;
	double	temp;

	discr = SQ(q->b) - 4.0 * q->a * q->c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		q->x0 = -0.5 * q->b / q->a;
		q->x1 = q->x0;
	}
	else
	{
		temp = (q->b > 0.0) ? (q->b + sqrt(discr)) / -2.0 :
			(q->b - sqrt(discr)) / -2.0;
		q->x0 = temp / q->a;
		q->x1 = q->c / temp;
	}
	return (check_quadratic_results(q, t));
}

int			check_quadratic_results(t_quadratic *q, double *t)
{
	if (q->x0 > q->x1)
		SWAP(q->x0, q->x1, double);
	if (q->x0 < 0.0)
	{
		q->x0 = q->x1;
		if (q->x0 < 0.0)
			return (0);
	}
	*t = q->x0;
	return (1);
}

void		v_init(t_vect3 *v, double x, double y, double z)
{
	(*v)[0] = x;
	(*v)[1] = y;
	(*v)[2] = z;
}


void		v_mult(double scalar, t_vect3 *v, t_vect3 *result)
{
	t_vect3	mult;

	v_init(&mult, scalar, scalar, scalar);
	*result = *v * mult;
}


int				cylinder_intersect(t_obj *obj, t_ray *ray, double *t)
{
	t_quadratic	q;
	t_vect3		dp;
	double		scal_a;
	t_vect3		vect_a;
	t_vect3		vect_b;

	v_subtract(&ray->orig, &obj->center, &dp);
	scal_a = v_dot(&ray->dir, &obj->dir);
	v_mult(scal_a, &obj->dir, &vect_a);
	v_subtract(&ray->dir, &vect_a, &vect_a);
	q.a = v_dot(&vect_a, &vect_a);
	scal_a = v_dot(&dp, &obj->dir);
	v_mult(scal_a, &obj->dir, &vect_b);
	v_subtract(&dp, &vect_b, &vect_b);
	q.b = 2.0 * v_dot(&vect_a, &vect_b);
	q.c = v_dot(&vect_b, &vect_b) - obj->radius * obj->radius;
	return (solve_quadratic(&q, t));
}





int main()
{
    
    // repere = screen (start and finish)
    

    //ray only
    t_ray ray;
    int z_range = 1000;
    ray.pos = newVect(0,0,-z_range);
    ray.dir = newVect(0,0,z_range);


    //object 
    t_figure obj;
    obj.pos = newVect(300,300,300);
    obj.radius = 100;
    obj.type = CYLINDER; // (cylinder / con / plane ..)
    obj.dir = vectSub(newVect(300,300,300),obj.pos); //direction 
	

    //intersection
    t_vector p_i;
    float is_inter;
    is_inter = ft_inter_cylinder(ray,obj);
	printf("is_intersected: %.2f \n",is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}
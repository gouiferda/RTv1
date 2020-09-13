#include "headers.h"





t_vector	ft_vect_sub(t_vector u, t_vector v)
{
	t_vector vec;

	vec.x = u.x - v.x;
	vec.y = u.y - v.y;
	vec.z = u.z - v.z;
	return (vec);
}

t_vector	ft_vect_norm(t_vector *vec)
{
	double	w;

	w = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	if (w)
	{
		vec->x /= w;
		vec->y /= w;
		vec->z /= w;
	}
	else
		*vec = (t_vector){0, 0, 0};
	return (*vec);
}

double		ft_vect_dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}


double	equation_solve(double a, double b, double c)
{
	double	delta;
	double	inter1;
	double	inter2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	inter1 = (-b - sqrt(delta)) / (2 * a);
	inter2 = (-b + sqrt(delta)) / (2 * a);
	if ((inter2 < MIN_NBR && inter1 < MIN_NBR))
		return (0);
	if ((inter2 < MIN_NBR))
		return (inter1);
	if ((inter1 < MIN_NBR))
		return (inter2);
	return (fmin(inter1, inter2));
}



double	cylinder_intersection(t_ray r, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	obj_center;

	obj_center = ft_vect_sub(r.ori, obj->ori);
	ft_vect_norm(&obj->axi);
	a = ft_vect_dot(r.dir, r.dir) - ft_vect_dot(r.dir, obj->axi) *
												ft_vect_dot(r.dir, obj->axi);
	b = 2 * (ft_vect_dot(r.dir, obj_center) -
	(ft_vect_dot(r.dir, obj->axi) * ft_vect_dot(obj_center, obj->axi)));
	c = ft_vect_dot(obj_center, obj_center) -
			ft_vect_dot(obj_center, obj->axi) *
						ft_vect_dot(obj_center, obj->axi) - obj->ray * obj->ray;
	return (equation_solve(a, b, c));
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
    t_figure s;
    s.pos = newVect(0,0,0);
    s.radius = 100;
    s.color = 125678;
    s.type = SPHERE;
    //s.dir = ... //direction (cylinder / con / plane ..)


    //intersection
    t_vector p_i;
    int is_inter = 0;

    is_inter = sphere_ray_inter(ray,s,&p_i);
  


    printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


    return 0;
}

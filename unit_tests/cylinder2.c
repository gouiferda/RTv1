#include "headers.h"






t_vector	ft_sub(t_vector a, t_vector b)
{
	return (VEC(a.x - b.x, a.y - b.y, a.z - b.z));
}

double		ft_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	ft_pro_k(t_vector a, double k)
{
	return (VEC(a.x * k, a.y * k, a.z * k));
}


t_vector	ft_normalize(t_vector a)
{
	float k;

	if (a.x == 0.0 && a.y == 0.0 && a.z == 0.0)
		return (VEC(0, 0, 0));
	k = 1.0 / sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (ft_pro_k(a, k));
}


t_vector	ft_add(t_vector a, t_vector b)
{
	return (VEC(a.x + b.x, a.y + b.y, a.z + b.z));
}


t_vector	ft_ray_function(t_ray *r, double t)
{
	return (ft_add(r->pos, ft_pro_k(r->dir, t)));
}

int			ft_hit_cylinder(t_figure *o, t_ray *r, t_interval t, t_hit *rec)
{
	rec->oc = ft_sub(r->pos, o->pos);
	rec->coef[0] = ft_dot(r->dir, r->dir) - pow(ft_dot(r->dir, o->rot), 2);
	rec->coef[1] = 2 * (ft_dot(r->dir, rec->oc) - (ft_dot(r->dir, o->rot)
				* ft_dot(rec->oc, o->rot)));
	rec->coef[2] = ft_dot(rec->oc, rec->oc) - pow(ft_dot(rec->oc, o->rot), 2)
		- o->size * o->size;
	rec->delta = rec->coef[1] * rec->coef[1] - 4 * rec->coef[0] * rec->coef[2];
	if (rec->delta >= 0)
	{
		rec->r[0] = (-rec->coef[1] - sqrt(rec->delta)) / (2 * rec->coef[0]);
		rec->r[1] = (-rec->coef[1] + sqrt(rec->delta)) / (2 * rec->coef[0]);
		rec->r[0] = rec->r[0] < rec->r[1] ? rec->r[0] : rec->r[1];
		if (rec->r[0] < t.t_max && rec->r[0] > t.t_min)
		{
			rec->t = rec->r[0];
			rec->p = ft_ray_function(r, rec->t);
			rec->n = ft_normalize(ft_sub(ft_sub(rec->p, o->pos),
						ft_pro_k(o->rot, ft_dot(r->dir, o->rot)
							* rec->t + ft_dot(rec->oc, o->rot))));
			return (1);
		}
	}
	return (0);
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

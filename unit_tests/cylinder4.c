#include "headers.h"


double			*hit_cylinder(t_ray *ray, t_shape *shape, double a, double b)
{
	t_vector	oc;
	double		*xs;
	double		c;
	double		disc;

	xs = (double *)malloc(sizeof(double) * 2);
	xs[0] = MAX_I;
	xs[1] = MAX_I;
	oc = ray->a - shape->center;
	a = dot(ray->b, ray->b) - pow(dot(ray->b, shape->axis_v), 2);
	b = 2 * (dot(ray->b, oc) - (dot(ray->b, shape->axis_v) *
		dot(oc, shape->axis_v)));
	c = dot(oc, oc) - pow(dot(oc, shape->axis_v), 2) -
	shape->radius * shape->radius;
	disc = b * b - 4 * a * c;
	if (disc >= 0)
	{
		xs[0] = (-b + sqrt(disc)) / (2.0 * a);
		xs[1] = (-b - sqrt(disc)) / (2.0 * a);
	}
	return (xs);
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
    is_inter = cylinder_intersection(ray,obj);
	printf("is_intersected: %.2f \n",is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}
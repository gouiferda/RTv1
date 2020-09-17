#include "headers.h"



int					intersect_cylinder(t_line line, t_object obj, double sols[MAX_DEGREE])
{
	t_quadratic	equa;
	double		radic;

	equa = (t_quadratic){.a = (line.v.z * line.v.z) + (line.v.y * line.v.y),
		.b = 2 * ((line.o.z * line.v.z) + (line.o.y * line.v.y)),
		.c = (line.o.z * line.o.z) + (line.o.y * line.o.y) -
			(obj.object_union.cylinder.radius *
			obj.object_union.cylinder.radius)};
	radic = (equa.b * equa.b) - (4 * equa.a * equa.c);
	if (radic < 0.0)
		return (0);
	sols[0] = (-equa.b + sqrt(radic)) / (2.0 * equa.a);
	sols[1] = (-equa.b - sqrt(radic)) / (2.0 * equa.a);
	return (2);
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
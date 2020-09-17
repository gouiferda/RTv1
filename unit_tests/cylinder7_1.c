#include "headers.h"



float	ft_min_posi(float t1, float t2)
{
	if (t1 < t2)
	{
		if (t1 > 0)
			return (t1);
		else
			return (t2);
	}
	else if (t1 > t2)
	{
		if (t2 > 0)
			return (t2);
		else
			return (t1);
	}
	return (INFINIT);
}


float	ft_inter_cylinder(t_figure cam, t_obj obj, t_val *v)
{
	t_vect	x;
	t_var	var;
	float	t1;

	x = vectSub(cam.pos, obj.pos);
	var.a = (vectDot(cam.ray, cam.ray) - (vectDot(cam.ray, obj.dir)
			* vectDot(cam.ray, obj.dir)));
	var.b = 2 * (vectDot(cam.ray, x) - (vectDot(cam.ray, obj.dir)
				* vectDot(x, obj.dir)));
	var.c = (vectDot(x, x) - (vectDot(x, obj.dir) *
				vectDot(x, obj.dir)) - (obj.rad * obj.rad));
	var.d = var.b * var.b - (4 * var.a * var.c);
	if (var.d < 0)
		return (INFINIT);
	var.t1 = (-var.b + sqrtf(var.d)) / (2 * var.a);
	var.t2 = (-var.b - sqrtf(var.d)) / (2 * var.a);
	if ((var.t1 < 0 && var.t2 < 0))
		return (INFINIT);
	t1 = ft_min_posi(var.t1, var.t2);
	t1 -= 0.2;
	if (t1 < v->dis)
		v->m = vectDot(cam.ray, obj.dir) * t1 + (vectDot(x, obj.dir));
	return (ft_min_posi(var.t1, var.t2));
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
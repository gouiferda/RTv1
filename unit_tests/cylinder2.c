#include "headers.h"




double	get_t(double a, double b, double d)
{
	double t1;
	double t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	else if ((t2 <= t1 && t2 >= 0) || (t1 < 0 && t2 >= 0))
		return (t2);
	return (-1);
}
//cylinder_intersect(ray->orig, ray->dir, obj)
double	cylinder_intersect(t_ray ray, t_figure obj)
{
	t_vector o=ray.pos;
	t_vector dir=ray.dir;
	double	a;
	double	b;
	double	c;
	double	d;
	t_vector	x;

	x = vectSub(o, obj.pos);
	a = vectDot(dir, dir) - pow(vectDot(dir, obj.dir), 2);
	b = 2 * (vectDot(dir, x) - (vectDot(dir, obj.dir) * vectDot(x, obj.dir)));
	c = vectDot(x, x) - pow(vectDot(x, obj.dir), 2) - pow(obj.radius, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_t(a, b, d));
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
    s.radius = 10;
    //s.color = 125678;
    s.type = CYLINDER;//(cylinder / con / plane ..)
    s.dir = newVect(0,10,300); //direction 


    //intersection
    t_vector p_i;
    double is_inter = 0;

    is_inter = cylinder_intersect(ray,s);
  
	printf("is_intersected2: %.2f \n",is_inter);

   // printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


    return 0;
}

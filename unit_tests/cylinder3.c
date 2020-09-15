#include "headers.h"

double solution(float a, float b, float c)
{
    double discriminant;
    double t1;
    double t2;

    discriminant = ((b * b) - (4 * a * c));
    if (discriminant < 0)
        return (FAR);
    if (discriminant == 0)
        return (-b / 2 * a);
    t1 = (-b + sqrt(discriminant)) / (2 * a);
    t2 = (-b - sqrt(discriminant)) / (2 * a);
    if (t1 < t2 && t1 > 0 && t1 < 100000)
        return (t1);
    if (t2 < t1 && t2 > 0 && t2 < 100000)
        return (t2);
    return (FAR);
}

double	cylinder_intersection(t_ray r, t_figure obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	obj_center;

	obj_center = vectSub(r.pos, obj.pos);
	obj.dir = vectNorm(obj.dir);
	a = vectDot(r.dir, r.dir) - vectDot(r.dir, obj.dir) * vectDot(r.dir, obj.dir);
	b = 2 * (vectDot(r.dir, obj_center) -
	(vectDot(r.dir, obj.dir) * vectDot(obj_center, obj.dir)));
	c = vectDot(obj_center, obj_center) - vectDot(obj_center, obj.dir) * 
        vectDot(obj_center, obj.dir) - obj.radius * obj.radius;
	return (solution(a, b, c));
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



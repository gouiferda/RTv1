#include "headers.h"

double hit_cylinder(t_ray ray, t_figure shape)
{
	t_vector oc;
	double *xs;
	double c;
	double disc;
	double a;
	double b;

	xs = (double *)malloc(sizeof(double) * 2);
	xs[0] = 1000;
	xs[1] = 1000;
	oc = vectSub(ray.pos, shape.pos);
	a = vectDot(ray.dir, ray.dir) - pow(vectDot(ray.dir, shape.dir), 2);
	b = 2 * (vectDot(ray.dir, oc) - (vectDot(ray.dir, shape.dir) *
									 vectDot(oc, shape.dir)));
	c = vectDot(oc, oc) - pow(vectDot(oc, shape.dir), 2) -
		shape.radius * shape.radius;
	disc = b * b - 4 * a * c;
	if (disc >= 0)
	{
		xs[0] = (-b + sqrt(disc)) / (2.0 * a);
		xs[1] = (-b - sqrt(disc)) / (2.0 * a);
	}
	return (xs[0]);
}

int main()
{

	// repere = screen (start and finish)

	//ray only
	t_ray ray;
	int z_range = 1000;
	ray.pos = newVect(0, 0, -z_range);
	ray.dir = newVect(0, 0, z_range);

	//object
	t_figure obj;
	obj.pos = newVect(0, 0,0);
	obj.radius = 100;
	obj.type = CYLINDER;								// (cylinder / con / plane ..)
	obj.dir = vectSub(newVect(10, 10, 300),obj.pos); //direction

	//intersection
	t_vector p_i;
	double is_inter;
	is_inter = hit_cylinder(ray, obj);
	printf("is_intersected: %.2f \n", is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);

	return 0;
}
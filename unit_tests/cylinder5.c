#include "headers.h"



double		limit_cylinder(double cylinder_height, t_object cylinder, t_vec cam,
								double tmp, double t)
{
	double	m;

	m = tmp * t + vectDot(vectSub(cam, cylinder->center), cylinder->normal);
	return ((m < 0.0 || m > cylinder.height) ? INFINITY : t);
}


void			intersect_cylinder(t_vec camera, t_vec dir,
									t_object *cylinder, double *ts)
{
	t_vector		oc;
	double		k[3];
	double		d;
	double		tmp;
	t_vector camera = ray.pos;
	t_vector dir = ray.dir;
	t_vector cylinder_normal = cylinder.pos;
	double cylider_height = 10;

	tmp = vectDot(dir, cylinder_normal);
	oc = vectSub(camera, cylinder.pos);
	k[0] = vectDot(dir, dir) - tmp * tmp;
	k[1] = 2.0 * (vectDot(dir, oc) - tmp * vectDot(oc, cylinder_normal));
	k[2] = vectDot(oc, oc) - pow(vectDot(oc, cylinder_normal), 2.0) -
						pow(cylinder.radius, 2.0);
	d = sqrt(k[1] * k[1] - 4.0 * k[0] * k[2]);
	if (d < 0.0)
	{
		ts[0] = INFINITY;
		ts[1] = INFINITY;
		return ;
	}
	ts[0] = (-k[1] + d) / (2.0 * k[0]);
	ts[1] = (-k[1] - d) / (2.0 * k[0]);
	if (cylider_height != INFINITY)
	{
		ts[0] = limit_cylinder(cylinder, camera, tmp, ts[0]);
		ts[1] = limit_cylinder(cylinder, camera, tmp, ts[1]);
	}
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
	obj.pos = newVect(0, 0,0);
	obj.radius = 100;
	obj.type = CYLINDER;								// (cylinder / con / plane ..)
	obj.dir = vectSub(newVect(0, 0, 300),obj.pos); //direction
	

    //intersection
    t_vector p_i;
    double *solutions;
	solutions = (double *)malloc(sizeof(double) * 2);
    intersect_cylinder(ray,obj,solutions);
	printf("is_intersected: %.2f , %.2f  \n",solutions[0],solutions[1]);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}
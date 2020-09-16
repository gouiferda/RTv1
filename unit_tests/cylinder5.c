#include "headers.h"


void			intersect_cylinder(t_vec camera, t_vec dir,
									t_object *cylinder, double *ts)
{
	t_vec		oc;
	double		k[3];
	double		d;
	double		tmp;

	tmp = dot(dir, cylinder->normal);
	oc = substruct(camera, cylinder->center);
	k[0] = dot(dir, dir) - tmp * tmp;
	k[1] = 2.0 * (dot(dir, oc) - tmp * dot(oc, cylinder->normal));
	k[2] = dot(oc, oc) - pow(dot(oc, cylinder->normal), 2.0) -
						pow(CYLINDER_D->radius, 2.0);
	d = sqrt(k[1] * k[1] - 4.0 * k[0] * k[2]);
	if (d < 0.0)
	{
		ts[0] = INFINITY;
		ts[1] = INFINITY;
		return ;
	}
	ts[0] = (-k[1] + d) / (2.0 * k[0]);
	ts[1] = (-k[1] - d) / (2.0 * k[0]);
	if (CYLINDER_D->height != INFINITY)
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
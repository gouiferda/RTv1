#include "headers.h"





t_root			hit_cylinder(t_vector dir, t_vector camera, t_figure cylinder)
{
	t_vector	res;
	double		discrim;
	t_root		root;

	res.x = vectDot(dir, dir) - pow(vectDot(dir, cylinder.dir), 2.0);
	res.y = (vectDot(dir, vectSub(camera, cylinder.pos))
				- vectDot(dir, cylinder.dir)
				* vectDot(vectSub(camera, cylinder.pos),
					cylinder.dir)) * 2.0;
	res.z = vectDot(vectSub(camera, cylinder.pos),
						vectSub(camera, cylinder.pos))
			- pow(vectDot(vectSub(camera, cylinder.pos),
							cylinder.dir), 2)
			- (cylinder.radius * cylinder.radius);
	discrim = res.y * res.y - (4.0 * res.x * res.z);
	if (discrim < 0)
		return (t_root){-1, -1};
	root.a = ((-res.y + sqrt(discrim)) / (2.0 * res.x));
	root.b = ((-res.y - sqrt(discrim)) / (2.0 * res.x));
	return (root);
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
    is_inter = hit_cylinder(dir,camera,cylinder);
	printf("is_intersected: %.2f \n",is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}
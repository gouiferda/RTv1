#include "headers.h"





t_root			hit_cylinder(t_vector dir, t_vector camera, t_obj *cylinder)
{
	t_vector	res;
	double		discrim;
	t_root		root;

	res.x = ft_vectDot(dir, dir) - pow(ft_vectDot(dir, cylinder->dir), 2.0);
	res.y = (ft_vectDot(dir, ft_vec_subtract(camera, cylinder->pos))
				- ft_vectDot(dir, cylinder->dir)
				* ft_vectDot(ft_vec_subtract(camera, cylinder->pos),
					cylinder->dir)) * 2.0;
	res.z = ft_vectDot(ft_vec_subtract(camera, cylinder->pos),
						ft_vec_subtract(camera, cylinder->pos))
			- pow(ft_vectDot(ft_vec_subtract(camera, cylinder->pos),
							cylinder->dir), 2)
			- (cylinder->radius * cylinder->radius);
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
    is_inter = cylinder_intersection(ray,obj);
	printf("is_intersected: %.2f \n",is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}
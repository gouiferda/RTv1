#include "headers.h"





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
    s.radius = 100;
    s.color = 125678;
    s.type = SPHERE; // (cylinder / con / plane ..)
    //s.dir = ... //direction 


    //intersection
    t_vector p_i;
    int is_inter = 0;

    // is_inter = sphere_ray_inter(ray,s,&p_i);
  


    // printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


    return 0;
}

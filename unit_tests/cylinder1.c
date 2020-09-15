#include "headers.h"


typedef struct	s_delta
{
	float	a;
	float	b;
	float	c;
	float	delta;
}				t_delta;


static int		ft_min_ray(float t1, float t2, float *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
}


int				ft_cylindre_intersect( t_ray r,t_figure c, float *t)
{
	t_delta		d;
	t_vector	dist;

	d.a = (r.dir.x * r.dir.x + r.dir.z * r.dir.z);
	dist = vectSub(r.pos, c.pos);
	d.b = 2.0 * (dist.x * r.dir.x + dist.z * r.dir.z);
	d.c = (dist.x * dist.x + dist.z * dist.z) - c.radius * c.radius;
	d.delta = d.b * d.b - 4.0 * d.a * d.c;
	if (d.delta < 0.0)
		return (0);
	d.delta = sqrt(d.delta);
	return (ft_min_ray((-d.b + d.delta) / (2.0 * d.a),
				(-d.b - d.delta) / (2.0 * d.a), t));
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
    obj.pos = newVect(-2660,-2000,60);
    obj.radius = 100;
    obj.type = CYLINDER; // (cylinder / con / plane ..)
    obj.dir = newVect(-2660,-2660,30); //direction 
	

    //intersection
    t_vector p_i;
    float is_inter;
    ft_cylindre_intersect(ray,obj,&is_inter);
	printf("is_intersected: %.2f \n",is_inter);
	//printf("is_intersected: %d, point(x,y,z): (%.f,%.f,%.f) \n",is_inter, p_i.x, p_i.y,p_i.z);


	return 0;
}



//



/*
Intersection Cylinder::hit(Ray ray)
{
    ray.setOrigin(vec3(getInverseTransform() * vec4(ray.getOrigin(),1)));
    ray.setDirection(glm::normalize(vec3(getInverseTransform() * vec4(ray.getDirection(),0))));

    // R(t) = o + td
    // x² + z² = r²
    // (ox+tdx)² + (oz+tdz)² = r²
    // (ox)² + 2oxtdx + (tdx)² + (oz)² + 2oztdz + (tdz)² = r²
    // t²(dx + dz) + 2t(oxdx + ozdz) + (ox)² + (oz)² - r² = 0
    // a=(dx + dz); b = 2(oxdx + ozdz); c = (ox)² + (oz)² - r²
    float a = ray.getDirection().x*ray.getDirection().x + ray.getDirection().z*ray.getDirection().z;
    float b = 2*(ray.getOrigin().x*ray.getDirection().x + ray.getOrigin().z*ray.getDirection().z);
    float c = ray.getOrigin().x*ray.getOrigin().x + ray.getOrigin().z*ray.getOrigin().z - m_radius*m_radius;

    float discr = b*b - 4*a*c;
    if (discr < 0)
    {
        return Intersection(false);
    }

    float x1 = (-b+sqrt(discr))/(2*a);
    float x2 = (-b-sqrt(discr))/(2*a);

    float t;
    //choose the smallest and >=0 t
    if (x1 > x2)
    {
        t=x2;
    }

    if (t < 0)
    {
        t=x1;
    }


    // if both solution are <0 => NO INTERSECTION!
    if (t<0)
    {
        return Intersection(false);
    }

    // normal calculation
    // f(x,y) = x² + z² - r² = 0
    // T = (dx/dt, y, dz/dt)
    // 0 = df/dt = (df/dx, y, df/dz) · T
    // N = (2x, 0, 2z)
    vec3 point = ray.getOrigin() + ray.getDirection()*t;
    vec3 normal = vec3(2*point.x, 0.0f, 2*point.z);


    // If the y-component from point computed is smaller than 0 or bigger than height => NO INTERSECTION!
    if (point.y < 0 || point.y > m_height)
    {
        return Intersection(false);
    }

    //If ray direction is not pararel to Y Plane
    if (ray.getDirection().y != 0.0f) //Paralel
    {
        //Compute t's for point intersection in the Y Plane
        float t3 = (0-ray.getOrigin().y)/ray.getDirection().y;
        float t4 = (m_height-ray.getOrigin().y)/ray.getDirection().y;
        float t2;

        //choose the smallest and >=0 t
        t2 = std::min(t3,t4);
        if (t2 < 0)
        {
            t2 = std::max(t3,t4);
        }
        if (t2 >= 0)
        {
            // If there is a t >= 0 compute de point and check if the point is inside the cap
            vec3 point1 = ray.getOrigin() + ray.getDirection()*t2;
            std::cout << "point " << point1.y << " hipo "  << point1.x*point1.x + point1.z*point1.z << " radio " << m_radius*m_radius << std::endl;
            if (point1.x*point1.x + point1.z*point1.z <= m_radius*m_radius+0.9f)
            {
                // Intersection point is inside cap but, Which t is the smallest? t from cap or t from body cylinder?
                // I choose the smallest t and check if the t is from cap and compute normal and return intersection.
                t = std::min(t,t2);
                if (t == t3)
                {
                    normal = vec3(0.0f,-1.0f,0.0f);
                    return Intersection(true, point1, normal);
                }
                else if (t == t4)
                {
                    normal = vec3(0.0f,1.0f,0.0f);
                    return Intersection(true, point1, normal);
                }
            }
        }
    }

    // Intersection in the body cylinder, compute the point and return the intersection
    point = ray.getOrigin() + ray.getDirection()*t;

    return Intersection(true, point, normal);
}*/
#include "rtv.h"

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

int cylinder_inter_v1(t_ray ray, t_figure cylinder, double *s4)
{

    return (1);
}

void test_cylinder_inter_v1(t_rtv *rtv)
{

    //creating objects

    t_ray ray;
    double ray_start_z = -1000;
    int ray_end_z = 200;
    ray.pos = newVect(0, 0, ray_start_z);
    ray.dir = newVect(0, 0, ray_end_z);

    t_figure cylinder1;
    cylinder1.type = CYLINDER;
    cylinder1.radius = 100;
    cylinder1.color = GREEN;
    cylinder1.pos = newVect(0, 0, 500);
    cylinder1.dir = newVect(0, 0, 700);
    //test intersection
    double *s1;
    int res = cylinder_inter_v1(ray, cylinder1, s1);
    printf("result: %d , solution:  %.2f  \n", res, *s1);
}

int plane_inter_v1(t_ray ray, t_figure figure, t_vector *s1)
{
    t_vector plane_normal = vectSub(figure.dir, figure.pos);
    t_vector plane_point = figure.pos;
    t_vector ray_normal = vectSub(ray.dir, ray.pos);
    t_vector intersection_p;
    if (vectDot(ray_normal, plane_normal) >= 0)
        return (0);
    t_vector diff = vectSub(ray.pos, plane_point);
    t_vector av1 = vectAdd(diff, plane_point);
    double dot1 = vectDot(ray_normal, plane_normal);
    double dot2 = vectDot(diff, plane_normal);
    t_vector sv1 = vectScale(ray_normal, -dot2 / dot1);

    intersection_p = vectAdd(av1, sv1);
    *s1 = intersection_p;
    return 1;
}

int sphere_inter_v1(t_ray ray, t_figure figure, t_vector *s2)
{
    double a, b, c, t2, d;

    a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
    b = -2 * ((ray.dir.x - ray.pos.x) * (figure.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (figure.pos.y - ray.pos.y) + (figure.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
   // c = pow((figure.pos.x - ray.pos.x), 2) + pow((figure.pos.y - ray.pos.y), 2) + pow((figure.pos.z - ray.pos.z), 2) - pow(figure.radius, 2);
    

    // a = vectDot(ray.dir, ray.dir);
    // b = vectDot(vectScale(ray.pos, 2), vectSub(ray.pos, figure.pos));
     c = vectDot(vectSub(ray.pos, figure.pos), vectSub(ray.pos, figure.pos)) - pow(figure.radius, 2);
    d = pow(b, 2) - (4 * a * c);
    t2 = solution(a, b, c);

    s2->x = ray.pos.x + ((ray.dir.x - ray.pos.x) * t2);
    s2->y = ray.pos.y + ((ray.dir.y - ray.pos.y) * t2);
    s2->z = ray.pos.z + ((ray.dir.z - ray.pos.z) * t2);

    if (t2 == FAR)
        return 0;
    return (1);
}

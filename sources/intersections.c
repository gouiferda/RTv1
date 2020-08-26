#include "rtv.h"


int cylinder_inter_v1(t_ray ray, t_figure cylinder, double *s1)
{

    return (1);
}

void test_cylinder_inter_v1(t_rtv *rtv)
{

    //creating objects

    t_figure cylinder1;
    cylinder1.type = CYLINDER;
    cylinder1.radius = 100;
    cylinder1.color = GREEN;
    cylinder1.pos = newVect(rtv->screen_w / 2, rtv->screen_h / 2, 500);
    cylinder1.dir = newVect(rtv->screen_w / 2, rtv->screen_h / 2, 700);
    t_ray ray;
    double ray_start_z = -1000;
    int ray_end_z = 400;
    ray.pos = newVect(0, 0, ray_start_z);
    ray.dir = newVect(0, 0, ray_end_z);

    //test intersection
    double s1 = 0, s2 = 0;
    int res = cylinder_inter_v1(ray, cylinder1, &s1);
    printf("result: %d , solution:  s1: %.2f , s2: %.2f  \n", res, s1, s2);
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

int sphere_inter_v1(t_ray ray, t_figure figure, t_vector *s1, t_vector *s2)
{
    double a, b, c, t1, t2;
    int res = 0;

    a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
    b = -2 * ((ray.dir.x - ray.pos.x) * (figure.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (figure.pos.y - ray.pos.y) + (figure.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
    c = pow((figure.pos.x - ray.pos.x), 2) + pow((figure.pos.y - ray.pos.y), 2) + pow((figure.pos.z - ray.pos.z), 2) - pow(figure.radius, 2);

    t1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    t2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

    s1->x = ray.pos.x + ((ray.dir.x - ray.pos.x) * t1);
    s1->y = ray.pos.y + ((ray.dir.y - ray.pos.y) * t1);
    s1->z = ray.pos.z + ((ray.dir.z - ray.pos.z) * t1);

    s2->x = ray.pos.x + ((ray.dir.x - ray.pos.x) * t2);
    s2->y = ray.pos.y + ((ray.dir.y - ray.pos.y) * t2);
    s2->z = ray.pos.z + ((ray.dir.z - ray.pos.z) * t2);

    if ((pow(b, 2) - (4 * a * c)) >= 0)
        res = 1;

    return (res);
}

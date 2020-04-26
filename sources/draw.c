/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void draw_bg(t_rtv *rtv)
{
    int final_color = BLACK;
    int x = 0;
    int y = 0;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
}

int obj_inter(t_ray ray, t_object obj, t_point *s1, t_point *s2)
{
    double a, b, c, t1, t2;
    int res = 0;

    if (obj.type == SPHERE)
    {
        a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
        b = -2 * ((ray.dir.x - ray.pos.x) * (obj.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (obj.pos.y - ray.pos.y) + (obj.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
        c = pow((obj.pos.x - ray.pos.x), 2) + pow((obj.pos.y - ray.pos.y), 2) + pow((obj.pos.z - ray.pos.z), 2) - pow(obj.radius, 2);

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
    }
    return (res);
}

void getClosestTest()
{
    int end_distance = 1000;
    int obj_count = 8;
    int objects_z[] = {10, 40, 80, 5, 67, 9, 50, 90, 7};
    int furthest_dist = end_distance;
    int i = 0;
    int clostedObjId = -1;
    while (i <= obj_count)
    {
        if (objects_z[i] < furthest_dist)
        {
            furthest_dist = objects_z[i];
            clostedObjId = i;
        }
        i++;
    }

    printf("closest_dist = %i , clostedObjId=%i", furthest_dist, clostedObjId);
}

void test(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_start_z = -1000 + (rtv->zoom * 10);
    int ray_len = 1000;
    t_point ray_pos = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, ray_len);
    t_ray ray = {ray_pos, ray_dir};

    //object in center screen
    int objects_c = 6;
    t_object objects[objects_c];
    int colors[]={BLUE,RED,GREEN2,ORANGE2,YELLOW,BLUE3,GREEN,BLUE3};

    int j = 0;
    while (j < objects_c)
    {
        objects[j].type = SPHERE;
        objects[j].radius = 50;
        objects[j].pos = get_point((rtv->screen_w / (3 - (j * 0.3))), (rtv->screen_h / 2), 0);
        objects[j].rotation = get_point(0, 0, 0);
        objects[j].color = colors[j];
        j++;
    }

    int i = 0;
    //int closestObjDistance = ray_start_z;
    int furthestDistance = ray_len;
    int closestObjId = -1;
    t_point s1, s2;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            // final_color = BLACK;

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;
            //find intersections with the ray
            //     for each object in the scene
            i = 0;
            furthestDistance = ray_len;
            while (i < objects_c)
            {
                //     determine closest ray object/intersection;
                if (obj_inter(ray, objects[i], &s1, &s2) == 1)
                {
                    if (s2.z < furthestDistance)
                    {
                        furthestDistance = s2.z;
                        closestObjId = i;
                    }
                    //closestObjId = i;
                }
                i++;
            }
            if (closestObjId != -1)
            {
                if (obj_inter(ray, objects[closestObjId], &s1, &s2) == 1)
                {
                    final_color = objects[closestObjId].color;
                    add_px(rtv, x, y, final_color);
                    closestObjId = -1;
                }
            }
            y++;
        }
        x++;
    }
}

void intersection_test(t_rtv *rtv)
{

    t_point obj_pos1 = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), 0);
    t_object obj = {.type = SPHERE, .radius = 100, .pos = obj_pos1, .rotation = get_point(0, 0, 0), .color = BLUE};

    t_point s1, s2;
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_pos = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_len);
    t_ray ray = {ray_pos, ray_dir};

    if (obj_inter(ray, obj, &s1, &s2) == 1)
    {
        printf("Interestected in : s1(%d,%d,%d) s2(%d,%d,%d) \n", s1.x, s1.y, s1.z, s2.x, s2.y, s2.z);
    }
}

void draw(t_rtv *rtv)
{
    //intersection_test(rtv);

    init_draw(rtv);

    draw_bg(rtv);
    test(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

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

void draw_test(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    t_light light = {get_point((rtv->screen_w / 2), 100, 0), 100};
    int inShadow = 0;
    t_ray shadowRay;

    //ray starts from center screen
    int ray_start_z = -1000 + (rtv->zoom * 10);
    int ray_len = 1000;
    t_point ray_pos = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, ray_len);
    t_ray ray = {ray_pos, ray_dir};

    //object in center screen
    int objects_c = 1;
    t_object objects[objects_c];
    int colors[] = {BLUE, RED, GREEN2, ORANGE2, YELLOW, BLUE3, GREEN, BLUE3};
    int j = 0;
    while (j < objects_c)
    {
        objects[j].type = SPHERE;
        objects[j].radius = 50;
        objects[j].pos = get_point((rtv->screen_w / (2 - (j * 0.3))), (rtv->screen_h / 2), 0);
        objects[j].rotation = get_point(0, 0, 0);
        objects[j].color = colors[j];
        j++;
    }

    int i = 0;
    int minDistance = ray_len;
    int closestObjId = -1;
    t_point s1, s2;
    t_point sh1, sh2;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            ray.dir.x = x;
            ray.dir.y = y;
            //     for each object in the scene determine closest ray object/intersection;
            i = 0;
            minDistance = ray_len;
            while (i < objects_c)
            {
                //find intersections with the ray
                if (obj_inter(ray, objects[i], &s1, &s2) == 1)
                {
                    if (s2.z < minDistance)
                    {
                        minDistance = s2.z;
                        closestObjId = i;
                    }
                }
                i++;
            }
            if (closestObjId != -1)
            {

                if (obj_inter(ray, objects[closestObjId], &s1, &s2) == 1)
                {
                    i = 0;
                    while (i < objects_c)
                    {
                        shadowRay.pos = get_point(s2.x, s2.y, s2.z);
                        shadowRay.dir = get_point(light.pos.x, light.pos.y, light.pos.z);
                        //find intersections with the ray
                        if (obj_inter(shadowRay, objects[i], &sh1, &sh2) == 1 && closestObjId!=i)
                        {
                            inShadow = 1;
                            break;
                        }
                        i++;
                    }
                    if (inShadow == 0)
                    {
                        final_color = objects[closestObjId].color;
                    }
                    else
                    {
                        final_color = BLACK;
                        inShadow = 0;
                    }
                    add_px(rtv, x, y, final_color);
                    closestObjId = -1;
                }
            }
            y++;
        }
        x++;
    }
}

void draw(t_rtv *rtv)
{
    //intersection_test(rtv);

    init_draw(rtv);

    draw_bg(rtv);
    draw_test(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

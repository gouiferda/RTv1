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

void test(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_pos = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, 0);
    t_ray ray = {ray_pos, ray_dir};

    //object in center screen
    t_point obj_pos1 = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), 0);
    t_point obj_pos2 = get_point((rtv->screen_w / 2), (rtv->screen_h / 3), 200);

    t_object objects[] = {
        {.type = SPHERE, .radius = 100, .pos = obj_pos1, .rotation = get_point(0, 0, 0), .color = BLUE},
        {.type = SPHERE, .radius = 100, .pos = obj_pos2, .rotation = get_point(0, 0, 0), .color = YELLOW},
    };
    int i = 0;
    int closestObjDistance = ray_start_z;
    int closestObjId = -1;
    t_object closestObject;
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
            while (i < 2)
            {
                //     determine closest ray object/intersection;
                t_object currentObject = objects[i];
                if (obj_inter(ray, currentObject, &s1, &s2) == 1)
                {
                    if (s1.z > closestObjDistance)
                    {
                        closestObjDistance = s1.z;
                        closestObjId = i;
                    }
                }
                i++;
            }
            if (closestObjId > -1)
            {
                if (obj_inter(ray, objects[closestObjId], &s1, &s2) == 1)
                {
                    final_color = objects[closestObjId].color;
                    add_px(rtv, x, y, final_color);
                }
            }

            y++;
        }
        x++;
    }
}

void draw(t_rtv *rtv)
{
    init_draw(rtv);

    draw_bg(rtv);
    test(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

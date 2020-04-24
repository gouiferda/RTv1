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

int obj_inter(t_ray ray, t_object obj)
{
    double a, b, c;
    int res = 0;

    if (obj.type == SPHERE)
    {
        a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
        b = -2 * ((ray.dir.x - ray.pos.x) * (obj.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (obj.pos.y - ray.pos.y) + (obj.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
        c = pow((obj.pos.x - ray.pos.x), 2) + pow((obj.pos.y - ray.pos.y), 2) + pow((obj.pos.z - ray.pos.z), 2) - pow(obj.radius, 2);
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
    t_point ray_start = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, 0);
    t_ray ray = {ray_start, ray_dir};
    t_object obj1 = {SPHERE, 100, get_point((rtv->screen_w / 2), (rtv->screen_h / 2), 0), get_point(0, 0, 0), BLUE};

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            // final_color = WHITE;

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;
            //find intersections with the ray
            if (obj_inter(ray, obj1) == 1)
            {
                final_color = obj1.color;
                add_px(rtv, x, y, final_color);
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

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

void draw_colorful_test_screen(t_rtv *rtv)
{
    int final_color = BLUE;
    int x = 0;
    int y = 0;
    int r, g, b;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            r = y * 0.35;
            g = x * 0.25;
            b = 10;
            final_color = get_color(r, g, b);
            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
}

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

void draw_axis(t_rtv *rtv)
{
    int final_color = WHITE;
    int start_x_axis = -500;
    int end_x_axis = 500;
    int start_y_axis = -500;
    int end_y_axis = 500;
    int start_z_axis = -500;
    int end_z_axis = 500;
    while (start_x_axis < end_x_axis)
    {
        add_p_point(rtv, get_point(start_x_axis, 0, 0), final_color);
        start_x_axis++;
    }
    while (start_y_axis < end_y_axis)
    {
        add_p_point(rtv, get_point(0, start_y_axis, 0), final_color);
        start_y_axis++;
    }
    while (start_z_axis < end_z_axis)
    {
        add_p_point(rtv, get_point(0, 0, start_z_axis), final_color);
        start_z_axis++;
    }
}

void test_d1(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_start = get_point(-(rtv->screen_w / 2), -(rtv->screen_h / 2), ray_start_z);
    t_ray ray = {ray_start, get_point(0, 0, ray_len)};
    t_object obj1 = {SPHERE, 40, get_point(0, 0, 0), get_point(0, 0, 0), BLUE};

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

void test_d2(t_rtv *rtv)
{

    int final_color = BLACK;
    int x = -500;
    int y = -500;
    int x_end = 500;
    int y_end = 500;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_start = proj_p(rtv,get_point(0, 0, ray_start_z));
    t_point ray_dir = proj_p(rtv,get_point(-500, -500, ray_len));
    t_ray ray = {ray_start, ray_dir};
    t_object obj1 = {SPHERE, rtv->zoom * 50, proj_p(rtv,get_point(0, 0, 0)), get_point(0, 0, 0), RED};

    while (x < x_end)
    {
        y = -500;
        while (y < y_end)
        {
            // final_color = WHITE;

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;
            //find intersections with the ray
            if (obj_inter(ray, obj1) == 1)
            {
                final_color = obj1.color;
                add_px(rtv, x, y, obj1.color);
            }
            y++;
        }
        x++;
    }
}

void test_d3(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_start = get_point(-(rtv->screen_w / 2), -(rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, 0);
    t_ray ray = {ray_start, ray_dir};
    t_object obj1 = {SPHERE, 40, get_point(0, 0, 0), get_point(0, 0, 0), BLUE};

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

    //draw_colorful_test_screen(rtv);
    draw_bg(rtv);
    draw_axis(rtv);
    //test_d1(rtv);
    //test_d2(rtv);
    test_d3(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

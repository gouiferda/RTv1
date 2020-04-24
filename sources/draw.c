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

void test_screen(t_rtv *rtv)
{
    init_draw(rtv);
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
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

void test_d1(t_rtv *rtv)
{
    init_draw(rtv);
    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_len = 300;
    t_point ray_start = get_point(rtv->screen_w / 2, rtv->screen_h / 2, -ray_len);
    t_ray ray = {ray_start, get_point(0, 0, ray_len)};

    t_object obj1 = {SPHERE, 100, get_point(0, 0, 0), get_point(0, 0, 0), BLUE};

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;

            //find intersections with the ray
            

            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

void draw(t_rtv *rtv)
{
    // test_screen(rtv);
    test_d1(rtv);
}

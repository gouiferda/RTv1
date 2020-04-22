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

void draw_axis(t_rtv *rtv)
{
    t_point p0;
    t_point p1;
    t_point p2;
    t_point p3;
    t_point p4;
    t_point p5;

    p0 = get_point(-rtv->screen_w / 2,0,0);
    p1 = get_point(rtv->screen_w / 2,0,0);
    draw_p_line(rtv, p0, p1, WHITE);
    p2 = get_point(0,rtv->screen_h / 2,0);
    p3 = get_point(0,-rtv->screen_h / 2,0);
    draw_p_line(rtv, p2, p3, WHITE);
    p4 = get_point(0,0,rtv->screen_h / 2);
    p5 = get_point(0,0,-rtv->screen_h / 2);
    draw_p_line(rtv, p4, p5, WHITE);
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
    mlx_string_put(rtv->mlx, rtv->win, projected_p(rtv, p0).x, projected_p(rtv, p0).y,
                   WHITE, "X axis");
    mlx_string_put(rtv->mlx, rtv->win, projected_p(rtv, p2).x, projected_p(rtv, p2).y,
                   WHITE, "Y axis");
    mlx_string_put(rtv->mlx, rtv->win, projected_p(rtv, p4).x, projected_p(rtv, p4).y,
                   WHITE, "Z axis");
}

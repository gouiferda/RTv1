/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:32:02 by sgouifer          #+#    #+#             */
/*   Updated: 2019/03/09 22:32:05 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void draw_pyramid(t_rtv *rtv, t_pyramid pyramid)
{
    t_point top;

    top.x = (pyramid.base.p1.x + pyramid.base.p2.x + pyramid.base.p3.x + pyramid.base.p4.x) / 4;
    top.y = pyramid.height;
    top.z = (pyramid.base.p1.z + pyramid.base.p2.z + pyramid.base.p3.z + pyramid.base.p4.z ) / 4;

    //base
    draw_p_line(rtv, pyramid.base.p1, pyramid.base.p2, pyramid.color);
    draw_p_line(rtv, pyramid.base.p2, pyramid.base.p3, pyramid.color);
    draw_p_line(rtv, pyramid.base.p3, pyramid.base.p4, pyramid.color);
    draw_p_line(rtv, pyramid.base.p4, pyramid.base.p1, pyramid.color);
    //up
    draw_p_line(rtv, top, pyramid.base.p4, pyramid.color);
    draw_p_line(rtv, top, pyramid.base.p3, pyramid.color);
    draw_p_line(rtv, top, pyramid.base.p2, pyramid.color);
    draw_p_line(rtv, top, pyramid.base.p1, pyramid.color);
    
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

void draw_pyramid2(t_rtv *rtv, t_pyramid pyramid)
{
    //base
    draw_p_line(rtv, pyramid.base.p1, pyramid.base.p2, pyramid.color);
    draw_p_line(rtv, pyramid.base.p2, pyramid.base.p3, pyramid.color);
    draw_p_line(rtv, pyramid.base.p3, pyramid.base.p4, pyramid.color);
    draw_p_line(rtv, pyramid.base.p4, pyramid.base.p1, pyramid.color);
    //up
    draw_p_line(rtv, pyramid.top, pyramid.base.p4, pyramid.color);
    draw_p_line(rtv, pyramid.top, pyramid.base.p3, pyramid.color);
    draw_p_line(rtv, pyramid.top, pyramid.base.p2, pyramid.color);
    draw_p_line(rtv, pyramid.top, pyramid.base.p1, pyramid.color);
    
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_pyramid get_pyramid(int color, t_square base, int height)
{
    t_pyramid pyramid;

    pyramid.color = color;
    pyramid.base = base;
    pyramid.height = height;
    return (pyramid);
}

t_pyramid get_pyramid2(int color, t_square base, t_point top)
{
    t_pyramid pyramid;

    pyramid.color = color;
    pyramid.base = base;
    pyramid.top = top;
    pyramid.height = 0;
    return (pyramid);
}
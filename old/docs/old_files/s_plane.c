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

void draw_plane(t_rtv *rtv, t_plane plane)
{
    //border
    draw_p_line(rtv, plane.start1, plane.start2, plane.color);
    draw_p_line(rtv, plane.finish1, plane.finish2, plane.color);
    draw_p_line(rtv, plane.start1, plane.finish1, plane.color);
    draw_p_line(rtv, plane.start2, plane.finish2, plane.color);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_plane get_plane(int color, int width, int height)
{
    t_plane plane;
    plane.color = color;
    plane.width = width;
    plane.height = height;
    plane.start1.x = -plane.width / 2;
    plane.start1.y = 0;
    plane.start1.z = plane.height / 2;
    plane.start2.x = -plane.width / 2;
    plane.start2.y = 0;
    plane.start2.z = -plane.height / 2;
    plane.finish1.x = plane.width / 2;
    plane.finish1.y = 0;
    plane.finish1.z = plane.height / 2;
    plane.finish2.x = plane.width / 2;
    plane.finish2.y = 0;
    plane.finish2.z = -plane.height / 2;
    return (plane);
}
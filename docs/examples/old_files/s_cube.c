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

void draw_cube(t_rtv *rtv, t_cube cube)
{
    //base 1
    draw_p_line(rtv, cube.base.p1, cube.base.p2, cube.color);
    draw_p_line(rtv, cube.base.p2, cube.base.p3, cube.color);
    draw_p_line(rtv, cube.base.p3, cube.base.p4, cube.color);
    draw_p_line(rtv, cube.base.p4, cube.base.p1, cube.color);

    //horizontal links
    draw_p_line(rtv, cube.base.p1, get_point(cube.base.p1.x, cube.base.p1.y + cube.height, cube.base.p1.z), cube.color);
    draw_p_line(rtv, cube.base.p2, get_point(cube.base.p2.x, cube.base.p2.y + cube.height, cube.base.p2.z), cube.color);
    draw_p_line(rtv, cube.base.p3, get_point(cube.base.p3.x, cube.base.p3.y + cube.height, cube.base.p3.z), cube.color);
    draw_p_line(rtv, cube.base.p4, get_point(cube.base.p4.x, cube.base.p4.y + cube.height, cube.base.p4.z), cube.color);

    cube.base.p1.y += cube.height;
    cube.base.p2.y += cube.height;
    cube.base.p3.y += cube.height;
    cube.base.p4.y += cube.height;

    //base 2
    draw_p_line(rtv, cube.base.p1, cube.base.p2, cube.color);
    draw_p_line(rtv, cube.base.p2, cube.base.p3, cube.color);
    draw_p_line(rtv, cube.base.p3, cube.base.p4, cube.color);
    draw_p_line(rtv, cube.base.p4, cube.base.p1, cube.color);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_cube get_cube(int color, t_square base, int height)
{
    t_cube cube;

    cube.color = GREEN;
    cube.base = base;
    cube.height = height;
    return (cube);
}
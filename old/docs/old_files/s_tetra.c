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

void draw_tetra(t_rtv *rtv, t_tetra tetra)
{
    t_point top;

    top.x = (tetra.base.p1.x + tetra.base.p2.x + tetra.base.p3.x) / 3;
    top.y = tetra.height;
    top.z = (tetra.base.p1.z + tetra.base.p2.z + tetra.base.p3.z) / 3;
    //base
    draw_p_line(rtv, tetra.base.p1, tetra.base.p2, tetra.color);
    draw_p_line(rtv, tetra.base.p2, tetra.base.p3, tetra.color);
    draw_p_line(rtv, tetra.base.p3, tetra.base.p1, tetra.color);
    //up
    draw_p_line(rtv, top, tetra.base.p3, tetra.color);
    draw_p_line(rtv, top, tetra.base.p2, tetra.color);
    draw_p_line(rtv, top, tetra.base.p1, tetra.color);
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_tetra get_tetra(int color, t_triangle base, int height)
{
    t_tetra tetra;

    tetra.color = color;
    tetra.base = base;
    tetra.height = height;
    return (tetra);
}
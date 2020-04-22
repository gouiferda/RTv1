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

void    add_new_px(t_rtv *rtv, int x, int y, int z, int color)
{
    add_p_point2(rtv, x,y,z, color);
}

void dc(t_rtv *rtv, int xc, int yc, int x, int y, int z, int color)
{
     // add_new_px(rtv, xc + x, yc + y, z, color);
    // add_new_px(rtv, xc - x, yc + y, z, color);
    // add_new_px(rtv, xc + x, yc - y, z, color);
    // add_new_px(rtv, xc - x, yc - y, z, color);
    // add_new_px(rtv, xc + y, yc + x, z, color);
    // add_new_px(rtv, xc - y, yc + x, z, color);
    // add_new_px(rtv, xc + y, yc - x, z, color);
    // add_new_px(rtv, xc - y, yc - x, z, color);
    add_px(rtv, xc + x, yc + y, color);
    add_px(rtv, xc - x, yc + y, color);
    add_px(rtv, xc + x, yc - y, color);
    add_px(rtv, xc - x, yc - y, color);
    add_px(rtv, xc + y, yc + x, color);
    add_px(rtv, xc - y, yc + x, color);
    add_px(rtv, xc + y, yc - x, color);
    add_px(rtv, xc - y, yc - x, color);
}

void draw_circle(t_rtv *rtv, int xc, int yc, int z, int r, int color)
{
    // if (rtv->zoom > 1)
    //     r = (r * (rtv->zoom / 2));
    
    int x = 0, y = r;
    int d = 3 - 2 * r;
    dc(rtv, xc, yc, x, y, z, color);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        dc(rtv, xc, yc, x, y, z, color);
    }
}
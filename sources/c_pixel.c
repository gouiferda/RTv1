/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void add_px(t_rtv *rtv, int x, int y, int color)
{
    int i;

    if (x > 0 && y > 0 && x < (rtv->screen_w) && y < rtv->screen_h)
    {
        i = (x * rtv->bpp / 8) + (y * rtv->size_line);
        rtv->img_data[i] = color;
        rtv->img_data[++i] = color >> 8;
        rtv->img_data[++i] = color >> 16;
    }
}

void add_px2(t_rtv *rtv, int x, int y, int color)
{
    add_px(rtv, x + (rtv->screen_w / 2), (-y + (rtv->screen_h / 2)), color);
}

void add_px3(t_rtv *rtv, int x, int y, t_color c)
{
    int i;
    x = x+ (rtv->screen_w / 2);
    y = (-y + (rtv->screen_h / 2));

    if (x > 0 && y > 0 && x < (rtv->screen_w) && y < rtv->screen_h)
    {
        i = (x * rtv->bpp / 8) + (y * rtv->size_line);
        rtv->img_data[i] = (unsigned char)min(c.r*255.0f, 255.0f);
        rtv->img_data[++i] = (unsigned char)min(c.g*255.0f, 255.0f);
        rtv->img_data[++i] = (unsigned char)min(c.b*255.0f, 255.0f);
    }
}

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

    if (x > 0 && y > 0 && x < (rtv->screen_w + RIGHT_MENU_W) && y < rtv->screen_h)
    {
        i = (x * rtv->bpp / 8) + (y * rtv->size_line);
        rtv->img_data[i] = color;
        rtv->img_data[++i] = color >> 8;
        rtv->img_data[++i] = color >> 16;
    }
}


void add_px1(t_rtv *rtv, int x, int y, t_color color)
{
    int p;
    p = (x * rtv->bpp / 8) + (y * rtv->size_line);
    rtv->img_data[p] = (unsigned char)min(color.red * 255.0f, 255.0f);
    rtv->img_data[p + 1] = (unsigned char)min(color.green * 255.0f, 255.0f);
    rtv->img_data[p + 2] = (unsigned char)min(color.blue * 255.0f, 255.0f);
}

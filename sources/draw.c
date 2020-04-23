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

void draw(t_rtv *rtv)
{
    init_draw(rtv);
    int final_color = BLUE;
    int x = 0;
    int y = 0;
    int r,g,b;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            r = y * 0.35;
            g = x * 0.25;
            b = 10;
            final_color = get_color(r,g,b);
            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

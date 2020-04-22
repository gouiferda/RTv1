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


void draw_test3(t_rtv *rtv)
{

    init_draw(rtv);

    int final_color = BLACK;


    int x = 0;
    int y = 0;

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            final_color = BLACK;


            add_px(rtv, x, y, final_color);

            y++;
        }
        x++;
    }

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
    draw_axis(rtv);
}

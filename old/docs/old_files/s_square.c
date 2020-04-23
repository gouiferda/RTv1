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

void draw_square(t_rtv *rtv, t_square square)
{
    draw_p_line(rtv, square.p1, square.p2, square.color);
    draw_p_line(rtv, square.p2, square.p3, square.color);
    draw_p_line(rtv, square.p3, square.p4, square.color);
    draw_p_line(rtv, square.p4, square.p1, square.color);
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_square get_square(int color, t_point p1, t_point p2, t_point p3, t_point p4)
{
    t_square square;

    square.color = GREEN;
    square.p1 = p1;
    square.p2 = p2;
    square.p3 = p3;
    square.p4 = p4;
    
    return (square);
}
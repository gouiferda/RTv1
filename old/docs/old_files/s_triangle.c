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

void draw_triangle(t_rtv *rtv, t_triangle triangle)
{
    draw_p_line(rtv, triangle.p1, triangle.p2, triangle.color);
    draw_p_line(rtv, triangle.p2, triangle.p3, triangle.color);
    draw_p_line(rtv, triangle.p3, triangle.p1, triangle.color);
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

t_triangle get_triangle(int color, t_point p1, t_point p2, t_point p3)
{
    t_triangle triangle;

    triangle.color = GREEN;
    triangle.p1 = p1;
    triangle.p2 = p2;
    triangle.p3 = p3;
    return (triangle);
}
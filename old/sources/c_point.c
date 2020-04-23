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

t_point get_point(int x, int y, int z)
{
    t_point point;
    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

void    add_point(t_rtv *rtv,t_point p, int c)
{
    add_px(rtv, p.x, p.y, c);
}

void    add_p_point(t_rtv *rtv, t_point p, int c)
{
    p = projected_p(rtv,p);
    add_px(rtv, p.x, p.y, c);
}

void    add_p_point2(t_rtv *rtv, int x, int y, int z, int c)
{
    t_point p;
    p = get_point(x,y,z);
    p.color = c;
    add_p_point(rtv, p, p.color);
}
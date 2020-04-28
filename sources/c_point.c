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

void add_point(t_rtv *rtv, t_point p)
{
	add_px(rtv, p.x, p.y, p.z);
}

t_point proj_p(t_rtv *rtv, t_point p)
{
	p.y = p.y * -1;
	p.x *= rtv->zoom;
	p.y *= rtv->zoom;
	p.z *= rtv->zoom;
	p.z += rtv->offset_z;
	rx(&p.y, &p.z, rtv->alpha);
	ry(&p.x, &p.z, rtv->beta);
	rz(&p.x, &p.y, rtv->gamma);
	p.x += rtv->offset_x + (rtv->screen_w / 2);
	p.y += rtv->offset_y + (rtv->screen_h / 2);
	return (p);
}

void add_p_point(t_rtv *rtv, t_point p, int color)
{
	p = proj_p(rtv, p);
	add_px(rtv, p.x, p.y, color);
}

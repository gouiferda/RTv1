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

/* Subtract two vectors and return the resulting t_point */
t_point vectorSub(t_point *v1, t_point *v2)
{
	t_point result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(t_point *v1, t_point *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate t_point x Scalar and return resulting t_point*/
t_point vectorScale(float c, t_point *v)
{
	t_point result = {v->x * c, v->y * c, v->z * c};
	return result;
}

/* Add two vectors and return the resulting t_point */
t_point vectorAdd(t_point *v1, t_point *v2)
{
	t_point result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return result;
}
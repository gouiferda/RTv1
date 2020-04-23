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

void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;
	
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ISO_ANGLE2);
	*y = (previous_x + previous_y) * sin(ISO_ANGLE2) - z;
}
//under dev
void		perspective(t_rtv *rtv,int *x, int *y, int z)
{
	int previous_x;
	int previous_y;
	
	previous_x = *x;
	previous_y = *y;
	// *x = (rtv->zoom * previous_x) / z;
	// *y = (rtv->zoom * previous_y) / z;
}

t_point		projected_p(t_rtv *rtv, t_point p)
{
	p.y = p.y * -1;


	
	//perspective(rtv, &p.x, &p.y, p.z);

	p.x *= rtv->zoom;
	p.y *=  rtv->zoom;
	p.z *=  rtv->zoom;
	p.z += rtv->offset_z;
    rx(&p.y, &p.z, rtv->alpha);
	ry(&p.x, &p.z, rtv->beta);
	rz(&p.x, &p.y, rtv->gamma);
	//iso(&p.x, &p.y, p.z);
	p.x += rtv->offset_x + (rtv->screen_w / 2);
	p.y += rtv->offset_y + (rtv->screen_h / 2);
	return (p);
}

t_point		projected_cords(t_rtv *rtv, int *x, int *y, int *z)
{
	*y = *y * -1;

	*x *= rtv->zoom;
	*y *=  rtv->zoom;
	*z *=  rtv->zoom;
	*z += rtv->offset_z;
    rx(y, z, rtv->alpha);
	ry(x, z, rtv->beta);
	rz(x, y, rtv->gamma);
	//iso(x, y, *z);
	*x += rtv->offset_x + (rtv->screen_w / 2);
	*y += rtv->offset_y + (rtv->screen_h / 2);
}

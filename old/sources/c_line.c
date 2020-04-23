/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	draw_line(t_rtv *f, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	s[0] = (p1.x < p2.x ? 1 : -1);
	s[1] = (p1.y < p2.y ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		add_px(f, p1.x, p1.y, c);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			p1.x += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			p1.y += s[1];
		}
	}
}

void		draw_p_line(t_rtv *rtv, t_point p1, t_point p2, int c)
{
	p1 = projected_p(rtv, p1);
	p2 = projected_p(rtv, p2);
	draw_line(rtv, p1, p2, c);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "keys.h"

void	error(char *msg)
{
	ft_putstr("rtv Error: ");
	ft_putendl(msg);
	exit(0);
}

void	end(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void reset(int keycode, t_rtv *rtv)
{
	set_defaults(rtv);
	draw(rtv);
}


void	rotate(int keycode, t_rtv *rtv)
{
	double val;
	val = 0.05;
	if (keycode == MAIN_PAD_1 || keycode == N_2)
		affect_double2(&rtv->alpha, val);
	else if (keycode == MAIN_PAD_2 || keycode == N_8)
		affect_double2(&rtv->alpha, -val);
	else if (keycode == MAIN_PAD_3 || keycode == N_6)
		affect_double2(&rtv->beta, val);
	else if (keycode == MAIN_PAD_4 || keycode == N_4)
		affect_double2(&rtv->beta, -val);
	else if (keycode == MAIN_PAD_5 || keycode == N_3)
		affect_double2(&rtv->gamma, val);
	else if (keycode == MAIN_PAD_6 || keycode == N_1)
		affect_double2(&rtv->gamma, -val);
    printf("rotate:	alpha: %f	beta: %f	gamma: %f\n", rtv->alpha,rtv->beta,rtv->gamma);
	draw(rtv);
}

void	position(int keycode, t_rtv *rtv)
{
	if (keycode == ARROW_RIGHT)
		affect_int2(&rtv->offset_x, MOVE_STEPS);
	else if (keycode == ARROW_LEFT)
		affect_int2(&rtv->offset_x, -MOVE_STEPS);
	else if (keycode == ARROW_DOWN)
		affect_int2(&rtv->offset_y, MOVE_STEPS);
	else if (keycode == ARROW_UP)
		affect_int2(&rtv->offset_y, -MOVE_STEPS);
    printf("position:	offset_x: %d	offset_y: %d\n", rtv->offset_x,rtv->offset_y);
	draw(rtv);
}

void	zoom(int keycode, t_rtv *rtv)
{
	if (keycode == MOUSE_SCROLL_UP || keycode == N_PLUS)
		affect_int(&rtv->zoom, ZOOM_STEPS);
	else if (keycode == MOUSE_SCROLL_DOWN || keycode == N_MINUS)
		affect_int(&rtv->zoom, -ZOOM_STEPS);
	printf("zoom: %d\n",rtv->zoom);
	draw(rtv);
}
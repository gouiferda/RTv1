/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:57:23 by arudenko          #+#    #+#             */
/*   Updated: 2018/04/02 11:38:45 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_rtv *s)
{
	int x;
	int y;
	int color;
	t_ray ray;

	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = -1;
	x = 0;
	s->b = s->win_surface->pixels;
	while (x < WIDTH )
	{
		y = 0;
		while (y < HEIGHT)
		{
			ray.dir = convert_coords(s, x - WIDTH / 2 , HEIGHT / 2 - y);
			color = ray_tracer_figures(ray.origin, ray.dir, 0.0001f, 1000000.0, s);
			s->b[x + y * WIDTH] = color;
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	t_rtv rtv;
	t_figure	s;
	init_rtv(&rtv);
	init_sphere(&rtv);
	init_light(&rtv);
	draw(&rtv);
	while (1)
	{
		if (!poll_event(&rtv))
			return (0);
		// ft_bzero(rtv.win_surface->pixels, WIDTH * HEIGHT * 4);
		SDL_UpdateWindowSurface(rtv.win);
	}

	SDL_FreeSurface(rtv.win_surface);
	return (0);
}

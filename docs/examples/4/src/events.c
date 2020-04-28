/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:04:35 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 13:05:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		poll_event(t_rtv *s)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
			e.key.keysym.sym == SDLK_ESCAPE))
			{
				ft_bzero(s->win_surface->pixels, WIDTH * HEIGHT * 4);
				SDL_FreeSurface(s->win_surface);
				return (0);
			}
		// if (e.key.keysym.sym == SDLK_d)
		// 	s->figure[6].direction.x += 0.4;
		// if (e.key.keysym.sym == SDLK_a)
		// 	s->figure[6].direction.x -= 1;
		// if (e.key.keysym.sym == SDLK_w)
		// 	s->figure[6].direction.y += 0.1;
		// if (e.key.keysym.sym == SDLK_s)
		// 	s->figure[6].direction.y -= 0.1;
		// if (e.key.keysym.sym == SDLK_q)
		// 	s->figure[6].direction.y += 0.1;
		// if (e.key.keysym.sym == SDLK_z)
		// 	s->figure[6].direction.y -= 0.1;
		// if (e.key.keysym.sym == SDLK_e)
		// 	s->figure[6].pos.x += 0.1;
		// if (e.key.keysym.sym == SDLK_c)
		// 	s->figure[6].pos.x -= 0.1;
		else if (e.type == SDL_KEYDOWN)
		{
			ft_bzero(s->win_surface->pixels, WIDTH * HEIGHT * 4);
			if (e.key.keysym.sym == SDLK_w)
				s->light[1].pos.y += 0.3;
			else if (e.key.keysym.sym == SDLK_s)
				s->light[1].pos.y -= 0.3;
			else if (e.key.keysym.sym == SDLK_d)
				s->light[1].pos.x += 0.3;
			else if (e.key.keysym.sym == SDLK_a)
				s->light[1].pos.x -= 0.3;
			else if (e.key.keysym.sym == SDLK_q)
				s->light[1].pos.z += 0.3;
			else if (e.key.keysym.sym == SDLK_z)
				s->light[1].pos.z -= 0.3;
			ft_putendl("here");
			printf("x: %f y: %f z: %f\n",s->light[1].pos.x, s->light[1].pos.y, s->light[1].pos.z);
			draw(s);
		}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inites.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:01:16 by arudenko          #+#    #+#             */
/*   Updated: 2018/07/24 13:50:07 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *s)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		sdl_err();
	s->win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	s->win_surface = SDL_GetWindowSurface(s->win);
	s->buff = s->win_surface->pixels;
	s->vp.h = 1.0;
	s->vp.w = 1.0;
	s->vp.dist = 3.0;
	s->texure_surf = SDL_LoadBMP("bricks.bmp");
	if (s->texure_surf == NULL)
		ft_putendl("LolWat");
}

void	init_sphere(t_rtv *s)
{
	s->figure = (t_figure *)malloc(sizeof(t_figure) * NUM_FIGURES);

	s->figure[0].radius = 1.0;
	s->figure[0].material = 1;
	s->figure[0].pos.x = 0.0;
	s->figure[0].pos.y = -1.0;
	s->figure[0].pos.z = 5.0;
	s->figure[0].direction.x  = 0;
	s->figure[0].direction.y  = 0;
	s->figure[0].direction.z  = 0;
	s->figure[0].color.r = 250;
	s->figure[0].color.g = 0;
	s->figure[0].color.b = 0;
	s->figure[0].spec = 100;
	s->figure[0].name = SPHERA;

	s->figure[1].radius = 0.1;
	s->figure[1].material = 1;
	s->figure[1].pos.x = 2.0;
	s->figure[1].pos.y = 0.5;
	s->figure[1].pos.z = 5.0;
	s->figure[1].direction.x  = 0;
	s->figure[1].direction.y  = 0;
	s->figure[1].direction.z  = 0;
	s->figure[1].color.r = 0;
	s->figure[1].color.g = 250;
	s->figure[1].color.b = 0;
	s->figure[1].spec = 50;
	s->figure[1].name = SPHERA;

	s->figure[2].radius = 0.0;
	s->figure[2].material = 1;
	s->figure[2].pos.x = -1.5;
	s->figure[2].pos.y = 0.0;
	s->figure[2].pos.z = 5.0;
	s->figure[2].direction.x  = 0;
	s->figure[2].direction.y  = 0;
	s->figure[2].direction.z  = 0;
	s->figure[2].color.r = 0;
	s->figure[2].color.g = 0;
	s->figure[2].color.b = 250;
	s->figure[2].spec = 10;
	s->figure[2].name = SPHERA;

	s->figure[3].radius = 0.0;
	s->figure[3].material = 1;
	s->figure[3].pos.x = 0.0;//normal
	s->figure[3].pos.y = -1.0;
	s->figure[3].pos.z = 0.0;
	s->figure[3].direction.x  = 0;//1 //point
	s->figure[3].direction.y  = 1;
	s->figure[3].direction.z  = 0.3;
	s->figure[3].color.r = 250;
	s->figure[3].color.g = 250;
	s->figure[3].color.b = 250;
	s->figure[3].spec = 10;
	s->figure[3].name = PLANE;

	s->figure[4].radius = 0.2;
	s->figure[4].material = 1;//1
	s->figure[4].pos.x = -2.0;//1
	s->figure[4].pos.y = 0.0;//0 // start
	s->figure[4].pos.z = 5.0;//0
	s->figure[4].direction.x  = 0.0;///vector
	s->figure[4].direction.y  = 1.0;//0
	s->figure[4].direction.z  = 0.0;//0
	s->figure[4].color.r = 0;
	s->figure[4].color.g = 250;
	s->figure[4].color.b = 0;
	s->figure[4].spec = 3;
	s->figure[4].name = CYLINDER;

	s->figure[5].radius = 0.0;
	s->figure[5].material = 1;
	s->figure[5].pos.x = -1.0;
	s->figure[5].pos.y = 0.0;
	s->figure[5].pos.z = 7.0;
	s->figure[5].direction.x  = 0;
	s->figure[5].direction.y  = 1;
	s->figure[5].direction.z  = -0.25;
	s->figure[5].color.r = 0;
	s->figure[5].color.g = 0;
	s->figure[5].color.b = 250;
	s->figure[5].spec = 100;
	s->figure[5].name = CONE;

	// s->figure[6].radius = 0.0;
	// s->figure[6].material = 1;
	// s->figure[6].pos.x = 0.0;
	// s->figure[6].pos.y = 1.0;
	// s->figure[6].pos.z = 1.5;
	// s->figure[6].direction.x  = 0;
	// s->figure[6].direction.y  = 1;
	// s->figure[6].direction.z  = -1;
	// s->figure[6].color.red = 150;
	// s->figure[6].color.green = 150;
	// s->figure[6].color.blue = 50;
	// s->figure[6].spec = 1000;
	// s->figure[6].name = PLANE;
	//printf("%f\n", s->spher[0].color.red);
}


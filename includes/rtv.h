/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 20:46:51 by sgouifer          #+#    #+#             */
/*   Updated: 2019/07/28 20:46:51 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
#define RTV_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //to delete
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "colors.h"
#include "defaults.h"

typedef struct s_point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct s_ray
{
	t_point pos;
	t_point dir;
} t_ray;

typedef struct s_object
{
	t_point pos;
	int color;
	int object_type;
	void *object;
} t_object;

typedef struct s_rtv
{
	void *mlx;
	void *win;
	int screen_w;
	int screen_h;
	void *img_ptr;
	char *img_data;
	int size_line;
	int bpp;
	int endian;
	int max_iter;
	int mouse_x;
	int mouse_y;
	double r;
	double g;
	double b;
	int x_start;
	int y_start;
	int x_finish;
	int y_finish;
	int zoom;
	double alpha;
	double beta;
	double gamma;
	int offset_x;
	int offset_y;
	int offset_z;
} t_rtv;

void    set_defaults(t_rtv *rtv);
void init_draw(t_rtv *rtv);
t_rtv *init_rtv(void);

void mlx(t_rtv *rtv);

void	draw_line(t_rtv *f, t_point p1, t_point p2, int c);

t_point get_point(int x, int y, int z);
void    add_point(t_rtv *rtv,t_point p);
void    add_p_point2(t_rtv *rtv, int x, int y, int z, int c);

void    add_px(t_rtv *rtv, int x, int y, int color);

void	draw(t_rtv *rtv);

void	error(char *msg);
void	end(char *msg);

int		closer_hook(void *param);
int		keys_hook(int keycode, void *param);
int		mouse_hook(int keycode, int x, int y, void *param);
int		expose(void *param);

void	reset(int keycode, t_rtv *rtv);


#endif

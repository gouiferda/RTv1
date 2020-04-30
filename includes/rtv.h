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

#define min(a,b) (((a) < (b)) ? (a) : (b))


typedef struct		s_vector
{
	double 			x;
	double 			y;
	double 			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		dir;
}					t_ray;

typedef struct s_light
{
	t_vector		pos;
	int				type;
	double			intens;
} t_light;

typedef struct	s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_color;

typedef struct s_object
{
	int type;
	int radius;
	t_vector		pos;
	t_vector		direction;
	t_color			color;
} t_object;




typedef struct{
        t_vector pos;
        float  radius;
	int material;
}sphere; 

typedef struct{
	float red, green, blue;
}colour;


typedef struct{
	colour diffuse;
	float reflection;
}material;

typedef struct{
	t_vector pos;
	colour intensity;
}light;

//end new

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

// void	draw_line(t_rtv *f, t_point p1, t_point p2, int c);

// t_point get_point(int x, int y, int z);
// void    add_point(t_rtv *rtv,t_point p);

void    add_px(t_rtv *rtv, int x, int y, int color);

void	draw(t_rtv *rtv);

void	error(char *msg);
void	end(char *msg);

int		closer_hook(void *param);
int		keys_hook(int keycode, void *param);
int		mouse_hook(int keycode, int x, int y, void *param);
int		expose(void *param);

void	reset(int keycode, t_rtv *rtv);

// t_point		proj_p(t_rtv *rtv, t_point p);

// void    add_p_point(t_rtv *rtv, t_point p, int color);


void	affect_int(int *x, int val);
void	affect_double(double *x, double val);
void	affect_double2(double *x, double val);
void	affect_int2(int *x, int val);
void	affect_double3(double *x, double *y, double val);

void	position(int keycode, t_rtv *rtv);
void	zoom(int keycode, t_rtv *rtv);
void	rotate(int keycode, t_rtv *rtv);

void	rx(int *y, int *z, double alpha);
void	ry(int *x, int *z, double beta);
void	rz(int *x, int *y, double gamma);

t_color		get_color_s(int r, int g, int b);

t_vector vectorSub(t_vector *v1, t_vector *v2);
float vectorDot(t_vector *v1, t_vector *v2);
t_vector vectorScale(float c, t_vector *v);
t_vector vectorAdd(t_vector *v1, t_vector *v2);



#endif

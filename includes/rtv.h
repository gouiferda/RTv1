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
# define RTV_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //to delete
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "colors.h"
#include "defaults.h"



typedef struct		s_vector
{
	double 			x;
	double 			y;
	double 			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		pos;
	t_vector		dir;
}					t_ray;

typedef struct	s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_color;

typedef struct s_figure
{
	int type;
	float  radius;
	t_vector		pos;
	t_vector		dir;
	int color;
	t_color c; // (3 values between 0–1, for R-G-B)
	double specular; // (value between 0–1)
	double diffuse; // (value between 0–1)
	double reflection;
} t_figure;


typedef struct s_light
{
	t_vector		pos;
	t_color			c;
} t_light;




// typedef struct{
// 	float red, green, blue;
// }colour;


// typedef struct{
// 	colour diffuse;
// 	float reflection;
// }material;



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


void    add_px(t_rtv *rtv, int x, int y, int color);
void add_px2(t_rtv *rtv, int x, int y, int color);
void add_px3(t_rtv *rtv, int x, int y, t_color c);

void	draw(t_rtv *rtv);

void	error(char *msg);
void	end(char *msg);

int		closer_hook(void *param);
int		keys_hook(int keycode, void *param);
int		mouse_hook(int keycode, int x, int y, void *param);
int		expose(void *param);

void	reset(int keycode, t_rtv *rtv);

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
int		get_color(int r, int g, int b);


void draw_bg(t_rtv *rtv);
void draw_colorful_test_screen(t_rtv *rtv);



t_vector newVect(double x, double y,double z);
t_vector		vectScale(t_vector a, double x);
t_vector		vectNorm(t_vector a);
t_vector		vectAdd(t_vector a, t_vector b);
t_vector		vectSub(t_vector a, t_vector b);
t_vector		vectCross(t_vector a, t_vector b);
double		vectDot(t_vector a, t_vector b);

t_color colorConverter(int c);

#endif

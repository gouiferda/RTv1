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
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "colors.h"
#include "defaults.h"

//to delete
typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
} t_point;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	direction;
}				t_ray;

typedef struct	s_color
{
	double		red;
	double		green;
	double		blue;
}				t_color;

typedef struct		s_sphere
{
	double		radius;
	t_vector	position;
	int			c;
	t_color		color;
}					t_sphere;




typedef struct s_light{
	t_vector	position;
	t_color		intensity;
}				t_light;

// typedef struct	s_plane
// {
// 	double		d;
// 	t_vector	n;
// 	t_color		diffuse;
// }				t_plane;


typedef struct	s_plane
{
	t_point		start1;
	t_point		start2;
	t_point		finish1;
	t_point		finish2;
	int	width;
	int height;
	int		color;
}				t_plane;


typedef struct	s_square
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	int		color;
}				t_square;

typedef struct	s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	int		color;
}				t_triangle;


typedef struct	s_cube
{
	t_square base;
    int		height;
	int		color;
}				t_cube;

typedef struct	s_tetra
{
	int height;
	t_triangle	base;
	int		color;
}				t_tetra;

typedef struct	s_pyramid
{
	int height;
	t_square	base;
	t_point top;
	int		color;
}				t_pyramid;

typedef struct	s_cylinder
{
	t_point start;
	t_point end;
	double		radius;
	int		color;
}				t_cylinder;

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
	int to_draw_plane;
	double r;
	double g;
	double b;
	int to_draw_controls;
	int to_draw_info;
	int x_start;
	int y_start;
	int x_finish;
	int y_finish;
	int power;
	int lock_shape;
	int projection;
	int zoom;
	double alpha;
	double beta;
	double gamma;
	int offset_x;
	int offset_y;
	int offset_z;
} t_rtv;


#define min(a,b) (((a) < (b)) ? (a) : (b))

void    set_defaults(t_rtv *rtv);
void init_draw(t_rtv *rtv);
t_rtv *init_rtv(void);

void mlx(t_rtv *rtv);

void	draw_line(t_rtv *f, t_point p1, t_point p2, int c);
void		draw_p_line(t_rtv *rtv, t_point p1, t_point p2, int c);

void    add_px(t_rtv *rtv, int x, int y, int color);

void	draw(t_rtv *rtv);

void		rx(int *y, int *z, double alpha);
void		ry(int *x, int *z, double beta);
void		rz(int *x, int *y, double gamma);

void	error(char *msg);
void	end(char *msg);
void	rotate(int keycode, t_rtv *rtv);

int		closer_hook(void *param);
int		keys_hook(int keycode, void *param);
int		mouse_hook(int keycode, int x, int y, void *param);

void		iso(int *x, int *y, int z);
t_point		projected_p(t_rtv *rtv, t_point p);
t_point		projected_cords(t_rtv *rtv, int *x, int *y, int *z);
// t_point		project_p(t_rtv *rtv, t_point p);

void	affect_int(int *x, int val);
void	affect_double(double *x, double val);
void	affect_double2(double *x, double val);
void	affect_int2(int *x, int val);
void	affect_double3(double *x, double *y, double val);

void	position(int keycode, t_rtv *rtv);
void	zoom(int keycode, t_rtv *rtv);
void	reset(int keycode, t_rtv *rtv);


t_point get_point(int x, int y, int z);
void    add_point(t_rtv *rtv,t_point p, int c);
void    add_p_point(t_rtv *rtv, t_point p, int c);
void    add_p_point2(t_rtv *rtv, int x, int y, int z, int c);

void draw_axis(t_rtv *rtv);

t_sphere get_sphere(int radius, t_color color, t_vector position);


// t_sphere *get_g_spheres(int count, int radius);
//void draw_g_spheres(t_rtv *rtv, int count, int radius);



t_light get_light(t_vector	position, t_color intensity);

t_vector vector_sub(t_vector *v1, t_vector *v2);
float vector_dot(t_vector *v1, t_vector *v2);
t_vector vector_scale(float c, t_vector *v);
t_vector vector_add(t_vector *v1, t_vector *v2);


t_color		get_color(double r, double g, double b);
int		get_color1(int r, int g, int b);

void draw_test(t_rtv *rtv);

t_vector	projected_v(t_rtv *rtv, t_vector v);
t_vector vector_new(int x, int y, int z);

#endif

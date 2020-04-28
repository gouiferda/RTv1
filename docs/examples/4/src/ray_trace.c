#include "rtv1.h"

int ray_tracer_figures(t_vector o, t_vector direction, double min, double max, t_rtv *s)
{
	s->sf.closest_obj = max;
	closest_object(o, direction, min, max, s);
	if (s->sf.closest_obj == max || s->sf.near == NULL)
		return (0);
	t_vector point;
	t_vector normal;
	t_vector a;

	point = vector_add(o, vector_mult_scal(s->sf.closest_obj, direction));

	normal = get_normal(s->sf.near, point);

	
	t_vector view = vector_mult_scal(-1.0, direction);

	double fg = lightning(s, point, normal, s->sf.near->spec, view);
	if (s->sf.near->material == 0)
		s->sf.near->color = texture_color(normal, s->sf.closest_obj, s->texure_surf);
	return ((color_parse(s->sf.near->color, fg)));
}

t_color		texture_color(t_vector normal, double hit, SDL_Surface *texture)
{
	t_color		col;
	Uint32		color;
	double		u;
	double		v;
	int x = 0;
	int y = 0;

	u = 0.5 + atan2(normal.z, normal.x) / (M_PI);
	v = 0.5 - asin(normal.y/2.0)/M_PI;
	v = v - floor(v);
	u = u - floor(u);
	// printf("u: %f v : %f\n",normal.z ,normal.x);
	SDL_LockSurface( texture );

	x = (int)(texture->w * u * 10.0 ) % texture->w;
	y = (int)(texture->h * v * 10.0 ) % texture->h;
	// printf("x: %d y : %d\n",x ,y);
	// color = getcolor(texture, abs(x % (int)texture->w), abs(y % (int)texture->h));
	color = getcolor(texture, x ,y);

	SDL_GetRGB(color, texture->format, &col.r, &col.g, &col.b);

	SDL_UnlockSurface( texture );

	color = (col.r << 16 | col.g << 8 | col.b);
	return (col);
}

Uint32		getcolor(SDL_Surface *texture, int x, int y)
{
	Uint8			*pixel;
	unsigned int	sz;

	sz = sizeof(Uint32);
	pixel = (Uint8*)texture->pixels;
	pixel += ((Uint32)y * (Uint32)texture->pitch) + ((Uint32)x * texture->format->BytesPerPixel);
	// printf("%d\n", pixel[((Uint32)y * (Uint32)1) + ((Uint32)x * sz)]);
	// exit(0);
	return (*((Uint32*)pixel));
}
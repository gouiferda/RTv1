#include "rtv1.h"

int clamp(int a)
{
	if (a <= 0)
		return (0);
	else if (a > 255)
		return (255);
	return (a);
}

int		color_parse(t_color col, double c)
{
	int r;
	int g;
	int b;
	int	color;

	r = clamp((col.r & 0xFF) * c);
	g = clamp((col.g & 0xFF) * c);
	b = clamp((col.b & 0xFF) * c);
	color = (r << 16 | g << 8 | b);
	return (color);
}

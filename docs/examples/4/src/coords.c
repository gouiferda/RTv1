#include "rtv1.h"

t_vector		convert_coords(t_rtv *s, int x, int y)
{
	t_vector		dis;

	dis.x = ((double)x) * s->vp.w / WIDTH;
	dis.y = ((double)y) * s->vp.h / HEIGHT;
	dis.z = 1.0;
	return (dis);
}
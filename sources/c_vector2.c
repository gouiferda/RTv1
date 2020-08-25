#include "rtv.h"

t_vector		vecopx(t_vector a, double x)
{
	t_vector	v;

	v.x = a.x * x;
	v.y = a.y * x;
	v.z = a.z * x;
	return (v);
}

double		vecdot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector		vecnorm(t_vector a)
{
	double	k;

	if (a.x == 0.0 && a.y == 0.0 && a.z == 0.0)
		return (vecset(0, 0, 0));
	k = 1.0 / sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (vecopx(a, k));
}

t_vector		veccross(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

t_vector		vecsub(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}



t_vector		vecadd(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vector		vecset(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

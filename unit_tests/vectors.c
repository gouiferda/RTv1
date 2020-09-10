
#include <stdio.h>
#include <math.h>
#include "headers.h"


t_vector newVect(double x, double y,double z)
{
	t_vector v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

double		vectDot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector		vectScale(t_vector a, double x)
{
	t_vector	v;

	v.x = a.x * x;
	v.y = a.y * x;
	v.z = a.z * x;
	return (v);
}

t_vector		vectNorm(t_vector a)
{
	double	k;

	if (a.x == 0.0 && a.y == 0.0 && a.z == 0.0)
		return (newVect(0, 0, 0));
	k = 1.0 / sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (vectScale(a, k));
}

t_vector		vectAdd(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vector		vectSub(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vector		vectCross(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}


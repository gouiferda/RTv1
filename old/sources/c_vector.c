/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"


t_vector vector_new(int x, int y, int z)
{
    t_vector vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return (vector);
}

/* Subtract two vectors and return the resulting vector */
t_vector vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z };
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vector_dot(t_vector *v1, t_vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}


/* Calculate Vector x Scalar and return resulting Vector*/ 
t_vector vector_scale(float c, t_vector *v)
{
        t_vector result = {v->x * c, v->y * c, v->z * c };
        return result;
}

/* Add two vectors and return the resulting vector */
t_vector vector_add(t_vector *v1, t_vector *v2)
{
        t_vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
        return result;
}



/* Calculate vector cross product and return resulting vector */
t_vector vector_cross(t_vector *v1, t_vector *v2){
	t_vector result;
	
	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);
	
	return result;
}

t_vector	vector_normalize(t_vector *n)
{
	double temp;

	temp = vector_dot(n, n);
	if (temp != 0)
		temp = 1.0f / sqrt(temp);
	return (vector_scale(temp, n));
}

double		vector_cos(t_vector *v1, t_vector *v2)
{
	double a;
	double b;
	double c;
	double cos;

	a = vector_dot(v1, v2);
	b = vector_dot(v1, v1);
	c = vector_dot(v2, v2);
	cos = a / (b * c);
	return (cos);
}

double		vector_sin(t_vector *v1, t_vector *v2)
{
	double cos;
	double sin;

	cos = vector_cos(v1, v2);
	sin = sqrt(1 - cos * cos);
	return (sin);
}

double		vector_len(t_vector *v1, t_vector *v2)
{
	double a;

	a = vector_dot(v1, v2);
	return (sqrt(a));
}




t_vector	projected_v(t_rtv *rtv, t_vector v)
{
	v.y = v.y * -1;
	// v.x *= rtv->zoom;
	// v.y *=  rtv->zoom;
	// v.z *=  rtv->zoom;
	v.z += rtv->offset_z;
    // rx(&v.y, &v.z, rtv->alpha);
	// ry(&v.x, &v.z, rtv->beta);
	// rz(&v.x, &v.y, rtv->gamma);
	//iso(&p.x, &p.y, p.z);
	v.x += rtv->offset_x + (rtv->screen_w / 2);
	v.y += rtv->offset_y + (rtv->screen_h / 2);
	return (v);
}
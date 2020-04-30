
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

/* Subtract two vectors and return the resulting t_vector */
t_vector vectorSub(t_vector *v1, t_vector *v2)
{
	t_vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(t_vector *v1, t_vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate t_vector x Scalar and return resulting t_vector*/
t_vector vectorScale(float c, t_vector *v)
{
	t_vector result = {v->x * c, v->y * c, v->z * c};
	return result;
}

/* Add two vectors and return the resulting t_vector */
t_vector vectorAdd(t_vector *v1, t_vector *v2)
{
	t_vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return result;
}
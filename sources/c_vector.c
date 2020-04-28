
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

/* Subtract two vectors and return the resulting vector */
vector vectorSub(vector *v1, vector *v2)
{
	vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(vector *v1, vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate vector x Scalar and return resulting vector*/
vector vectorScale(float c, vector *v)
{
	vector result = {v->x * c, v->y * c, v->z * c};
	return result;
}

/* Add two vectors and return the resulting vector */
vector vectorAdd(vector *v1, vector *v2)
{
	vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return result;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:00:48 by arudenko          #+#    #+#             */
/*   Updated: 2018/07/24 13:40:40 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector get_normal(t_figure *fig, t_vector point)
{
	if (fig->name == SPHERA)
		return (spher_normal(fig, point));
	else if (fig->name == PLANE)
		return (plane_normal(fig));
	else if (fig->name == CYLINDER)
		return (cylinder_normal(point, fig));
	else if (fig->name == CONE)
		return (cone_normal(point, fig));
	return ((t_vector){0.0, 0.0 ,0.0});
}

t_vector spher_normal(t_figure *fig, t_vector point)
{
	t_vector normal;

	normal = vector_sub(point, fig->pos);
	normal = vector_mult_scal(1.0 / vec_len(normal), normal);
	// normal = vector_mult_scal(-1.0, normal);
	// normal = vnormalize(normal);
	return (normal);
}

t_vector plane_normal(t_figure *fig)
{
	// vec_len(fig->direction)
	return (vnormalize(fig->direction));
}

t_vector		cylinder_normal(t_vector point, t_figure *fig)
{
	double		m;
	t_vector	normal;

	// fig->pos = vnormalize(vector_mult_scal(-1.0, fig->pos));
	m = vector_dot(vector_sub(point, fig->pos), fig->direction);
	normal = vector_add(fig->pos, vector_mult_scal(m, fig->direction));
	normal = vnormalize(vector_sub(point, normal));
	return (normal);
}

t_vector		cone_normal(t_vector point, t_figure *obj)
{
	double		m;
	t_vector	res;

	m = pow(vec_len(vector_sub(point, obj->pos)), 2) / vector_dot(vector_sub(point,
			obj->pos), obj->direction);
	res = vector_add(obj->pos, vector_mult_scal(m, obj->direction));
	res = vnormalize(vector_sub(point, res));
	return (res);
}
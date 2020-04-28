/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:47:53 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 13:49:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_root find_sphere(t_vector origin, t_vector direction, t_figure *sphere)
{
	t_root d;
	double discrim;
	t_vector oc;
	t_vector res;

	oc = vector_sub(origin, sphere->pos);
	res.x = vector_dot(direction, direction);
	res.y = 2 * vector_dot(oc, direction);
	res.z = vector_dot(oc, oc) - sphere->radius * sphere->radius;
	discrim = res.y * res.y - (4.0 * res.x * res.z);
	if (discrim < 0)
	{
		return ((t_root){-1, -1});
	}
	d.a = ((-res.y + sqrt(discrim)) / (2.0 * res.x));
	d.b = ((-res.y - sqrt(discrim)) / (2.0 * res.x));
	return (d);
}

// t_root find_plane(t_vector origin, t_vector direction, t_figure *obj)
// {
// 	t_root k;
// 	t_vector subs;

// 	subs = vector_sub(origin, obj->pos);
// 	k.a = vector_dot(direction, obj->direction);
// 	k.b = vector_dot(subs, obj->direction);
// 	if (k.a != 0)
// 		return ((t_root){-k.b / k.a, -1.0});
// 	return ((t_root){-1.0, -1.0});
// }

t_root find_plane(t_vector origin, t_vector direction, t_figure *obj)
{
	t_root k;

	k = (t_root){-1, -1};
	if (obj->direction.x != 0 || obj->direction.y != 0 || obj->direction.z != 0)
		k.a = vector_dot(obj->direction, vector_sub(obj->pos, origin)) /
				vector_dot(obj->direction, direction);
		k.b = -1.0;
	return (k);
}

//  a   = D|D - (D|V)^2
//    b/2 = D|X - (D|V)*(X|V)
//    c   = X|X - (X|V)^2 - r*r
// Surface normal is:

//    m = D|V*t + X|V
//    N = nrm( P-C-V*m )

t_root			find_cylinder(t_vector origin, t_vector dir, t_figure *obj)
{
	t_vector	res;
	double		discrim;
	t_root		d;

    // obj->pos = vnormalize(obj->pos);
	res.x = vector_dot(dir, dir) - pow(vector_dot(dir, obj->direction), 2.0);

	res.y = (vector_dot(dir, vector_sub(origin, obj->pos)) - vector_dot(dir, obj->direction) *
			vector_dot(vector_sub(origin, obj->pos), obj->direction)) * 2.0;

	res.z = vector_dot(vector_sub(origin, obj->pos), vector_sub(origin, obj->pos)) -
		pow(vector_dot(vector_sub(origin, obj->pos), obj->direction), 2) - (obj->radius * obj->radius);
	discrim = res.y * res.y - (4.0 * res.x * res.z);
	if (discrim < 0)
	{
		return ((t_root){-1, -1});
	}
	d.a = ((-res.y + sqrt(discrim)) / (2.0 * res.x));
	d.b = ((-res.y - sqrt(discrim)) / (2.0 * res.x));
	return (d);
}

t_root		find_cone(t_vector origin, t_vector dir, t_figure *obj)
{
	//vector - dir
	t_vector	res;
	double		discrim;
	t_root d;

	res.x = vector_dot(dir, dir) - ((1 + pow(obj->radius, 2)) *
			(pow(vector_dot(dir, obj->direction), 2)));
	res.y = 2 * (vector_dot(dir, vector_sub(origin, obj->pos)) -
			((1 + pow(obj->radius, 2)) *
			vector_dot(dir, obj->direction) *
			vector_dot(vector_sub(origin, obj->pos), obj->direction)));
	res.z = vector_dot(vector_sub(origin, obj->pos),
			vector_sub(origin, obj->pos)) -
			((1 + pow(obj->radius, 2)) *
			(pow(vector_dot(vector_sub(origin, obj->pos),
					obj->direction), 2)));
	discrim = (res.y * res.y) - (4 * res.x * res.z);
	if (discrim < 0)
	{
		return ((t_root){-1, -1});
	}
	d.a = ((-res.y + sqrt(discrim)) / (2.0 * res.x));
	d.b = ((-res.y - sqrt(discrim)) / (2.0 * res.x));
	return (d);
}
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

int get_color(int r, int g, int b)
{
	return (r << 16) + (g << 8) + (b);
}

t_color get_color_s(int r, int g, int b)
{
	t_color color = {r, g, b};
	return color;
}

t_color colorConverter(int c)
{
	t_color rgbColor;

	rgbColor.r = 1;
	rgbColor.g = 1;
	rgbColor.b = 0;
	return rgbColor;
}
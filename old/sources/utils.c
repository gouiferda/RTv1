/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	affect_int(int *x, int val)
{
	if (*x + val > 0)
		*x = *x + val;
}

void	affect_double(double *x, double val)
{
	if (*x + val > 0)
		*x = *x + val;
}

void	affect_double2(double *x, double val)
{
	*x = *x + val;
}

void	affect_int2(int *x, int val)
{
	*x = *x + val;
}

void	affect_double3(double *x, double *y, double val)
{
	*x = *x + val;
	*y = *y + val;
}

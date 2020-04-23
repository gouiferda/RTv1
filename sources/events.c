/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "keys.h"

void	error(char *msg)
{
	ft_putstr("rtv Error: ");
	ft_putendl(msg);
	exit(0);
}

void	end(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void reset(int keycode, t_rtv *rtv)
{
	set_defaults(rtv);
	draw(rtv);
}
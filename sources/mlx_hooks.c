/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "keys.h"

int closer_hook(void *param)
{
	t_rtv *rtv;

	rtv = (t_rtv *)param;
	free(rtv->mlx);
	free(rtv->win);
	free(rtv->img_ptr);
	free(rtv->img_data);
	free(rtv);
	ft_putendl("RTv1:		Ended");
	exit(0);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, void *param)
{
	t_rtv	*rtv;

	rtv = (t_rtv *)param;
	return (0);
}

int keys_hook(int keycode, void *param)
{
	t_rtv *rtv;

	rtv = (t_rtv *)param;
	
	if (keycode == MAIN_PAD_ESC)
		closer_hook(rtv);
	if (keycode == MAIN_PAD_SPACE)
		reset(keycode, rtv);
	return (0);
}

int expose(void *param)
{
	t_rtv *rtv;

	//rtv = (t_rtv *)param;
	//printf("expose event\n");

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int x_hook(void *param)
{
    t_rtv *rtv;

    rtv = (t_rtv *)param;
    free(rtv);
    ft_putendl("RTv1:		Ended");
    exit(0);
    return (0);
}

void mlx(t_rtv *rtv)
{
    mlx_hook(rtv->win, 17, 0, x_hook, rtv);
	mlx_hook(rtv->win, 17, 0, closer_hook, rtv);
    mlx_hook(rtv->win, 2, 0, keys_hook, rtv);
	mlx_hook(rtv->win, 4, 0, mouse_hook, rtv);
	mlx_hook(rtv->win, 12, 0, expose, rtv);
    ft_putendl("minilibx:       Looping");
    mlx_loop(rtv->mlx);
    ft_putendl("RTv1:           Finished");   
}

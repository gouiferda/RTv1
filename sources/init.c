/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void init_draw(t_rtv *rtv)
{
    int i;
    int *img;

    ft_bzero(rtv->img_data,
             (rtv->screen_w) * rtv->screen_h * (rtv->bpp / 8));
    img = (int *)(rtv->img_data);
    i = 0;
    while (i < rtv->screen_h * (rtv->screen_w))
    {
        img[i] = BACKGROUND;
        i++;
    }
}

void    set_defaults(t_rtv *rtv)
{
    rtv->offset_x = OFFSET_X_DEFAULT;
    rtv->offset_y = OFFSET_Y_DEFAULT;
    rtv->offset_z = OFFSET_Z_DEFAULT;
    rtv->zoom = ZOOM_DEFAULT;
	rtv->alpha = ALPHA;
	rtv->beta = BETA;
	rtv->gamma = GAMMA;
    rtv->screen_w = SCREEN_W;
    rtv->screen_h = SCREEN_H;
}

t_rtv *init_rtv(void)
{
    t_rtv *rtv;

    ft_putendl("_________________________");
    ft_putendl("\n");
    ft_putendl("RTv1:           Main");
    ft_putendl("RTv1:           Init RTv1");
    rtv = (t_rtv *)ft_memalloc(sizeof(t_rtv));
    set_defaults(rtv);
    rtv->mlx = mlx_init();
    rtv->img_ptr = mlx_new_image(rtv->mlx, rtv->screen_w, rtv->screen_h);
    rtv->img_data = mlx_get_data_addr(rtv->img_ptr, &(rtv->bpp), &(rtv->size_line), &(rtv->endian));
    rtv->win = mlx_new_window(rtv->mlx, rtv->screen_w, rtv->screen_h, "RTv1 v1.0 - @sgouifer");
    return (rtv);
}

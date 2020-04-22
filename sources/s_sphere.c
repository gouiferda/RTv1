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

// t_sphere *get_g_spheres(int count, int radius)
// {
//     t_sphere *spheres;
//     spheres = (t_sphere *)malloc(sizeof(t_sphere) * count);
//     int i = 0;
//     while (i < count)
//     {
//         spheres[i] = get_sphere(radius, ((i + 100) * 1000), get_point((count * radius * -1 + radius / 4) + ((radius * 2 + radius / 2) * i), radius, 0));
//         i++;
//     }
//     return (spheres);
// }


// void draw_g_spheres(t_rtv *rtv, int count, int radius)
// {
//     draw_spheres(rtv, get_g_spheres(count,radius), count);
// }


// void draw_spheres(t_rtv *rtv, t_sphere *spheres, int s_c)
// {
//     int i;
//     i = 0;
//     while (i < s_c)
//     {
//         //printf("radius: %d\n", spheres[i].radius);
//         draw_sphere(rtv, spheres[i]);
//         i++;
//     }
// }

// void draw_sphere(t_rtv *rtv, t_sphere sphere)
// {
//     t_point p;
//     p = projected_p(rtv, sphere.position);
//     if (rtv->zoom > 0)
//         sphere.radius *= rtv->zoom;

//     draw_circle(rtv, p.x, p.y, p.z, sphere.radius, sphere.color); //old

//     //new
//     ///*
//     int x_start = p.x - sphere.radius;
//     int x_finish = p.x + sphere.radius;
//     int y_start = p.y - sphere.radius;
//     int y_finish = p.y + sphere.radius;
//     int x = x_start;
//     int y = y_start;
//     //printf("%d %d \n",rtv->screen_w,rtv->screen_h);
//     while (x < x_finish)
//     {
//         y = y_start;
//         while (y < y_finish)
//         {
            
//            if ((sphere.radius) > sqrt((int)pow((double)x- p.x,2) + (int)pow((double)y- p.y,2)))
//             {
//                 add_px(rtv, x, y, sphere.color);
//             }
                
//             y++;
//         }
//         x++;
//     }
//    // */
//     //end new

//     mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
// }

t_sphere get_sphere(int radius, t_color color, t_vector position)
{
    t_sphere sphere;
    sphere.position = position;
    sphere.color = color;
    sphere.c = BLUE;
    sphere.radius = radius;
    return (sphere);
}
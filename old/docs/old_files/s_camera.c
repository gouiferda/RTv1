/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:32:02 by sgouifer          #+#    #+#             */
/*   Updated: 2019/03/09 22:32:05 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void draw_camera_icon(t_rtv *rtv, t_point position, int c)
{
    int s_w;
    t_square s;
    t_triangle t;

    s_w = 10;
    s.color = c;
    s.p1.x = position.x ;
    s.p1.y = position.y + s_w;
    s.p1.z = position.z + s_w * 2;
    s.p2.x = position.x ;
    s.p2.y = position.y - s_w;
    s.p2.z = position.z+ s_w * 2;
    s.p3.x = position.x ;
    s.p3.y = position.y - s_w;
    s.p3.z = position.z- s_w * 2;
    s.p4.x = position.x ;
    s.p4.y = position.y + s_w;
    s.p4.z = position.z- s_w * 2;

    t.color = c;
    t.p1.x = position.x ;
    t.p1.y = ((position.y + s_w) + (position.y - s_w)) / 2;
    t.p1.z = position.z- s_w * 2;
    t.p2.x = position.x;
    t.p2.y = position.y + s_w;
    t.p2.z = position.z- s_w * 4;
    t.p3.x = position.x ;
    t.p3.y = position.y - s_w;
    t.p3.z = position.z- s_w * 4;

    t_point cam_start;
    cam_start.x = position.x;
    cam_start.y = ((position.y + s_w) + (position.y - s_w)) / 2;
    cam_start.z = position.z- s_w * 6;

    int frame_w = rtv->screen_w;
    int frame_h = rtv->screen_h;
    int frame_z = position.z - 100;

    draw_pyramid2(rtv,
               get_pyramid2(
                   YELLOW,
                   get_square(YELLOW, get_point(frame_w / 2, frame_h / 2, frame_z),
                                get_point(-frame_w / 2, frame_h / 2, frame_z),
                                get_point(-frame_w / 2, -frame_h / 2, frame_z),get_point(frame_w / 2,-frame_h / 2, frame_z)),cam_start));

    draw_square(rtv, s);
    draw_triangle(rtv, t);
}
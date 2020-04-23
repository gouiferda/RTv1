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

// draw plane test

#include "rtv.h"

t_vector intersectionPoint2(t_vector lineVector, t_vector linePoint, t_vector planeNormal, t_vector planePoint)
{
    t_vector diff = vector_sub(&linePoint, &planePoint);

    t_vector add1 = vector_add(&diff, &planePoint);
    double dot1 = -vector_dot(&diff, &planeNormal);
    double dot2 = vector_dot(&lineVector, &planeNormal);
    double div = dot1 / dot2;
    t_vector v_s = vector_scale(div, &lineVector);
    return vector_add(&add1, &v_s);
}

typedef struct t_plane2
{
    t_vector p;
    t_vector n;
    t_color color;
} t_plane2;

int intersectRaySphere_v1(t_ray *r, t_sphere *s)
{
    float A = vector_dot(&r->direction, &r->direction);
    t_vector dist = vector_sub(&r->start, &s->position);
    float B = 2 * vector_dot(&r->direction, &dist);
    float C = vector_dot(&dist, &dist) - (s->radius * s->radius);
    float discr = B * B - 4 * A * C;
    if (discr < 0)
        return 0;
    else
        return 1;
}


void draw_test2(t_rtv *rtv)
{

    // t_ray ray;
    // ray.start = vector_new(0,0,10);
    // ray.direction = vector_new(0,0,-10);

    // t_plane2 plane;
    //  plane.p = vector_new(0,0,5);
    //  plane.n = vector_new(0,0,1);

    // if (vector_dot(&ray.direction, &plane.n) == 0)
    //     printf("Line and Plane do not intersect, either parallel or line is on the plane");
    // else
    // {

    //     t_vector iP = intersectionPoint2(ray.direction, ray.start, plane.n, plane.p);

    //     printf("Intersection point is (%lf,%lf,%lf)\n", iP.x, iP.y, iP.z);
    // }

    init_draw(rtv);

    int final_color = BLACK;

    //v1
    ///*
    int hit;
    t_sphere s;
    t_ray r;
    s.position = vector_new(200, 200, 100);
    s.radius = 100;
    s.c = BLUE;

    t_plane2 plane;
    plane.p = vector_new(0, 0, 5);
    plane.n = vector_new(0, 0, 1);

    r.direction = vector_new(0, 0, 1);
    r.start.z = 0;
    //*/
    t_vector iP;

    int x = 0;
    int y = 0;

    while (x < rtv->screen_w)
    {
        y = 0;
        r.start.x = x;
        while (y < rtv->screen_h)
        {
            final_color = BLACK;
            r.start.y = y;

            if (intersectRaySphere_v1(&r, &s))
            {
                hit = intersectRaySphere_v1(&r, &s);
                 if (hit) final_color = YELLOW;
            }else if (vector_dot(&r.direction, &plane.n) != 0)
            {
                iP = intersectionPoint2(r.direction, r.start, plane.n, plane.p);

                if (iP.x == x && iP.y == y)
                    if (hit) final_color = BLUE;
            }else{
                final_color = BLACK;
            }

            add_px(rtv, x, y, final_color);

            y++;
        }
        x++;
    }

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
    draw_axis(rtv);
}

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

int plane_inter_v1(t_ray ray, t_figure figure, t_vector *s1)
{
    t_vector line_dir_vector = vectorSub(&ray.dir, &ray.pos); //has values a b and c
    t_vector plane_norm = vectorSub(&figure.dir,&figure.pos);
    t_vector plane_point = figure.pos;

    float denom = vectorDot(&plane_norm, &line_dir_vector);

    // Prevent divide by zero:
    if (abs(denom) <= 1e-4f)
        return (0);

    // If you want to ensure the ray reflects off only
    // the "top" half of the plane, use this instead:
    if (-denom <= 1e-4f)
        return (0);

    float t = -(vectorDot(&plane_norm, &ray.pos) + 10) / denom;
    if (t <= 1e-4)
        return (0);

    t_vector vv = vectorScale(t, &line_dir_vector);
    *s1 = vectorAdd(&ray.pos, &vv);
    return 1;
}

int sphere_inter_v1(t_ray ray, t_figure figure, t_vector *s1, t_vector *s2)
{
    double a, b, c, t1, t2;
    int res = 0;

    a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
    b = -2 * ((ray.dir.x - ray.pos.x) * (figure.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (figure.pos.y - ray.pos.y) + (figure.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
    c = pow((figure.pos.x - ray.pos.x), 2) + pow((figure.pos.y - ray.pos.y), 2) + pow((figure.pos.z - ray.pos.z), 2) - pow(figure.radius, 2);

    t1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    t2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

    s1->x = ray.pos.x + ((ray.dir.x - ray.pos.x) * t1);
    s1->y = ray.pos.y + ((ray.dir.y - ray.pos.y) * t1);
    s1->z = ray.pos.z + ((ray.dir.z - ray.pos.z) * t1);

    s2->x = ray.pos.x + ((ray.dir.x - ray.pos.x) * t2);
    s2->y = ray.pos.y + ((ray.dir.y - ray.pos.y) * t2);
    s2->z = ray.pos.z + ((ray.dir.z - ray.pos.z) * t2);

    if ((pow(b, 2) - (4 * a * c)) >= 0)
        res = 1;

    return (res);
}

void draw_figures_v1(t_rtv *rtv)
{
    int final_color = BLACK;

    double ray_start_z = -1000;
    int ray_len = 1000;

    t_ray ray;
    //Ray = { starting point, direction };
    ray.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);

    // t_figure figure1;
    // figure1.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), 0);
    // figure1.radius = 50;
    // figure1.color = YELLOW;

    int figures_count = 4;
    t_figure figures[figures_count];
    int colors[] = {RED, BLUE, YELLOW, GREEN};
    int figure_types[] = {SPHERE, SPHERE,SPHERE, PLANE};
    int start_x = rtv->screen_w / 3;
    int bet_s = 30;

    int k = 0;
    while (k < figures_count)
    {
        figures[k].pos = newVect(start_x, (rtv->screen_h / 2), 0);
        figures[k].radius = 50;
        figures[k].color = colors[k];
        figures[k].type = figure_types[k];
        figures[k].dir = newVect(start_x, (rtv->screen_h / 2), -100);
        start_x += (figures[k].radius * 2) - 30;
        k++;
    }

    t_vector s1, s2, s3;

    int x = 0;
    int y = 0;
    int closest_object_index = -1;
    int minDistance = ray_len;

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            //for each object in the scene determine closest ray object/intersection;
            k = 0;
            minDistance = ray_len;
            while (k < figures_count)
            {
                if (figures[k].type == SPHERE)
                {
                    if (sphere_inter_v1(ray, figures[k], &s1, &s2) == 1)
                    {
                        if (s2.z < minDistance)
                        {
                            minDistance = s2.z;
                            closest_object_index = k;
                        }
                    }
                }
                else if (figures[k].type == PLANE)
                {
                    if (plane_inter_v1(ray, figures[k], &s3) == 1)
                    {
                        if (s3.z < minDistance)
                        {
                            minDistance = s3.z;
                            closest_object_index = k;
                        }
                    }
                }
                k++;
                
            }
            ray.dir = newVect(x, y, ray_len);
            if (closest_object_index != -1)
            {
                if (figures[closest_object_index].type == SPHERE)
                {
                    if (sphere_inter_v1(ray, figures[closest_object_index], &s1, &s2) == 1)
                    {
                        final_color = figures[closest_object_index].color;
                        add_px(rtv, x, y, final_color);
                    }
                }
                else if (figures[closest_object_index].type == PLANE)
                {
                    if (plane_inter_v1(ray, figures[closest_object_index], &s3) == 1)
                    {
                        final_color = figures[closest_object_index].color;
                        add_px(rtv, x, y, final_color);
                    }
                }
                closest_object_index = -1;
            }
            y++;
        }
        x++;
    }
}

void draw(t_rtv *rtv)
{
    init_draw(rtv);

    draw_bg(rtv);
    //draw_colorful_test_screen(rtv);
    draw_figures_v1(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

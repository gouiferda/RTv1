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

t_figure *gen_figures(int figures_count)
{
    //generates figures
    t_figure *figures;
    figures = (t_figure *)malloc(sizeof(t_figure) * (figures_count));
    int colors[] = {C_GREEN1, C_YELLOW1, C_RED1, C_GREY1, C_GREY2}; //, C_DARK_BLUE1
    int figure_types[] = {SPHERE, SPHERE, SPHERE, PLANE, PLANE};    //, PLANE
    int start_x = 0;
    int bet_s = 30;
    int sphere_radius = 50;
    int k = 0;
    while (k < figures_count)
    {
        figures[k].pos = newVect(0, 0, 400);
        if (k <= 2)
            figures[k].pos = newVect(start_x, sphere_radius - 10, 0);
        figures[k].radius = sphere_radius;
        figures[k].color = colors[k];
        figures[k].type = figure_types[k];
        // figures[k].c = colorConverter(colors[k]);
        
        figures[k].c.r = 1;
        figures[k].c.g = (k % 2 == 0) ? 0 : 1;
        figures[k].c.b = (k % 4 != 0) ? 0 : 1;
        //figures[k].reflection = 0;
        figures[k].specular = 1;
        figures[k].diffuse = 1;
        figures[k].dir = newVect(0, 10, 400);
        if (k == 4)
            figures[k].dir = newVect(0, 0, 300);
        start_x += (figures[k].radius * 2) - 30;
        k++;
    }
    return figures;
}

int get_surface_color(t_figure f, t_vector i, t_ray r, t_light l)
{
    int final_color = BLACK;
    t_color final_c;
    final_c.r = 0;
    final_c.g = 0;
    final_c.b = 0;
    int specular_k = 250;
    t_vector hit_normal = vectNorm(vectSub(i, f.pos));
    t_vector hit_to_cam = vectSub(r.pos, i);
    t_ray v_tolight_r;
    v_tolight_r.pos = i;
    v_tolight_r.dir = vectSub(l.pos, i);
    t_vector half_vect = vectNorm(vectAdd(v_tolight_r.dir, hit_to_cam));
    double kk = f.specular * max(vectDot(hit_normal, half_vect), 0) * specular_k;
    final_c.r += f.c.r * l.c.r * kk;
    final_c.g += f.c.g * l.c.g * kk;
    final_c.b += f.c.b * l.c.b * kk;
    final_color = get_color(final_c.r, final_c.b, final_c.b);
    return final_color;
}

t_color get_surface_color2(t_figure f, t_vector i, t_ray r, t_light l)
{
    int final_color = BLACK;
    t_color final_c;
    final_c.r = 0;
    final_c.g = 0;
    final_c.b = 0;
    int specular_k = 250;
    t_vector hit_normal = vectNorm(vectSub(i, f.pos));
    t_vector hit_to_cam = vectSub(r.pos, i);
    t_ray v_tolight_r;
    v_tolight_r.pos = i;
    v_tolight_r.dir = vectSub(l.pos, i);
    t_vector half_vect = vectNorm(vectAdd(v_tolight_r.dir, hit_to_cam));
    double kk = f.specular * max(vectDot(hit_normal, half_vect), 0) * specular_k;
    final_c.r += f.c.r * l.c.r * kk;
    final_c.g += f.c.g * l.c.g * kk;
    final_c.b += f.c.b * l.c.b * kk;
    return final_c;
}

void draw_figures_v1(t_rtv *rtv)
{
    int final_color = BLACK;

    //ray
    double ray_start_z = -1000;
    int ray_max_z = 1000;
    int ray_up_angle = 250;
    int ray_left_angle = -100;

    t_ray ray;
    ray.pos = newVect(0 + ray_left_angle, 0 + ray_up_angle, ray_start_z);

    //figures
    int figures_count = 5;
    t_figure *figures = gen_figures(figures_count);

    t_light light1;
    light1.pos = newVect(0, 600, -300);
    light1.c.r = 1;
    light1.c.g = 1;
    light1.c.b = 1;

    //for each pixel in the screen send a ray and save the closest object and show it
    t_vector s1, s2, s3, s4;

    int x = -(rtv->screen_w / 2);
    int y = -(rtv->screen_h / 2);
    int closest_object_index = -1;
    int minDistance = ray_max_z;
    int k = 0;
    while (x < rtv->screen_w / 2)
    {
        y = -(rtv->screen_h / 2);
        while (y < rtv->screen_h / 2)
        {

            t_color final_c;
            final_c.r = 0;
            final_c.g = 0;
            final_c.b = 0;
            //for each object in the scene determine closest ray object/intersection;
            k = 0;
            minDistance = ray_max_z;
            ray.dir = newVect(x, y, ray_max_z);
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
                // else if (figures[k].type == CYLINDER)
                // {
                //     if (cylinder_inter_v1(ray, figures[k], &s4) == 1)
                //     {
                //         closest_object_index = k;
                //         if (s4.z < minDistance)
                //         {
                //             //minDistance = s4.z;
                //             closest_object_index = k;
                //         }
                //     }
                // }
                k++;
            }
            if (closest_object_index != -1)
            {
                if (sphere_inter_v1(ray, figures[closest_object_index], &s1, &s2) == 1)
                {
                    final_color = get_surface_color(figures[closest_object_index], s2, ray, light1);
                    add_px2(rtv, x, y, final_color);
                    // add_px3(rtv, x, y, get_surface_color2(figures[closest_object_index], s3, ray, light1));
                }
                if (plane_inter_v1(ray, figures[closest_object_index], &s3) == 1)
                {
                    final_color = get_surface_color(figures[closest_object_index], s3, ray, light1);
                    add_px2(rtv, x, y, final_color);
                    //add_px3(rtv, x, y, get_surface_color2(figures[closest_object_index], s3, ray, light1));
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
    draw_figures_v1(rtv);
    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

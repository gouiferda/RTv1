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


//draw spheres test

#include "rtv.h"


int intersectRaySphere(t_ray *r, t_sphere *s, float *t)
{

    int retval = 0;
    float A = vector_dot(&r->direction, &r->direction);
    t_vector dist = vector_sub(&r->start, &s->position);
    float B = 2 * vector_dot(&r->direction, &dist);
    float C = vector_dot(&dist, &dist) - (s->radius * s->radius);
    float discr = B * B - 4 * A * C;
    if (discr < 0)
        retval = 0;
    else
    {
        float sqrtdiscr = sqrtf(discr);
        float t0 = (-B + sqrtdiscr) / (2);
        float t1 = (-B - sqrtdiscr) / (2);
        if (t0 > t1)
            t0 = t1;
        if ((t0 > 0.001f) && (t0 < *t))
        {
            *t = t0;
            retval = 1;
        }
        else
            retval = 0;
    }

    return retval;
}

void saveppm(char *filename, unsigned char *img, int width, int height)
{
    FILE *f;
    f = fopen(filename, "wb");
    fprintf(f, "P6 %d %d %d\n", width, height, 255);
    fwrite(img, 3, width * height, f);
    fclose(f);
}

void draw_test1(t_rtv *rtv)
{
    init_draw(rtv);

    int levels_of_reflection = 1;

    t_ray r;

    t_color sphere_color1 = get_color(1, 0, 0);
    t_color sphere_color2 = get_color(0, 1, 0);
    t_color sphere_color3 = get_color(0, 0, 1);

    int spheres_c = 2;
    t_sphere spheres[spheres_c];
    spheres[0].position = vector_new(200,500,0);
    //spheres[0].position = vector_new(600, 300, 0);
    spheres[0].radius = 100;
    spheres[0].color = sphere_color1;

    spheres[1].position = vector_new(200,300,0);
    //spheres[1].position = vector_new(300, 300, 0);
    spheres[1].radius = 100;
    spheres[1].color = sphere_color2;

    // spheres[2].position.x = 400;
    // spheres[2].position.y = 500;
    // spheres[2].position.z = 0;
    // spheres[2].radius = 100;
    // spheres[2].color = sphere_color3;

    t_color light_color1 = get_color(1, 1, 1);
    t_color light_color2 = get_color(1, 1, 1);

    int lights_c = 2;
    t_light lights[lights_c];
    //lights[0].position= projected_v(rtv,vector_new(0,300,-200));
    lights[0].position = vector_new(0, 300, -200);
    lights[0].intensity = light_color1;

    lights[1].position = vector_new(rtv->screen_w, 200, -300);
    lights[1].intensity = light_color2;

    // lights[2].position= vector_new(0,-100,-200);
    // lights[2].intensity = light_color1;
    

    int x = 0;
    int y = 0;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            float red = 0;
            float green = 0;
            float blue = 0;

            int level_refl = 0;
            float coef = 1;

            r.start = vector_new(x, y, -2000);
            r.direction = vector_new(0, 0, 1);

            while ((coef > 0.0f) && (level_refl < levels_of_reflection))
            {
                float t = 20000.0f;
                int currentSphere = -1;

                unsigned int i;
                for (i = 0; i < 3; i++)
                {
                    if (intersectRaySphere(&r, &spheres[i], &t))
                        currentSphere = i;
                }
                if (currentSphere == -1)
                    break;

                t_vector scaled = vector_scale(t, &r.direction);
                t_vector newStart = vector_add(&r.start, &scaled);
                t_vector n = vector_sub(&newStart, &spheres[currentSphere].position);
                float temp = vector_dot(&n, &n);
                if (temp == 0)
                    break;

                temp = 1.0f / sqrtf(temp);
                n = vector_scale(temp, &n);

                t_color currentColor = spheres[currentSphere].color;

                unsigned int j;
                for (j = 0; j < lights_c; j++)
                {
                    t_light currentLight = lights[j];
                    t_vector dist = vector_sub(&currentLight.position, &newStart);
                    if (vector_dot(&n, &dist) <= 0.0f)
                        continue;
                    float t = sqrtf(vector_dot(&dist, &dist));
                    if (t <= 0.0f)
                        continue;

                    t_ray lightRay;
                    lightRay.start = newStart;
                    lightRay.direction = vector_scale((1 / t), &dist);
                    int inShadow = 0;
                    unsigned int k;
                    for (k = 0; k < spheres_c; ++k)
                    {
                        if (intersectRaySphere(&lightRay, &spheres[k], &t))
                        {
                            inShadow = 1;
                            break;
                        }
                    }
                    if (!inShadow)
                    {
                        float lambert = vector_dot(&lightRay.direction, &n) * coef;
                        red += lambert * currentLight.intensity.red * currentColor.red;
                        green += lambert * currentLight.intensity.green * currentColor.green;
                        blue += lambert * currentLight.intensity.blue * currentColor.blue;
                    }
                }
                coef *= 0.8;

                r.start = newStart;
                float reflect = 2.0f * vector_dot(&r.direction, &n);
                t_vector tmp = vector_scale(reflect, &n);
                r.direction = vector_sub(&r.direction, &tmp);

                level_refl++;
            };
            add_px(rtv, x, y, get_color1(min(red * 255.0f, 255.0f), min(green * 255.0f, 255.0f), min(blue * 255.0f, 255.0f)));
            y++;
        }
        x++;
    }

    //light 1
    add_px(rtv, projected_v(rtv, vector_new(0, 300, -200)).x, projected_v(rtv, vector_new(0, 300, -200)).y, WHITE);


    //draw_axis(rtv);

    //menu
    x = rtv->screen_w;
    y = 0;
    while (x < rtv->screen_w + RIGHT_MENU_W)
    {
        y = 0;
        while (y < rtv->screen_h)
        {

            add_px(rtv, x, y, get_color1(37, 37, 38));
            y++;
        }
        x++;
    }

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);

    
}

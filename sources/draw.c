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

void draw_bg(t_rtv *rtv)
{
    int final_color = BLACK;
    int x = 0;
    int y = 0;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
}

int obj_inter1(t_ray ray, t_object obj, t_point *s1, t_point *s2)
{
    double a, b, c, t1, t2;
    int res = 0;

    if (obj.type == SPHERE)
    {
        a = pow((ray.dir.x - ray.pos.x), 2) + pow((ray.dir.y - ray.pos.y), 2) + pow((ray.dir.z - ray.pos.z), 2);
        b = -2 * ((ray.dir.x - ray.pos.x) * (obj.pos.x - ray.pos.x) + (ray.dir.y - ray.pos.y) * (obj.pos.y - ray.pos.y) + (obj.pos.z - ray.pos.z) * (ray.dir.z - ray.pos.z));
        c = pow((obj.pos.x - ray.pos.x), 2) + pow((obj.pos.y - ray.pos.y), 2) + pow((obj.pos.z - ray.pos.z), 2) - pow(obj.radius, 2);

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
    }
    return (res);
}

void draw_test1(t_rtv *rtv)
{
    int final_color = WHITE;
    int x = 0;
    int y = 0;

    t_light light = {get_point((rtv->screen_w), (rtv->screen_h / 2), -500), 100};

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_pos = get_point((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);
    t_point ray_dir = get_point(0, 0, ray_len);
    t_ray ray = {ray_pos, ray_dir};

    //object in center screen
    int objects_c = 1;
    t_object objects[objects_c];
    int colors[] = {BLUE, RED, GREEN2, ORANGE2, YELLOW, BLUE3, GREEN, BLUE3};
    int j = 0;
    while (j < objects_c)
    {
        objects[j].type = SPHERE;
        objects[j].radius = 50;
        objects[j].pos = get_point((rtv->screen_w / (2 - (j * 0.3))), (rtv->screen_h / 2), 0);
        objects[j].rotation = get_point(0, 0, 0);
        objects[j].color = colors[j];
        j++;
    }
    int i = 0;
    int minDistance = ray_len;
    int closestObjId = -1;
    t_point s1, s2;
    t_point sh1, sh2;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            ray.dir.x = x;
            ray.dir.y = y;
            //     for each object in the scene determine closest ray object/intersection;
            i = 0;
            minDistance = ray_len;
            while (i < objects_c)
            {
                //find intersections with the ray
                if (obj_inter1(ray, objects[i], &s1, &s2) == 1)
                {
                    if (s2.z < minDistance)
                    {
                        minDistance = s2.z;
                        closestObjId = i;
                    }
                }
                i++;
            }
            if (closestObjId != -1)
            {
                if (obj_inter1(ray, objects[closestObjId], &s1, &s2) == 1)
                {

                    final_color = objects[closestObjId].color;
                    add_px(rtv, x, y, final_color);
                    closestObjId = -1;
                }
            }
            y++;
        }
        x++;
    }
}

/* Check if the ray and sphere intersect */
int intersectRaySphere(ray *r, sphere *s, float *t)
{

    int retval = 0;

    /* A = d.d, the vector dot product of the direction */
    float A = vectorDot(&r->dir, &r->dir);

    /* We need a vector representing the distance between the start of 
	 * the ray and the position of the circle.
	 * This is the term (p0 - c) 
	 */
    vector dist = vectorSub(&r->start, &s->pos);

    /* 2d.(p0 - c) */
    float B = 2 * vectorDot(&r->dir, &dist);

    /* (p0 - c).(p0 - c) - r^2 */
    float C = vectorDot(&dist, &dist) - (s->radius * s->radius);

    /* Solving the discriminant */
    float discr = B * B - 4 * A * C;

    /* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
    if (discr < 0)
        retval = 0;
    else
    {
        float sqrtdiscr = sqrtf(discr);
        float t0 = (-B + sqrtdiscr) / (2);
        float t1 = (-B - sqrtdiscr) / (2);

        /* We want the closest one */
        if (t0 > t1)
            t0 = t1;

        /* Verify t1 larger than 0 and less than the original t */
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

void draw_test2(t_rtv *rtv)
{
    int final_color = BLACK;
    int x = 0;
    int y = 0;

    ray r;

    material materials[1];
    materials[0].diffuse.red = 1;
    materials[0].diffuse.green = 0;
    materials[0].diffuse.blue = 0;
    materials[0].reflection = 0.2;

    int spheres_c=1;
    sphere spheres[spheres_c];
    spheres[0].pos.x = (rtv->screen_w / 2);
    spheres[0].pos.y = (rtv->screen_h / 2);
    spheres[0].pos.z = 0;
    spheres[0].radius = 100;
    spheres[0].material = 0;

    int lights_c=1;
    light lights[lights_c];

    lights[0].pos.x = 0;
    lights[0].pos.y = 0;
    lights[0].pos.z = 400;
    lights[0].intensity.red = 1;
    lights[0].intensity.green = 1;
    lights[0].intensity.blue = 1;


    r.start.x = (rtv->screen_w / 2);
    r.start.y = (rtv->screen_h / 2);
    r.start.z = -2000;


    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            float red = 0;
            float green = 0;
            float blue = 0;

            int level = 0;
            float coef = 1.0;

            
            r.dir.x = x;
            r.dir.y = y;
            r.dir.z = 2000;

            /* Find closest intersection */
            float t = 20000.0f;
            int currentSphere = -1;

            unsigned int i;
            for (i = 0; i < spheres_c; i++)
            {
                if (intersectRaySphere(&r, &spheres[i], &t))
                    currentSphere = i;
            }
            if (currentSphere == -1)
                break;

            vector scaled = vectorScale(t, &r.dir);
            vector newStart = vectorAdd(&r.start, &scaled);

            /* Find the normal for this new vector at the point of intersection */
            vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
            float temp = vectorDot(&n, &n);
            if (temp == 0)
                break;

            temp = 1.0f / sqrtf(temp);
            n = vectorScale(temp, &n);

            /* Find the material to determine the colour */
            material currentMat = materials[spheres[currentSphere].material];

            /* Find the value of the light at this point */
            unsigned int j;
            for (j = 0; j < lights_c; j++)
            {
                light currentLight = lights[j];
                vector dist = vectorSub(&currentLight.pos, &newStart);
                if (vectorDot(&n, &dist) <= 0.0f)
                    continue;
                float t = sqrtf(vectorDot(&dist, &dist));
                if (t <= 0.0f)
                    continue;

                ray lightRay;
                lightRay.start = newStart;
                lightRay.dir = vectorScale((1 / t), &dist);

                /* Lambert diffusion */
                float lambert = vectorDot(&lightRay.dir, &n) * coef;
                red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
                green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
                blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
            }
            /* Iterate over the reflection */
            coef *= currentMat.reflection;

            /* The reflected ray start and direction */
            r.start = newStart;
            float reflect = 2.0f * vectorDot(&r.dir, &n);
            vector tmp = vectorScale(reflect, &n);
            r.dir = vectorSub(&r.dir, &tmp);

            final_color = get_color(red,green,blue);
            add_px(rtv, x, y, final_color);

            y++;
        }
        x++;
    }
}

void draw(t_rtv *rtv)
{

    init_draw(rtv);

    draw_bg(rtv);
    //draw_test1(rtv);
    draw_test2(rtv);

    mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
}

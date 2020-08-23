/*
void draw_test1(t_rtv *rtv)
{
    int final_color = RED;

    double ray_start_z = -1000;
    int ray_len = 1000;

    t_ray ray;
    ray.origin = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);

    t_figure figure1;
    figure1.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), 0);
    figure1.radius = 50;
    figure1.color = YELLOW;


    t_vector s1, s2;


    int x = 0;
    int y = 0;

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            ray.dir = newVect(x, y, ray_len);
            if (sphere_inter_v1(ray, figure1, &s1, &s2) == 1)
            {
                final_color = figure1.color;
                add_px(rtv, x, y, final_color);
            }
            y++;
        }
        x++;
    }
}
*/
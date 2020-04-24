


void draw_axis(t_rtv *rtv)
{
    int final_color = WHITE;
    int start_x_axis = -500;
    int end_x_axis = 500;
    int start_y_axis = -500;
    int end_y_axis = 500;
    int start_z_axis = -500;
    int end_z_axis = 500;
    while (start_x_axis < end_x_axis)
    {
        add_p_point(rtv, get_point(start_x_axis, 0, 0), final_color);
        start_x_axis++;
    }
    while (start_y_axis < end_y_axis)
    {
        add_p_point(rtv, get_point(0, start_y_axis, 0), final_color);
        start_y_axis++;
    }
    while (start_z_axis < end_z_axis)
    {
        add_p_point(rtv, get_point(0, 0, start_z_axis), final_color);
        start_z_axis++;
    }
}

void test_d1(t_rtv *rtv)
{

    int final_color = WHITE;
    int x = 0;
    int y = 0;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_start = get_point(-(rtv->screen_w / 2), -(rtv->screen_h / 2), ray_start_z);
    t_ray ray = {ray_start, get_point(0, 0, ray_len)};
    t_object obj1 = {SPHERE, 40, get_point(0, 0, 0), get_point(0, 0, 0), BLUE};

    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            // final_color = WHITE;

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;
            //find intersections with the ray
            if (obj_inter(ray, obj1) == 1)
            {
                final_color = obj1.color;
                add_px(rtv, x, y, final_color);
            }
            y++;
        }
        x++;
    }
}

void test_d2(t_rtv *rtv)
{

    int final_color = BLACK;
    int x = -500;
    int y = -500;
    int x_end = 500;
    int y_end = 500;

    //ray starts from center screen
    int ray_start_z = -1000;
    int ray_len = 1000;
    t_point ray_start = proj_p(rtv,get_point(0, 0, ray_start_z));
    t_point ray_dir = proj_p(rtv,get_point(-500, -500, ray_len));
    t_ray ray = {ray_start, ray_dir};
    t_object obj1 = {SPHERE, rtv->zoom * 50, proj_p(rtv,get_point(0, 0, 0)), get_point(0, 0, 0), RED};

    while (x < x_end)
    {
        y = -500;
        while (y < y_end)
        {
            // final_color = WHITE;

            //cast a ray from the eye
            ray.dir.x = x;
            ray.dir.y = y;
            //find intersections with the ray
            if (obj_inter(ray, obj1) == 1)
            {
                final_color = obj1.color;
                add_px(rtv, x, y, obj1.color);
            }
            y++;
        }
        x++;
    }
}


void draw_colorful_test_screen(t_rtv *rtv)
{
    int final_color = BLUE;
    int x = 0;
    int y = 0;
    int r, g, b;
    while (x < rtv->screen_w)
    {
        y = 0;
        while (y < rtv->screen_h)
        {
            r = y * 0.35;
            g = x * 0.25;
            b = 10;
            final_color = get_color(r, g, b);
            add_px(rtv, x, y, final_color);
            y++;
        }
        x++;
    }
}

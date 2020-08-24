
#include "rtv.h"

void draw_bg(t_rtv *rtv)
{
    int final_color = YELLOW;
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


// void draw_sphere(t_rtv *rtv, t_sphere sphere)
// {
//     int x;
//     int y;

//     //ft_putendl("RTv1:           Drawing sphere");

//     int distance_fr_o;
//     distance_fr_o = 0;
//     x = 0;
//     int z = 10;
//     while (x < rtv->screen_w / 1)
//     {
//         y = 0;
//         while (y < rtv->screen_h / 1)
//         {
//             // if (x < sphere1.position.x && y < sphere1.position.y)
//             //     distance_fr_o =  sqrt(pow((sphere1.position.x) - x,2) + pow((sphere1.position.y) - y,2));
//             // else if (x >= sphere1.position.x && y >= sphere1.position.y)
//             //    distance_fr_o =  sqrt(pow(x - (sphere1.position.x),2) + pow(y - (sphere1.position.y),2));
//             // else if (x < sphere1.position.x && y >= sphere1.position.y)
//             //    distance_fr_o =  sqrt(pow((sphere1.position.x)  -x,2) + pow(y - (sphere1.position.y),2));
//             // else if (x >= sphere1.position.x && y < sphere1.position.y)
//             //    distance_fr_o =  sqrt(pow(x - (sphere1.position.x),2) + pow((sphere1.position.y) - y,2));
//             //sphere1.color = c + (distance_fr_o * 1/4);
//             if ((rtv->zoom + sphere.radius) >= sqrt(((x - rtv->offset_x - sphere.position.x) * (x - rtv->offset_x - sphere.position.x) + (y - rtv->offset_y - sphere.position.y) * (y - rtv->offset_y - sphere.position.y))))
//             {
//                // add_point(rtv, x, y ,z,sphere.color);
//             }
//             y++;
//         }
//         x++;
//     }
//     mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
// }

// void draw_light(t_rtv *rtv, t_light light)
// {
//     int x;
//     int y;
//     int z;

//     //ft_putendl("RTv1:           Drawing light");
//     int distance_fr_o;
//     distance_fr_o = 0;
//     double k = 0.2;
//     int c = light.color;
//     x = 0;
//     z = 0;
//     while (x < rtv->screen_w / 1)
//     {
//         y = 0;
//         while (y < rtv->screen_h / 1)
//         {
//             if (x < light.position.x && y < light.position.y)
//                 distance_fr_o = sqrt(pow((light.position.x) - x, 2) + pow((light.position.y) - y, 2));
//             else if (x >= light.position.x && y >= light.position.y)
//                 distance_fr_o = sqrt(pow(x - (light.position.x), 2) + pow(y - (light.position.y), 2));
//             else if (x < light.position.x && y >= light.position.y)
//                 distance_fr_o = sqrt(pow((light.position.x) - x, 2) + pow(y - (light.position.y), 2));
//             else if (x >= light.position.x && y < light.position.y)
//                 distance_fr_o = sqrt(pow(x - (light.position.x), 2) + pow((light.position.y) - y, 2));
//             light.color = (c - (distance_fr_o * 2.5)); // +rtv->zoom
//             if ((rtv->zoom + light.radius) >= sqrt(((x - light.position.x) * (x - light.position.x) + (y - light.position.y) * (y - light.position.y))))
//                 add_px(rtv, x, y ,light.color);
//             y++;
//         }
//         x++;
//     }
//     //printf("value: %f\n",1/rtv->zoom * 10);
//     mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->img_ptr, 0, 0);
// }


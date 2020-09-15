/*
void draw_test1(t_rtv *rtv)
{
    int final_color = RED;

    double ray_start_z = -1000;
    int ray_len = 1000;

    t_ray ray;
    ray.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), ray_start_z);

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

int plane_inter_v1(t_ray ray, t_figure figure, t_vector *s1)
{

    
    //get plane equation from vector
    //general equation : a(x−x1)+b(y−y1)+c(z−z1)+d=0.

    //plane which passes through plane_point
    //normal vector is plane_norm
    //d is plane radius*2 (optional)

    //equation is:
    //plane_norm.x*(x-plane_point.x)+plane_norm.y*(y-plane_point.y)+plane_norm.z*(z-plane_point.z)+(radius*2)=0

    //we need to get perimitric equation of line:
    //x = X0+at  , y=y0+at , z=z0+at
    // x,y,z 0 are starting point : ray.pos
    //get vector from line (ray)

    //x = ray.pos.x + line_dir_vector.x * t
    //y = ray.pos.y + line_dir_vector.y * t
    //z = ray.pos.z + line_dir_vector.z * t

    //we plug x,y,z from line eq to plane equation to get intersection point
    //we find t then replace it in permitric eq to find intersection point

    //------

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


    /*
    n - the planes normal ray
    Po = single point on the plane
    L = the vector that represents the ray I am shooting
    Lo = a point on the line
    d = a scalar in the real world domain.

    So d needs to equal zero in order for the plane and the ray (at the point I'm looking at) to intersect? And can I use a direction vector coordinates to represent that point on the line>

 //For any point p on the plane, this equation is true:
    //dot(Po-p,N) = 0
    //For any point p on the line, this equation is true:
    //p = Lo+L*d
    //If the point is going to be both on the plane and on the line (the intersection), then they both must be true. Therefore we can substitute:
    //dot(Po-(Lo+L*d),N) = 0

    //d = dot(Po-Lo,N)/dot(L,N)

    // t_ray ray1;
    // ray1.pos = newVect(0, 0, -100);
    // ray1.dir = newVect(0, 0, 100);

    // t_figure plane;
    // plane.pos = newVect(0, 0, 0);
    // plane.dir = newVect(100, 0, 0);

    //  t_vector plane_norm = vectorSub(&figure.dir, &figure.pos);
    // //d = dot(Po-Lo,N)/dot(L,N)
    // t_vector vvv = vectorSub(&figure.pos, &ray.pos);
    // t_vector line_vector = vectorSub(&ray.dir,&ray.pos);
    // double d1 = vectorDot(&vvv, &plane_norm);
    // double d2 = vectorDot(&line_vector, &plane_norm);
    // double d = d1/d2;
    // //printf("result: %.2f\n", d);

    // return (d >= 0 && d<= 1);
}

int plane_inter_v1(t_ray ray, t_figure figure, t_vector *s1)
{
    // line direction, point on line, normal to plane and point on plane given as (x,y,z) tuples separated by space
    t_vector lV, lP, pN, pP, iP;

    lV = vectorSub(&ray.dir, &ray.pos);
    lP = ray.pos;
    pN = vectorSub(&figure.dir, &figure.pos);
    pP = figure.pos;

    if (vectorDot(&lV, &pN) == 0)
        return 0;

    t_vector diff = vectorSub(&lP, &pP);

    t_vector av1 = vectorAdd(&diff, &pP);
    double d1 = -vectorDot(&diff, &pN);
    double d2 = vectorDot(&lV, &pN);

    t_vector sv = vectorScale(d1 / d2, &lV);

    *s1 = vectorAdd(&av1, &sv);

    //lv line vector
    //lp point in line
    //pn plane normal
    //pp point in plane
    //ip point of intersection

    return 1;
}


int plane_inter_v1(t_ray ray, t_figure figure, t_vector *s1)
{
    //Step 1: Convert the plane into an equation
    //plane eq: Ax + By + Cz = D.
    //A , B , C are the coords of normal vector

    //x and y and z  r cords of a point from plane (plane pos)

    t_vector plane_normal = vectorSub(&figure.dir, &figure.pos);
    t_vector plane_point = figure.pos;

    // double d = plane_normal.x * plane_point.x + plane_normal.y * plane_point.y + plane_normal.z * plane_point.z;

    //printf("result: %.2f\n", d);

    //Find the equation for the line

    t_vector ray_normal = vectorSub(&ray.dir, &ray.pos);
    t_vector intersection_p;
    if (vectorDot(&ray_normal, &plane_normal) == 0)
    {
        printf("Line and Plane do not intersect, either parallel or line is on the plane \n");
        return (0);
    }
    else
    {
        t_vector diff = vectorSub(&ray.pos, &plane_point);
        t_vector av1 = vectorAdd(&diff, &plane_point);
        double dot1 = vectorDot(&ray_normal, &plane_normal);
        double dot2 = vectorDot(&diff, &plane_normal);
        t_vector sv1 = vectorScale(-dot2 / dot1, &ray_normal);

        intersection_p = vectorAdd(&av1, &sv1);
        *s1 = intersection_p;
        //printf("intersection_p:(%.2f,%.2f,%.2f) \n", intersection_p.x, intersection_p.y, intersection_p.z);
        return 1;
    }
}
void plane_intersection_test_v1(t_rtv *rtv)
{
    t_ray ray1;
    ray1.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), -500);
    ray1.dir = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), 500);

    t_figure figure1;
    figure1.pos = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), 0);
    figure1.dir = newVect((rtv->screen_w / 2), (rtv->screen_h / 2), 0);

    t_vector s1;

    plane_inter_v1(ray1, figure1, &s1);
}


*/
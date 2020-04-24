# RTv1

## To do

- [X] Author file
- [X] Minilibx expose properly (mlx_expose_hook)
- [ ] Functions and structures 
    - [ ] point/vector
    - [ ] ray
    - [ ] color
    - [ ] sphere
    - [ ] plane
    
    - [ ] cylinder
    - [ ] cone
    - [ ] light
- [ ] Light works on fixed and moved objects
    - [ ] ambiant light 
        - [ ] sphere
        - [ ] plane
        - [ ] cylinder
        - [ ] cone
    - [ ] diffusion 
- [ ] Shadows
- [ ] Multi objects and intersections
- [ ] Moving and rotating the objects
- [ ] Moving and rotating the camera
- [ ] Norm & Handle errors and leaks and messages
- [ ] Bonuses: Shine effect, Multi lights (spots)

______

## Notes

### Pseudo code:

```
for every pixel {
    cast a ray from the eye
    for every object in the scene
    {
        find intersections with the ray
        keep it if closest
    }
    compute color at the intersection point
}
```
Or:

```
for each pixel of the screen {
    Final color = 0;
    Ray = { starting point, direction };
    Repeat
    {
        for each object in the scene
        {
            determine closest ray object/intersection;
        }
        if intersection exists {
            for each light in the scene {
                if the light is not in shadow of another object
                {
                    add this light contribution to computed color;
                }
            }
        }
        Final color = Final color + computed color * previous reflection factor;
        reflection factor = reflection factor * surface reflection property;
        increment depth;
    } until reflection factor is 0 or maximum depth is reached;
}

```

### Steps:

The first ray we shoot from the eye into the scene is called a primary ray,
visibility ray, or camera ray.

1. check if the ray hits an object 
2. find out how much light it receives by throwing
another ray (called shadow rays) from the hit point to the scene's light

Or:

1. Scanning the screen
1. casting rays for good
1. The closest intersection
1. Sphere-Ray intersection
1. Lighting our intersection point
1. Lambert
1. Reflection
1. Phong
1. Antialiasing

### Light reflection:

### Ray tracing intuition

- Problems:
    - Where does a ray intersect a scene object ?
    - Do shadow rays intersect other objects before they hit the light source ?
    - How does the surface reflect light (diffuse,specular) ?
    - How far away is the light source ?
    - Where is the camera ?

- Color of points Factors:
    1. Incoming light: Distance to object, Angle to direction of light
        - determine if object is visible to light source (shadow ray)
    2. Reflection: Color of an object, Material, Dull objects deffuse, shiny surfaces: specular
    3. Camera position

- Spotlight intensity: appearance
- Diffuse: controls roghness/dullness of object
- Specular: controls shinningness

### Light rays

- Direct illumination
- Indirect illumination: Light bounding off of other objects in the scene
    - Reflected ray
- Refraction
- Ambiant: Color alone
- Specular + Diffuse: How surface responds to light

### Ray object intersection

- the intersection of a ray and a line in 2D
    - C: camera point + viewing direction
    - P: pixel in the image line (image plane) (where we have our normal x,y on our screen)
    - I: point of the intersection in the scene (where we would calculate intersactions)
    - Math used: slope-intercept form of a line (System of equations of 2 line equations)
- the intersection of a ray and a line in 3D
    - Math used: parametric function R(t)=(1-t)C+tP where:
        - t is a number and C and P and I that is R(t) have x,y
- How do we intersect a ray with a triangle ?

- We pick a Camera position (C) x,y,z and a viewing direction
- Image plane perpendicular to the viewing direction
- Now the intersection point is I=R(t)=(1-t)C+tP where points have x,y,z
- Implicit equation of a line: ax+by+c=0  <> Delta y * x - Delta x * y + i Delta x = 0
- Implicit equation of a plane: ax+by+cz+d=0 
- n Vector that is normal => perpendicular to a plane of ax+by+cz=d, a is a vector on the plane: gives us n.a=0 (dot product)

aIx+bIy+cIz+d=0
I=R(t)=(1-t)C+tP

- How to compute coords of I in the plane: we get equations of Ix,Iy,Iz by t, then Iy,Iz by Ix, then we replace in plane equation to get the I coords

- How to tell if the point is inside/on or outside the triangle??
- Math used: weighted averages of three points, I=aA+bB+cC, where a,b,c are the weights, we know I,A,B,C so if one or two of the weights is negative then I is outside the triangle

______


## Resources

### Videos

- [Easy explaination](https://www.youtube.com/watch?v=bN8AV_x4BXI)
- [UC Davis Ray Tracing Lecture](https://www.youtube.com/watch?v=Ahp6LDQnK4Y)

### Tutorials


- [Khan academy course: Basics and the Mathematics of rendering](https://www.khanacademy.org/partner-content/pixar/rendering/rendering1/v/rendering-1)

- [Udacity course: Interactive 3D Graphics](https://classroom.udacity.com/courses/cs291)

- [A Ray Tracer - Part 1](https://www.purplealienplanet.com/node/20)
- [A Ray Tracer - Part 2](https://www.purplealienplanet.com/node/23)

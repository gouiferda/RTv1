# RTv1

Ray tracer in C

## To do

- [X] Author file
- [X] Minilibx expose properly (mlx_expose_hook)
- [ ] Functions and structures 
    - [X] point/vector
    - [X] ray
    - [X] color
    - [X] light
    - [X] object
    - [ ] object types: properties and intersection
        - [ ] sphere
        - [ ] plane
        - [ ] cylinder
        - [ ] cone
- [ ] Light works on fixed and moved objects
    - [ ] ambiant light
    - [ ] diffusion: lambert diffuse model
    - [ ] specular: blinn specular model
- [ ] Shadows
- [ ] Multi objects and intersections
    - [ ] spheres
    - [ ] plane
    - [ ] cylinder
    - [ ] cone
- [ ] Moving and rotating the objects
- [ ] Moving and rotating the camera
- [ ] Norm & Handle errors and leaks and messages
- [ ] Bonuses: Shine effect, Multi lights (spots)

______

## Notes

### Pseudo code:

```
For each pixel {
    determine viewing direction
    intersect ray with scene
    compute illumination
    tore result in pixel
}
```
Or:

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
    1. Reflection: Color of an object, Material, Dull objects deffuse, shiny surfaces: specular
    1. Camera position

- Spotlight intensity: appearance
- Diffuse: controls roghness/dullness of object
- Specular: controls shinningness

![Img](https://i.imgur.com/9yEmvmn.png)

### Light rays

- Direct illumination
- Indirect illumination: Light bounding off of other objects in the scene
    - Reflected ray
- Refraction
- Ambiant: Color alone
- Specular + Diffuse: How surface responds to light

- Shading model: diffuse + specular reflection

### Ray object intersection

#### Detect

- Know if the ray interesetcs a plane in 3D:

- Substituting line values x, y and z into the equation of the sphere gives a quadratic equation of the form: at^2 + bt + c = 0

- Sphere defined by center coords (Xc,Yc,Zc)
- Ray defined by start and direction coords (X1,Y1,Z1) (X2,Y2,Z2), and radius R

- First find the values of the coefficients  a, b  and  c:

- a = (X2 − X1)^2 + (Y2 − Y1)^2 + (Z2 − Z1)^2
- b = − 2[(X2 − X1)(Xc − X1) + (Y2 − Y1)(Yc − Y1) + (Zc − Z1)(Z2 − Z1)]
- c = (Xc − X1)^2 + (Yc − Y1)^2 + (Zc − Z1)^2 − R^2

- Condition for intersection: 	b2 − 4ac > 0
- Condition for tangency: 	b2 − 4ac = 0
- No intersection when: 	b2 − 4ac < 0

#### Points of intersection

- The solution for  t  is: 	t=(-b±sqrt(b^2-4ac))/2a

- Ray given by parametric form is:
- x = x1 + (x2 − x1)t
- y = y1 + (y2 − y1)t
- z = z1 + (z2 − z1)t

- t1=(-b+sqrt(b^2-4ac))/2a
- t2=(-b-sqrt(b^2-4ac))/2a

- Therefor the coords of the intersections points are:
    - for point 1:
        - x = x1 + (x2 − x1)*t1
        - y = y1 + (y2 − y1)*t1
        - z = z1 + (z2 − z1)*t1
    - for point 2:
        - x = x1 + (x2 − x1)*t2
        - y = y1 + (y2 − y1)*t2
        - z = z1 + (z2 − z1)*t2

______


## Resources

### Videos

- [Easy explaination](https://www.youtube.com/watch?v=bN8AV_x4BXI)
- [UC Davis Ray Tracing Lecture](https://www.youtube.com/watch?v=Ahp6LDQnK4Y)

### Tutorials

- [Khan academy course: Basics and the Mathematics of rendering](https://www.khanacademy.org/partner-content/pixar/rendering/rendering1/v/rendering-1)
- [Udacity course: Interactive 3D Graphics](https://classroom.udacity.com/courses/cs291)


### Useful links

- [Intersection of a line and a sphere](http://www.ambrsoft.com/TrigoCalc/Sphere/SpherLineIntersection_.htm)
- [A Ray Tracer - Part 1](https://www.purplealienplanet.com/node/20)
- [A Ray Tracer - Part 2](https://www.purplealienplanet.com/node/23)

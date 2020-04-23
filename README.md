# RTv1

## To do

- [X] Author file
- [X] Minilibx expose properly (mlx_expose_hook)
- [ ] Functions and structures 
    - [ ] vector
    - [ ] ray
    - [ ] color
    - [ ] sphere
    - [ ] plane
    - [ ] cylinder
    - [ ] cone
    - [ ] camera
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

#### Color of points Factors

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


______


## Resources

### Videos

- [Easy explaination](https://www.youtube.com/watch?v=bN8AV_x4BXI)
- [Lecture](https://www.youtube.com/watch?v=Ahp6LDQnK4Y)

### Tutorials

- [Khan academy course](https://www.khanacademy.org/partner-content/pixar/rendering/rendering1/v/rendering-1)
- [A Ray Tracer - Part 1](https://www.purplealienplanet.com/node/20)
- [A Ray Tracer - Part 2](https://www.purplealienplanet.com/node/23)

# RTv1

Ray tracer in C

## To do

- [X] Author file
- [X] Minilibx functions: including expose properly (mlx_expose_hook)
- [ ] Functions and structures 
    - [X] vector
    - [X] ray
    - [X] figure
    - [ ] light
    - [ ] color
    - [ ] material
- [ ] Figures intersection with ray
    - [X] sphere
    - [X] plane
    - [ ] cylinder
    - [ ] cone
- [ ] Light works on fixed and moved objects - Multi objects and intersections
    - [ ] ambiant light
        - [X] sphere
        - [X] plane
        - [ ] cylinder
        - [ ] cone
    - [ ] diffusion: lambert diffuse model
    - [ ] specular: blinn specular model
- [ ] Shadows
- [ ] Moving and rotating the objects
- [ ] Moving and rotating the camera
- [ ] Norm & Handle errors and leaks and messages
- [ ] Bonuses: Shine effect, Multi lights (spots)

- [ ] Extras: Antialiasing, External files for scene description, Reflection,• Transparency, Shadow according to transparency, Textures


## Key definitions

- Ambiant: Color alone of the object
- Diffuse: controls roghness/dullness of object
- Specular: controls shinningness
- Specular + Diffuse: How surface responds to light
- Indirect illumination: Light bounding off of other objects in the scene (Reflected rays)
- Shading model: diffuse + specular reflection

## Helpful links

- Vectors

- Ray tracing explained

https://www.canva.com/design/DAD4I2tioJs/Gq5G-MR2jv_SpXNCVrlxjg/view?utm_content=DAD4I2tioJs&utm_campaign=designshare&utm_medium=link&utm_source=viewer

- Sphere line intersection

http://www.ambrsoft.com/TrigoCalc/Sphere/SpherLineIntersection_.htm

- Plane line intersection

http://pi.math.cornell.edu/~froh/231f08e1a.pdf
https://rosettacode.org/wiki/Find_the_intersection_of_a_line_with_a_plane#C

# Hmza to do
- research on ray tracing and vectors
- look for cylinder/line intersection
- look for cone/line  intersection
- research on how to add specular and diffuse mode
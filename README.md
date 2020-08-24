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
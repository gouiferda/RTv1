# RTv1

Ray tracer in C

## 🚀 Clone and Run

gcl https://github.com/gouiferda/RTv1.git;
cd RTv1;
make run;

## 📝 To do

- [X] Author file
- [X] Minilibx functions: including expose properly (mlx_expose_hook)
- [ ] Functions and structures 
    - [X] vector
    - [X] ray
    - [X] figure
    - [ ] camera
    - [ ] light
    - [ ] material (color , diffuse and specular/shiningness)
- [X] Mapping the coords system (0,0,0) to screen (0,0)
- [ ] Light works on fixed and moved objects - Multi objects and intersections
    - [ ] ambiant light / intersection with ray
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
- [ ] Extra Bonuses: Antialiasing, External files for scene description, Reflection, Transparency, Shadow according to transparency...

## ✅ Steps

1. [X] Scanning the screen
1. [X] casting rays for good
1. [X] The closest intersection
1. [X] Sphere-Ray intersection
1. [X] Plane-Ray intersection
1. [ ] Cylinder-Ray intersection
1. [ ] Cone-Ray intersection
1. [ ] Lighting our intersection point
1. [ ] Lambert
1. [ ] Reflection
1. [ ] Phong
1. [ ] Antialiasing


## 🗺 Key definitions

- Ambiant: Color alone of the object
- Diffuse: controls roghness/dullness of object
- Specular: controls shinningness
- Specular + Diffuse: How surface responds to light
- Indirect illumination: Light bounding off of other objects in the scene (Reflected rays)
- Shading model: diffuse + specular reflection

## 🔗 Helpful links

### Ray tracing explained

- [Easy explaination](https://www.youtube.com/watch?v=bN8AV_x4BXI)
- [Khan academy course: Basics and the Mathematics of rendering](https://www.khanacademy.org/partner-content/pixar/rendering/rendering1/v/rendering-1)
- [Udacity course: Interactive 3D Graphics](https://classroom.udacity.com/courses/cs291)
- [Ray tracing 1](https://www.canva.com/design/DAD4I2tioJs/Gq5G-MR2jv_SpXNCVrlxjg/view?utm_content=DAD4I2tioJs&utm_campaign=designshare&utm_medium=link&utm_source=viewer)
- [A Ray Tracer - Part 1](https://www.purplealienplanet.com/node/20)
- [A Ray Tracer - Part 2](https://www.purplealienplanet.com/node/23)


### Ray/Line intersection with figures/objects
- [Intersection of a Line and a sphere](http://www.ambrsoft.com/TrigoCalc/Sphere/SpherLineIntersection_.htm)
- [Intersection of a Line and a Plane 1](https://www.youtube.com/watch?v=_W3aVWsMp14)
- [Intersection of a Line and a Plane 2](https://rosettacode.org/wiki/Find_the_intersection_of_a_line_with_a_plane#C)
- [Intersection of a Line and a Plane 3](http://pi.math.cornell.edu/~froh/231f08e1a.pdf)


## 👨🏻‍💻 Hamza to do
Research:
- [ ] ray tracing
- [ ] vectors
Do a test for:
- [ ] cylinder/line intersection
- [ ] cone/line intersection
- [ ] create maps json parser (External files for scene description)
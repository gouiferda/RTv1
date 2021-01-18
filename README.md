# RTv1 - Let there be light

Ray tracer in C

## 🚀 Clone and Run

cd ~/Desktop;
gcl https://github.com/gouiferda/RTv1.git;
cd RTv1;
make run;

## 📝 To do

- [X] Minilibx functions
- [ ] expose properly (mlx_expose_hook)
- [X] Functions and structures 
    - [X] vector
    - [X] ray
    - [X] figure (sphere,plane,cylinder,cone)
    - [ ] camera
    - [ ] light
- [X] Mapping the coords system (0,0,0) to screen (0,0)
- [X] ambiant light / intersection with ray
    - [X] sphere
    - [X] plane
    - [ ] cylinder
    - [ ] cone
- [X] diffusion: lambert diffuse model
- [ ] specular: blinn specular model
- [ ] Shadows
- [ ] Moving and rotating the objects
- [ ] Moving and rotating the camera
- [ ] Norm & Handle errors and leaks and messages


- [ ] Multi lights (spots)
- [ ] Reflection
- [ ] Extra Bonuses: Antialiasing, External files for scene description, Reflection, Transparency, Shadow according to transparency...


- [X] Research/learn about: ray tracing and vectors in maths
- [X] Do a test and understand: plane line intersection

- [ ] cylinder/line intersection
- [ ] cone/line intersection

- [ ] Antialiasing
- [ ] create YML maps parser (Read External files for scene description)


## 🗺 Key definitions

- Ambiant: Color alone of the object
- Diffuse: controls roghness/dullness of object
- Specular: controls shinningness (noticable in : metal , marbles)
- Specular + Diffuse: How surface responds to light
- Indirect illumination: Light bounding off of other objects in the scene (Reflected rays)
- Shading model: diffuse + specular reflection


**Lambert: (Diffuse)**

To caluclate the color we need:
1. surface normal (intersection point - center of sphere) normalized
1. direction to the light (light pos - intersection point) normalized
1. do a dot product 
1. refelective color of the sphere

each rgb has from 0 to 1
color = (l.n) x light.intensity x color of figure rgb 
color = (L.N) x M diff x color of figure rgb 
L: Ray towards light direction
N: normal at hit pos,
M diffuse: material's diffuse coeficcient // how much the figure is absorbing light / 1 max 0 min
C object: color of object
Dot product should not be negative


**Blinn-Phong shading model: (Specular shading)**

Phong_term = (V.R)^k

V- Ray towards viewer
R- Light ray reflexted direction
k - Material's specular coefficient (shininess)
(L: intersection to light, N normal, R referse of L : reflection, V intersection to viewer ray to point)
Dot product should not be negative

Half way vector:

H = L + V
H = norm (H)

Blinn term = (H.R)^k

Material: 
- Color:base color
- Ambient: what color it reflects in ambient light
- Diffuse: what color it reflect in diffuse light
- Specular: what is the color of its specular hihglight


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

###  Shading / Diffuse mat shading

- [Ray Tracing: shading](https://www.youtube.com/watch?v=mZvPv7i9E18)
- [Building a Ray Tracer in Python](https://www.youtube.com/watch?v=fu_LuFU7iFo)







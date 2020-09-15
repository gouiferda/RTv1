
#include <stdio.h>
#include <math.h>


# define PLANE 1
# define SPHERE 2
# define CYLINDER 3
# define CONE 4

# define NEAR			1e-6
# define FAR			1000000
//# define MIN_NBR 		1e-4
# define MIN_NBR 1e-4



typedef struct		s_vector
{
	double 			x;
	double 			y;
	double 			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		pos;
	t_vector		dir;
}					t_ray;

typedef struct s_figure
{
	int type;
	float  radius;
	t_vector		pos;
	t_vector		dir;
	int color;
	double specular; // (value between 0–1)
	double diffuse; // (value between 0–1)
	double reflection;
} t_figure;




t_vector newVect(double x, double y,double z);
t_vector		vectScale(t_vector a, double x);
t_vector		vectNorm(t_vector a);
t_vector		vectAdd(t_vector a, t_vector b);
t_vector		vectSub(t_vector a, t_vector b);
t_vector		vectCross(t_vector a, t_vector b);
double		vectDot(t_vector a, t_vector b);
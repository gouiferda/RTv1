/* A simple ray tracer */

#include <stdio.h>
#include <stdbool.h> /* Needed for boolean datatype */

/* Width and height of out image */
#define WIDTH  800
#define HEIGHT 600

/* The vector structure */
typedef struct{
      float x,y,z;
}vector;

/* The sphere */
typedef struct{
        vector pos;
        float  radius;
}sphere; 

/* The ray */
typedef struct{
        vector start;
        vector dir;
}ray;

/* Subtract two vectors and return the resulting vector */
vector vectorSub(vector *v1, vector *v2){
	vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z };
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(vector *v1, vector *v2){
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}


/* Check if the ray and sphere intersect */
bool intersectRaySphere(ray *r, sphere *s){
	
	/* A = d.d, the vector dot product of the direction */
	float A = vectorDot(&r->dir, &r->dir); 
	
	/* We need a vector representing the distance between the start of 
	 * the ray and the position of the circle.
	 * This is the term (p0 - c) 
	 */
	vector dist = vectorSub(&r->start, &s->pos);
	
	/* 2d.(p0 - c) */  
	float B = 2 * vectorDot(&r->dir, &dist);
	
	/* (p0 - c).(p0 - c) - r^2 */
	float C = vectorDot(&dist, &dist) - (s->radius * s->radius);
	
	/* Solving the discriminant */
	float discr = B * B - 4 * A * C;
	
	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 */
	if(discr < 0)
		return false;
	else
		return true;
}

/* Output data as PPM file */
void saveppm(char *filename, unsigned char *img, int width, int height){
	/* FILE pointer */
	FILE *f;

	/* Open file for writing */
	f = fopen(filename, "wb");

	/* PPM header info, including the size of the image */
	fprintf(f, "P6 %d %d %d\n", width, height, 255);

	/* Write the image data to the file - remember 3 byte per pixel */
	fwrite(img, 3, width*height, f);

	/* Make sure you close the file */
	fclose(f);
}

int main(int argc, char *argv[]){
	
	/* Image data */
	unsigned char img[3*WIDTH*HEIGHT];

	/* Our ray and a sphere */
	sphere s;
	ray r;
	
	/* x, y for screen 'resolution' */
	int x,y;	

	/* Intersect ray/sphere or not */
	bool hit;

	/* Position the sphere */
	s.pos.x = 200;
	s.pos.y = 200;
	s.pos.z = 100;

	/* Sphere radius */
	s.radius = 100;

	/* Direction of the ray */
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;

	/* Start position of the ray, z coordinate */
	r.start.z = 0;

	/* Iterate over every pixel of our screen */
	for(y=0;y<HEIGHT;y++){
		/* Set the y-coordinate of the start position of the ray */
		r.start.y = y; 
		for(x=0;x<WIDTH;x++){
			/* Set the x-coordinate of the start position of the ray */
			r.start.x = x;

			/* Check if the ray intersects with the shpere */
			hit = intersectRaySphere(&r, &s);
			if(hit){
				img[(x + y*WIDTH)*3 + 0] = 255;
				img[(x + y*WIDTH)*3 + 1] = 0;
				img[(x + y*WIDTH)*3 + 2] = 0;
			}else{
				img[(x + y*WIDTH)*3 + 0] = 0;
				img[(x + y*WIDTH)*3 + 1] = 0;
				img[(x + y*WIDTH)*3 + 2] = 0;
			}
		}
	}

	saveppm("image.ppm", img, WIDTH, HEIGHT);

	return 0;
}

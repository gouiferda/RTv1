#include <stdio.h>
#include <math.h>

#define WIDTH 1000  
#define HEIGHT 1000

typedef struct {
    float x, y, z;
} vector;

float vectorDot(vector *v1, vector *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void writeppm(char *filename, unsigned char *img, int width, int height){
    FILE *f;
    f = fopen(filename, "w");
    fprintf(f, "P6 %d %d %d\n", width, height, 255);
    fwrite(img, 3, width*height, f);
    fclose(f);
}

float check_ray(px, py, pz, dx, dy, dz, r) {
    vector v1 = {px, py, pz};
    vector v2 = {dx, dy, dz};
    float det, b;
    b = -vectorDot(&v1, &v2);
    det = b*b - vectorDot(&v1, &v1) + r*r;

    if (det<0)
        return -1;

    det = sqrtf(det);
    float t1 = b - det;
    float t2 = b + det;

    return t1;
}

int main(void) {
    unsigned char img[WIDTH*HEIGHT*3];
    int distToPlane;
    float cameraY, cameraZ, cameraX, pixelWorldX, pixelWorldY, pixelWorldZ, amp, rayX, rayY, rayZ;
    for (int px = 0; px<WIDTH; px++) {
        for (int py = 0; py<HEIGHT; py++) {
            distToPlane = 100;
            pixelWorldX = distToPlane;
            pixelWorldY = (px - WIDTH / 2) / WIDTH;
            pixelWorldZ = (py - HEIGHT / 2) / WIDTH;

            rayX = pixelWorldX - cameraX;
            rayY = pixelWorldY - cameraY;
            rayZ = pixelWorldZ - cameraZ;

            amp = 1/sqrtf(rayX*rayX + rayY*rayY + rayZ*rayZ);
            rayX *= amp;
            rayY *= amp;
            rayZ *= amp;

            if (check_ray(50, 50, 50, rayX, rayY, rayZ, 50)) {
                img[(py + px*WIDTH)*3 + 0] = 0;
                img[(py + px*WIDTH)*3 + 1] = 0;
                img[(py + px*WIDTH)*3 + 2] = 128;
            }
            else {
                img[(py + px*WIDTH)*3 + 0] = 255;
                img[(py + px*WIDTH)*3 + 1] = 255;                                 
                img[(py + px*WIDTH)*3 + 2] = 255;
            }
        }
    }
    writeppm("image.ppm", img, WIDTH, HEIGHT);
}
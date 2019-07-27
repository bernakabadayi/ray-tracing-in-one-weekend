#include <iostream>
#include "vec3.h"
#include <fstream>
#include "time.h"
#include "ray.h"
#include "hitable.h"
#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"
#include <omp.h>


using namespace std;

vec3 color(ray r, hitable* world, int depth);
vec3 random_in_unit_sphere();
hitable *random_scene();

int main() {

    clock_t start = clock();
    int nx = 800;
    int ny = 400;
    int ns = 100;
    ofstream out("output.ppm");
    out << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    float R = cos(M_PI/4);
    hitable* list[4];
   // list[0] = new sphere(vec3(0,0,-1),0.5, new lambertian(vec3(0.8,0.3,0.3))); // middle
   // list[1] = new sphere(vec3(0,-100.5,-1),100, new lambertian(vec3(0.8,0.8,0.8))); //ground
   // list[2] = new sphere(vec3(1,0,-1),0.5, new metal(vec3(0.8,0.6,0.2), 0.1)); //right
   // list[3] = new sphere(vec3(-1,0,-1),0.5, new dielectric(1.5)); // left

    hitable* world = new hitablelist(list,4);
    world = random_scene();

    vec3 lookfrom = vec3(13,2,3);
    vec3 lookat = vec3(0,0,0);
    float dist_to_focus = 10; // (lookfrom - lookat).length();
    float aperture = 0.1;


    camera cam(lookfrom,lookat,vec3(0,1,0),20, float(nx)/float(ny), aperture, dist_to_focus);
    // ohne = 11sn
    #pragma omp parallel for collapse(2)
    for(int j = ny -1; j>= 0; j--)
    {
        for(int i = 0; i < nx; i++)
        {   
            vec3 col(0.0,0.0,0.0);
            for (int s = 0; s < ns; ++s)
            {
                // generate random number 0 <= ran < 1.
                float u = float(i+ drand48()) / float(nx);
                float v = float(j+ drand48()) / float(ny);

                ray r = cam.get_ray(u, v);
                vec3 p = r.point_at_parameter(2.0);
                col+= color(r, world, 0);
            }
            col /= ns;
            // Gamma correction with gamma 2, raising the color to the power 1/gamma
            col = vec3(sqrt(col[0]),sqrt(col[1]),sqrt(col[2]));
            int ir = int(255.99* col[0]);
            int ig = int(255.99* col[1]);
            int ib = int(255.99* col[2]);

            out << ir << " " << ig << " " << ib << endl;
        }

        cout << j << endl;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}

//linear blend
vec3 color(ray r, hitable* world, int depth)
{
    hit_record rec;
    if(world->hit(r,0.001,MAXFLOAT,rec))
    {
        ray scattered;
        vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        {
            return attenuation * color(scattered, world, depth+1);
        }
        else
        {
            return vec3(0,0,0);
        }
    }
    else
    {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5* (unit_direction.y() + 1.0);
        return (1.0-t)*vec3(1.0,1.0,1.0) + t*vec3(0.5,0.7,1.0);
    }
}

// rejection method: x^2+y^2≤1
vec3 random_in_unit_sphere()
{
    vec3 p;
    do {
        p = 2.0*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    }
    while (p.squared_length() >= 1);
    return p;
}

hitable *random_scene()
{
    int n = 500;
    hitable ** list = new hitable*[n+1];
    list[0] = new sphere(vec3(0,-1000,0),1000, new lambertian(vec3(0.5,0.5,0.5)));
    int i = 1;

    for (int a = -11; a <11; ++a)
    {
        for (int b = -11; b < 11; ++b) {
            float choose_mat = drand48();
            vec3 center(a+0.9*drand48(), 0.2, b+0.9*drand48());
            if((center-vec3(4, 0.2,0)).length() > 0.9)
            {
                if(choose_mat < 0.8) // diffuse material
                {
                    list[i++] = new sphere(center, 0.2, new lambertian(vec3(drand48()* drand48(),drand48()* drand48(),drand48()* drand48() )));
                }
                else if(choose_mat < 0.95)// metal
                {
                    list[i++] = new sphere(center, 0.2, new metal(vec3(0.5* (1+drand48()),0.5* (1+drand48()),0.5* (1+drand48()) ), 0.5*drand48()));
                } else
                {
                    list[i++] = new sphere(center,0.2, new dielectric(1.5));
                }
            }

        }
    }

    list[i++] = new sphere(vec3(0,1,0),1.0, new dielectric(1.5));
    list[i++] = new sphere(vec3(-4,1,0),1.0, new lambertian(vec3(0.4,0.2,0.1)));
    list[i++] = new sphere(vec3(4,1,0),1.0, new metal(vec3(0.7,0.6,0.5),0.0));

    return new hitablelist(list,i);

}

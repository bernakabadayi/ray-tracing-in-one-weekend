#include <iostream>
#include "vec3.h"
#include <fstream>
#include "time.h"
#include "ray.h"
#include "hitable.h"
#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"

using namespace std;

vec3 color(ray r, hitable* world);
vec3 random_in_unit_sphere();

int main() {

    clock_t start = clock();
    int nx = 800;
    int ny = 400;
    int ns = 100;
    ofstream out("output.ppm");
    out << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    hitable* list[2];
    list[0] = new sphere(vec3(0,0,-1),0.5);
    list[1] = new sphere(vec3(0,-100.5,-1),100);
    hitable* world = new hitablelist(list,2);
    camera cam;

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
                col+= color(r, world);
            }
            col /= ns;
            // Gamma correction with gamma 2, raising the color to the power 1/gamma
            col = vec3(sqrt(col[0]),sqrt(col[1]),sqrt(col[2]));
            int ir = int(255.99* col[0]);
            int ig = int(255.99* col[1]);
            int ib = int(255.99* col[2]);

            out << ir << " " << ig << " " << ib << endl;
        }
    }
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}

//linear blend
vec3 color(ray r, hitable* world)
{
    hit_record rec;
    if(world->hit(r,0,MAXFLOAT,rec))
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color(ray(rec.p, target - rec.p),world);
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
    do{
        p = 2.0*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    }
    while (p.squared_length() >= 1);
    return p;
}

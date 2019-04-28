//
// Created by Berna Kabadayi on 09.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H
#define RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H


#include "vec3.h"
#include "ray.h"

class camera {
    public:
        camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist){ // vfov is top to bottom in degrees
            lens_radius = aperture/2;
            float theta = vfov* M_PI/180;
            float half_height = tan(theta/2);
            float half_width = aspect *half_height;

            origin = lookfrom;
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup,w));
            v = cross(w,u);
            lower_left_corner = vec3(-half_width,-half_height,-1.0);
            lower_left_corner = origin - half_width*focus_dist*u - half_height*focus_dist*v - w*focus_dist;
            horizontal = 2*half_width*focus_dist*u;
            vertical = 2*half_height*focus_dist*v;
        }

        ray get_ray(float s,float t);
        vec3 random_in_unit_disk();

        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 u,v,w;
        float lens_radius;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H

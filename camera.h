//
// Created by Berna Kabadayi on 09.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H
#define RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H


#include "vec3.h"
#include "ray.h"

class camera {
    public:
        camera(){
            origin = vec3(0.0,0.0,0.0);
            lower_left_corner = vec3(-2.0,-1.0,-1.0);
            horizontal = vec3(4.0,0.0,0.0);
            vertical = vec3(0.0,2.0,0.0);
        }

        ray get_ray(float u,float v) { return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin); }

        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_CAMERA_H

//
// Created by Berna Kabadayi on 03.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_RAY_H
#define RAY_TRACING_IN_ONE_WEEKEND_RAY_H


#include "vec3.h"

// ray function p(t) = A + B*t, which gives 3D position along a line 3D

class ray {

    public:
        ray(){}
        ray(const vec3& a , const vec3& b){ A = a; B = b ;}
        vec3 origin() const { return A; }
        vec3 direction() const { return B; }
        vec3 point_at_parameter(float t){return A + t*B ;}

        vec3 A;
        vec3 B;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_RAY_H

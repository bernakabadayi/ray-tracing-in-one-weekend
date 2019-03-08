//
// Created by Berna Kabadayi on 09.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_HITABLE_H
#define RAY_TRACING_IN_ONE_WEEKEND_HITABLE_H

#include "vec3.h"
#include "ray.h"

struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const  = 0;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_HITABLE_H

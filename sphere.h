//
// Created by Berna Kabadayi on 09.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_SPHERE_H
#define RAY_TRACING_IN_ONE_WEEKEND_SPHERE_H


#include "hitable.h"

class sphere : public hitable{
    public:

    sphere() {}
    sphere(vec3 cen, float r): center(cen), radius(r) {};
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

    vec3 center;
    float radius;


};


#endif //RAY_TRACING_IN_ONE_WEEKEND_SPHERE_H
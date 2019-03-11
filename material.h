//
// Created by Berna Kabadayi on 11.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H
#define RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H


#include "ray.h"
#include "hitable.h"

// material​ will tell us how rays interact with the surface
class material {
    public:
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};


#endif //RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H

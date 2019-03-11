//
// Created by Berna Kabadayi on 11.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_METAL_H
#define RAY_TRACING_IN_ONE_WEEKEND_METAL_H


#include "material.h"

struct hit_record;

class metal : public material
{
    public:
        metal(const vec3& a, float f) : albedo(a)
        {
            if (f < 1)
                fuzz = f;
            else
                fuzz = 1;
        }
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
        vec3 reflect(const vec3& v, const vec3& n) const;

        vec3 albedo;
        float fuzz;
};


#endif //RAY_TRACING_IN_ONE_WEEKEND_METAL_H

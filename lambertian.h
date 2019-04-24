//
// Created by Berna Kabadayi on 11.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_LAMBERTIAN_H
#define RAY_TRACING_IN_ONE_WEEKEND_LAMBERTIAN_H


#include "material.h"
// diffuse(matte) material
class lambertian : public material {
    public:
        lambertian(const vec3& a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec,vec3& attenuation, ray& scattered) const;
        vec3 albedo;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_LAMBERTIAN_H

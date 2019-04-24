//
// Created by Berna Kabadayi on 24.04.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_DIELECTRIC_H
#define RAY_TRACING_IN_ONE_WEEKEND_DIELECTRIC_H


#include "material.h"

class dielectric : public material {
    public:
        dielectric(float ri): ref_idx(ri) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
        bool refract(const vec3& v,const vec3& n, float ni_over_nt, vec3& refracted) const;
        vec3 reflect(const vec3& v, const vec3& n) const;
        float schlink(float cosine, float ref_idx) const ;

        float ref_idx;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_DIELECTRIC_H

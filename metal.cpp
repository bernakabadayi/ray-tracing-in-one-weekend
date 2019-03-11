//
// Created by Berna Kabadayi on 11.03.19.
//

#include "metal.h"

bool metal::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
{
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation = albedo;

    return (dot(scattered.direction(),rec.normal) > 0);
}

vec3 metal::reflect(const vec3 &v, const vec3 &n) const
{
    return v - 2 * dot(v,n) * n;
}

//
// Created by Berna Kabadayi on 11.03.19.
//

#include "lambertian.h"

vec3 random_in_unit_sphere();

bool lambertian::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
{
    vec3 target = rec.p + rec.normal + random_in_unit_sphere(); //target is 3d point
    scattered = ray(rec.p, target - rec.p);
    attenuation = albedo;

    return true;
}


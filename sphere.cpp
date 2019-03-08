//
// Created by Berna Kabadayi on 09.03.19.
//

#include "sphere.h"

// t*t*dot(B​ ,​ B​ )​ + 2*t*dot(B​ ,A-​ ​C​) + dot(A​ -C,A​-​C​) - R*R = 0
bool sphere::hit(const ray &r, float t_min, float t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(),r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc,oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if(discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant) ) / (2.0*a);
        if(temp < t_max && temp > t_min)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            vec3 p_c = rec.p - center;
            rec.normal = p_c / radius;
            return true;

        }
        temp = (-b + sqrt(discriminant) ) / (2.0*a);
        if(temp < t_max && temp > t_min)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            vec3 p_c = rec.p - center;
            rec.normal = p_c / radius;
            return true;
        }

    }

    return false;
}
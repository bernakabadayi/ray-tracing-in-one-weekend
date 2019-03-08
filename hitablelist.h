//
// Created by Berna Kabadayi on 09.03.19.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_HITABLELIST_H
#define RAY_TRACING_IN_ONE_WEEKEND_HITABLELIST_H


#include "hitable.h"

// class for list of objects

class hitablelist : public hitable{
    public:
        hitablelist() {}
        hitablelist(hitable** l, int n): list(l), list_size(n) {};
        virtual bool hit(const ray& r,float t_min, float t_max, hit_record& rec) const;

        hitable **list;
        int list_size;

};


#endif //RAY_TRACING_IN_ONE_WEEKEND_HITABLELIST_H

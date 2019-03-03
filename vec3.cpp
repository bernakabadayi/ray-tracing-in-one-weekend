//
// Created by Berna Kabadayi on 31.01.19.
//

#include "vec3.h"

inline std::istream& operator>>(std::istream &is, vec3 &t ){
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3 &t ){
    os << t.e[0] << t.e[1] << t.e[2];
    return os;
}

void vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;

}

vec3 &vec3::operator+=(const vec3 &v2) {
    e[0] += v2.e[0];
    e[1] += v2.e[1];
    e[2] += v2.e[2];

    return *this;
}

vec3 &vec3::operator-=(const vec3 &v2) {
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];

    return *this;
}

vec3 &vec3::operator*=(const vec3 &v2) {
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];

    return *this;
}

vec3 &vec3::operator/=(const vec3 &v2) {
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];

    return *this;
}

vec3 &vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;

    return *this;
}

vec3 &vec3::operator/=(const float t) {
    float k = 1.0/t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;

    return *this;
}

// vector - vector
inline vec3 operator+(const vec3& v1, const vec3& v2)
{
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2]+ v1.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3& v1 , const vec3 &v2)
{
    return vec3(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]* v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0]/v2.e[0], v1.e[1]/v2.e[1], v1.e[2]/v2.e[2]);
}

// vector - constant

inline vec3 operator*(float t, const vec3& v)
{
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator/(vec3& v, float t)
{
    return vec3(v.e[0]/t, v.e[1]/t, v.e[1]/t);
}

inline vec3 operator*(const vec3& v, float t)
{
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline float dot(const vec3& v1, const vec3& v2)
{
    return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2];
}
inline vec3 cross(const vec3& v1, const vec3& v2)
{
    float e0 = v1.e[1]* v2.e[2] - v1.e[2]* v2.e[1];
    float e1 = v1.e[0]* v2.e[2] - v1.e[2]* v2.e[0];
    float e2 = v1.e[0]* v2.e[1] - v1.e[1]* v2.e[0];
    return vec3(e0, -e1, e2);
}

inline vec3 unit_vector(vec3& v)
{
    return v / v.length();
}
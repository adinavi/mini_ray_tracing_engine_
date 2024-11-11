
#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray {
public:
    Vector3 origin, direction;
    Ray(const Vector3& o, const Vector3& d) : origin(o), direction(d) {}
    Vector3 at(double t) const { return origin + t * direction; }
};

#endif

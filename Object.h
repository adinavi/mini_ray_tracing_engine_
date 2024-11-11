
#ifndef OBJECT_H
#define OBJECT_H

#include "Ray.h"
#include "Vector3.h"

class Object {
public:
    virtual bool intersect(const Ray& ray, double& t) const = 0;
};

#endif

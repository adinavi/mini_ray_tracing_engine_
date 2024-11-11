
#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "Vector3.h"

class Sphere : public Object {
public:
    Vector3 center;
    double radius;
    Sphere(const Vector3& c, double r) : center(c), radius(r) {}
    
    bool intersect(const Ray& ray, double& t) const override {
        Vector3 oc = ray.origin - center;
        double a = dot(ray.direction, ray.direction);
        double b = 2.0 * dot(oc, ray.direction);
        double c = dot(oc, oc) - radius * radius;
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) return false;
        t = (-b - sqrt(discriminant)) / (2.0 * a);
        return true;
    }
};

#endif

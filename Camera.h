
#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"
#include "Ray.h"

class Camera {
public:
    Vector3 origin;
    double field_of_view;

    Camera(const Vector3& o, double fov) : origin(o), field_of_view(fov) {}
    Ray getRay(double u, double v) const {
        Vector3 direction(u, v, -1); // Simplified direction
        return Ray(origin, direction);
    }
};

#endif

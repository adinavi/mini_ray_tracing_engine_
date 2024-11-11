
#ifndef RENDERER_H
#define RENDERER_H

#include "Scene.h"
#include "Camera.h"
#include "Vector3.h"
#include <iostream>
#include <limits>

class Renderer {
public:
    int width, height;

    Renderer(int w, int h) : width(w), height(h) {}

    Vector3 traceRay(const Ray& ray, const Scene& scene) {
        double t_closest = std::numeric_limits<double>::infinity();
        Object* closest_object = nullptr;

        // Find the closest intersection
        for (const auto& obj : scene.objects) {
            double t = 0;
            if (obj->intersect(ray, t) && t < t_closest) {
                t_closest = t;
                closest_object = obj;
            }
        }

        // If no object is hit, return background color
        if (!closest_object) return Vector3(0.5, 0.7, 1.0);  // Background color

        // Lighting and shading
        Vector3 hit_point = ray.at(t_closest);
        Vector3 normal = (hit_point - static_cast<Sphere*>(closest_object)->center).normalize();

        // Ambient lighting
        Vector3 ambient = 0.1 * Vector3(1, 1, 1); // White ambient light

        // Diffuse lighting
        Vector3 light_dir = Vector3(-1, -1, -1).normalize(); // Directional light source
        double diff = std::max(dot(normal, light_dir), 0.0);
        Vector3 diffuse = diff * Vector3(1, 1, 1); // White diffuse light

        // Specular lighting
        Vector3 view_dir = (Vector3(0, 0, 0) - hit_point).normalize();
        Vector3 reflect_dir = reflect(-light_dir, normal);
        double spec = pow(std::max(dot(view_dir, reflect_dir), 0.0), 32);
        Vector3 specular = 0.5 * spec * Vector3(1, 1, 1); // White specular light

        return ambient + diffuse + specular; // Combine lighting components
    }

    void render(const Scene& scene, const Camera& camera) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                double u = double(x) / (width - 1);
                double v = double(y) / (height - 1);
                Ray ray = camera.getRay(u, v);
                Vector3 color = traceRay(ray, scene);
                // Rendering to console as RGB values between 0-255
                std::cout << static_cast<int>(255.999 * color.x) << " "
                          << static_cast<int>(255.999 * color.y) << " "
                          << static_cast<int>(255.999 * color.z) << "\n";
            }
        }
    }

private:
    Vector3 reflect(const Vector3& v, const Vector3& n) const {
        return v - 2 * dot(v, n) * n;
    }
};

#endif

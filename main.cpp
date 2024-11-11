
#include "Ray.h"
#include "Camera.h"
#include "Object.h"
#include "Sphere.h"
#include "Scene.h"
#include "Renderer.h"
#include <iostream>

int main() {
    // Initialize the scene
    Scene scene;
    
    // Add objects to the scene
    Sphere sphere(Vector3(0, 0, -5), 1.0, Color(1, 0, 0)); // Red sphere
    scene.addObject(&sphere);
    
    // Set up the camera
    Camera camera(Vector3(0, 0, 0), 90);
    
    // Render the scene
    Renderer renderer(800, 600);
    renderer.render(scene, camera);
    
    return 0;
}

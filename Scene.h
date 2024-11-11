
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.h"

class Scene {
public:
    std::vector<Object*> objects;
    
    void addObject(Object* obj) { objects.push_back(obj); }
};

#endif

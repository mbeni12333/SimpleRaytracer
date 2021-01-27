#ifndef __SCENE__H_
#define __SCENE__H_

#include "Core.h"
#include "light.h"

struct Scene{
    Camera camera;
    struct Sphere* objects;
    Light* lights;
    int size;
    int nbLights;
    unsigned int width;
    unsigned int height;
};



#endif
#ifndef __SCENE__H_
#define __SCENE__H_

#include "Core.h"

struct Scene{
    Camera camera;
    struct Sphere* objects;
    int size;
    unsigned int width;
    unsigned int height;
};



#endif
#ifndef __OBJECTS__H_
#define __OBJECTS__H_

#include "Core.h"

struct Ray{
    Point origin;
    Vec3 direction;
};

struct Sphere{

    Vec3 position;
    Color color;
    double radius;

    Point& intersect(const Ray& ray){
        return position;
    }
};



#endif
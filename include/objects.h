#ifndef __OBJECTS__H_
#define __OBJECTS__H_

#include "Core.h"
#include <iostream>
#include "material.h"

struct Ray{
    Point origin;
    Vec3 direction;

    Ray(Point o,  Vec3 d){
        origin = o;
        direction = d/d.norm();
    }
};

struct Sphere{

    Vec3 position;
    Material material;
    double radius;

    double intersect(Ray* ray){

        Vec3 sphereToRay =  ray->origin - position;
        //std::cerr << sphereToRay.x << " " << sphereToRay.y << " " << sphereToRay.z << std::endl;

        double b = ray->direction*sphereToRay *2;
        double c = sphereToRay * sphereToRay - radius*radius;
        double delta = b*b - 4*c;
        double dist = -1.0f;

        if(delta >= 0){
            //std::cerr << "DELTA POSITIF : "<< delta << std::endl;
            dist = (double)(-b + sqrt(delta))/2.0f;

            if(dist > 0){
                return dist;
            }
        }

        return -1;
    }

    Vec3 normal(Point hit_point){
        
        Vec3 nrml = (hit_point - position);
        nrml = nrml/nrml.norm();

        return nrml;
    }
};



#endif
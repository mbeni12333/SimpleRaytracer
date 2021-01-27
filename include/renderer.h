#ifndef __RENDERER__H_
#define __RENDERER__H_

#include "Core.h"
#include "scene.h"
#include "objects.h"
#include "image.h"


double findNearest(Scene* scene, Ray& ray, Sphere* sphere);
Color colorAt(Scene* scene,const Point& rayIntersection, Sphere& sphere);
Color rayTrace(Scene* scene, Ray* ray);
image_t* renderScene(Scene* scene);



        //unsigned char* begin = renderImage->buff;
        //unsigned char* end = renderImage->buff + height*width - 1;
 
        //for(unsigned char* i = begin; i < end; i += height){
        //    unsigned char* end2 = i+height;

        //    x = xmin + deltaX* 
        //    for(unsigned char* j = i; j < end2; j++){
        //        Ray ray = {camera, Point(x, y, z)}
        //    }
        //}
    //}





#endif
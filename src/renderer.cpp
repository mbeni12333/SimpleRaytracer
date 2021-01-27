#include "renderer.h"
#include "image.h"
#include <iostream>

double findNearest(Scene* scene, Ray* ray, Sphere** sphere){

    double dist_min = 1000000000.0f;
    double dist = -1.0f;

    Sphere* objects = scene->objects;

    for(Sphere* i=objects; i<(objects+scene->size) ; i++){
        dist = i->intersect(ray);
        //std::cout << "dist : " << dist << std::endl;
        if(dist == -1.0f) continue;

        if(dist < dist_min){
            dist_min = dist;
            *sphere = i;
            //std::cerr << "WHAAAAAAAAAAAAAAAAATT" << std::endl;
        }
    }

    return dist_min == 1000000000.0f ? -1: dist_min ;
}

Color colorAt(Scene* scene, Point hitPoint, Vec3 hitNormal, Sphere* sphere){
    //std::cout << sphere->color.x;
    Material material = sphere->material;
    Color objColor = material.base;
    Vec3 to_cam = scene->camera - hitPoint;
    int specular_k = 50;

    Color color = Color({0.0f, 0.0f, 0.0f})*material.ambient;
    
    for(int i=0; i<scene->nbLights; i++){
        Ray to_light = Ray({hitPoint, (scene->lights[i]).position - hitPoint});
        

        // diffuse shadding lambert
        double tmp = hitNormal*to_light.direction;
        //std::cout << "BEFORE : " << color.x << color.y << color.z << std::endl;
        color = color + objColor*material.diffuse*MAX(tmp, 0.0f);
        //std::cout << "AFTER : " << color.x << color.y << color.z << std::endl;
        // specular Blinn-Phong
        Vec3 halfVector = (to_light.direction + to_cam);
        halfVector = halfVector/halfVector.norm();
        tmp = pow(hitNormal*halfVector, specular_k);
        //std::cout << tmp << std::endl;
        color = color + (scene->lights[i]).color*material.specular*MAX(tmp, 0);

        if(color.x > 255){
            color.x = 255;
        }
        if(color.y > 255){
            color.y = 255;
        }
        if(color.z > 255){
            color.z = 255;
        }
    }

    //std::cout << color.x << color.y << color.z << std::endl;
    return color;
}

Color rayTrace(Scene* scene, Ray* ray){

    Color color({0.0f, 0.0f, 0.0f});

    Sphere* sphere = nullptr;
    double dist = findNearest(scene, ray, &sphere);

    if(sphere == nullptr){
        return color;
    }

    //std::cout << "NOT NULL" ;

    Point rayIntersection = ray->direction*dist + ray->origin;
    Vec3 intersecTionNormal = sphere->normal(rayIntersection);

    color += colorAt(scene, rayIntersection, intersecTionNormal, sphere);
    //std::cout << color.x << " " << color.y << " " << color.z << std::endl;
    return color;
}

image_t* renderScene(Scene* scene){


         
    int height = scene->height;
    int width = scene->width;
    float aspectRatio = ((float)width)/((float)height);

    float xmin = -1.0f;
    float xmax = +1.0f;
    float deltaX = (float)(xmax-xmin)/(float)(width - 1);

    float ymin = -1.0f/ aspectRatio;
    float ymax = +1.0f/ aspectRatio;
    float deltaY = (float)(ymax-ymin)/(float)(height - 1);

    Camera camera = scene->camera;

    image_t* renderImage = createImage(width, height);

    

    for(int i=0; i<height; i++){
        float y = ymin + deltaY*i;
        for(int j=0; j<width; j++){
            float x = xmin + deltaX*j;

            Ray ray(camera, Point({x, y, 0.0f}) - camera);
            //std::cerr << "origin:" <<  ray.origin.x <<" " << ray.origin.y <<" " <<ray.origin.z << std::endl;

            (renderImage)->buff[i*width+j] = rayTrace(scene, &ray);

        }
    }

    return renderImage;
}



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

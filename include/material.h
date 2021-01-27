#ifndef __MATERIAL__H_
#define __MATERIAL__H_


#include "Core.h"

typedef struct Material{
    Color base;
    double diffuse;
    double specular;
    double ambient;
}Material;



 #endif
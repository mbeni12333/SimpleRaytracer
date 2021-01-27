#ifndef __CORE__H_
#define __Core__H_

#include <stdlib.h>
#include <math.h>

struct Vec3 {

    double x, y, z; // position components


    double norm(){
        // euclidean norm
        return sqrt(pow(x, 2) + pow(y, 2) + + pow(z, 2));
    }

    Vec3& operator + (const Vec3& v){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x + v.x;
        v_out->y = y + v.y;
        v_out->z = z + v.z;

        return *v_out;
    }
    Vec3& operator * (double k){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x*k;
        v_out->y = y*k;
        v_out->z = z*k; 

        return *v_out;
    }
    Vec3& operator / (int k){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x/k;
        v_out->y = y/k;
        v_out->z = z/k;

        return *v_out;
    }
    double operator * (const Vec3& v){
        // dot product
        return x*v.x + y*v.y + z*v.z ;
    }

};

typedef struct Vec3 Vec3;

Vec3& operator * (const Vec3& v, double k){return v*k;}
Vec3& operator / (const Vec3& v, double k){return v*k;}



 #endif
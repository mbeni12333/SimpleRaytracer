#ifndef __VECTOR__H_
#define __VECTOR__H_

#include <stdlib.h>
#include <math.h>

typedef struct Vec3 Vec3;


struct Vec3 {

    double x, y, z; // position components


    double norm(){
        // euclidean norm
        return sqrt(x*x + y*y + z*z);
    }


    Vec3 operator += (Vec3 v){

        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Vec3 operator - (Vec3 v){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x - v.x;
        v_out->y = y - v.y;
        v_out->z = z - v.z;

        return *v_out;
    }

    Vec3 operator + (Vec3 v){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x + v.x;
        v_out->y = y + v.y;
        v_out->z = z + v.z;

        return *v_out;
    }
    Vec3 operator * (double k){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x*k;
        v_out->y = y*k;
        v_out->z = z*k; 

        return *v_out;
    }
    const Vec3 operator / (double k){
        Vec3* v_out = (Vec3*) malloc(sizeof(Vec3));

        v_out->x = x/k;
        v_out->y = y/k;
        v_out->z = z/k;

        return *v_out;
    }
    double operator * (Vec3 v){
        // dot product
        return x*v.x + y*v.y + z*v.z ;
    }

};



//Vec3& operator * (const Vec3& v, double k){return v*k;}
//Vec3& operator  / (const Vec3& v, double k){return v*k;}



 #endif
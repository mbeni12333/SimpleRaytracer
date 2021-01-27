#include <iostream>
#include <random>

#include "Core.h"
#include "image.h"
#include "renderer.h"
#include "scene.h"
#include "objects.h"
#include "time.h"
#include "light.h"
#include "material.h"


#define NB_OBJECTS 40
#define NB_LIGHTS 1

int main(int argc, char* argv[]){
    srand(0);
    Camera camera({.0f, .0f, -5.0f});

    Sphere objects[NB_OBJECTS];
    Light lights[NB_LIGHTS];

    for(int i=0; i<NB_OBJECTS; i++){

        double x_rand = ((double) rand() / (RAND_MAX))*2.0f - 1.0f;
        double y_rand = ((double) rand() / (RAND_MAX))*1.2f - 0.6f; 
        double z_rand = ((double) rand() / (RAND_MAX))*1.0f; 

        double r_rand = rand()%256;
        double g_rand = rand()%256;
        double b_rand = rand()%256;



        double radius = ((double) rand() / (RAND_MAX))*0.1;


        Material material({{r_rand, g_rand ,b_rand},
                           1.0f, .3f, 0.05f});


        objects[i] = Sphere({{x_rand, y_rand, z_rand}, material,radius});
    }

    for(int i=0; i<NB_LIGHTS; i++){

            double x_rand = ((double) rand() / (RAND_MAX))*5.0 - 2.5f;
            double y_rand = ((double) rand() / (RAND_MAX))*5.0 - 2.5f; 
            double z_rand = ((double) rand() / (RAND_MAX))*10.0; 

            lights[i] = Light({{1.5f, -0.5f, 10.0f},
                                {255.0f, 255.0f, 255.0f}});
        }

    Scene scene({camera, objects, lights, NB_OBJECTS, NB_LIGHTS, WIDTH, HEIGHT});

    

    image_t* out = renderScene(&scene);

    saveImage(argv[1], out);

    return 0;
}
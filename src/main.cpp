#include <iostream>
#include <random>

#include "Core.h"
#include "image.h"
#include "renderer.h"
#include "scene.h"
#include "objects.h"
#include "time.h"

#define NB_OBJECTS 30

int main(int argc, char* argv[]){
    srand(time(NULL));
    Camera camera({.0f, .0f, -5.0f});

    Sphere objects[NB_OBJECTS];

    for(int i=0; i<NB_OBJECTS; i++){

        double x_rand = ((double) rand() / (RAND_MAX))*1.5f - 0.75f;
        double y_rand = ((double) rand() / (RAND_MAX))*1.0f - 0.5f; 
        double z_rand = ((double) rand() / (RAND_MAX))*1.0f; 

        double r_rand = rand()%256;
        double g_rand = rand()%256;
        double b_rand = rand()%256;

        double radius = ((double) rand() / (RAND_MAX))*0.1;

        objects[i] = Sphere({{x_rand, y_rand, z_rand},
                             {r_rand, g_rand, b_rand},
                              radius});
    }

    Scene scene({camera, objects, NB_OBJECTS, WIDTH, HEIGHT});

    

    image_t* out = renderScene(&scene);

    saveImage(argv[1], out);

    return 0;
}
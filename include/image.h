#ifndef IMAGE_
#define IMAGE_

#define VAL(img,i,j) (img)->buff[(i)*(img)->w+(j)]

#include "Core.h"

typedef struct{

	unsigned long w; // largeur en pixels
	unsigned long h; // hauteur en pixels
	char *path; // le chemin absolu du fichier correspondant
	Color *buff; // w x h octets correspondant aux pixels

} image_t;

image_t *createImage(int width, int height);
/*image_t *copyImage(image_t *src);*/
int saveImage(char *fileName, image_t *img);
// image_t *loadImage(char *fileName);
void destructImage(image_t *p);

#endif
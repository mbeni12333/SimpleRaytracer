#ifndef IMAGE_
#define IMAGE_

#define VAL(img,i,j) (img)->buff[(i)*(img)->w+(j)]

typedef struct{

	unsigned long w; // largeur en pixels
	unsigned long h; // hauteur en pixels
	char *path; // le chemin absolu du fichier correspondant
	unsigned char *buff; // w x h octets correspondant aux pixels

} image_t;

image_t *createImage();
image_t *copyImage(image_t *src);
int saveImage(char *fileName, image_t *img);
// image_t *loadImage(char *fileName);
void destructImage(image_t *p);

#endif
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "image.h"


image_t *createImage(){
    // Creates an empty image

    image_t* p;
    p = (image_t*) malloc(sizeof (image_t));
    p->w = 0;
    p->h = 0;
    p->path = NULL;
    p->buff = NULL;

	return p;
}

image_t *copyImage(image_t *src){
    // Create copy of image
    image_t* p = createImage();
    p->w = src->w;
    p->h = src->h;
    p->path = strdup(src->path);
    p->buff = (unsigned char*) malloc(sizeof (unsigned char)*(src->w*src->h));
    memcpy(p->buff,src->buff, sizeof (unsigned char)*(src->w*src->h));

	return p;
}


int saveImage(char *fileName, image_t *img){

	FILE* file = fopen(fileName, "w");

	fprintf(file, "P2\n");
	fprintf(file, "%lu %lu\n", img->w, img->h);
	fprintf(file, "%u\n", 255);

    unsigned char* begin = img->buff;
    unsigned  char* end = img->buff + (img->h)*(img->w) - 1;

    for(unsigned char* i = begin; i < end; i += img->w){

        unsigned char* end2 = i+img->w;

        for(unsigned char* j = i; j < end2; j++){
            fprintf(file, "%hhu " , *j);
        }
    }
    /*
	for(int i = 0; i < img->h; i++){
		for(int j = 0; j < img->w -1 ; j++){
			fprintf(fichier, "%hhu " , VAL(img, i, j));
		}
		fprintf(fichier, "%hhu\n" , VAL(img, i, j));	
	}
    */

	fclose(file);

	return 1;
}


void detruire_image(image_t *p){
    // Destruct image
	if(p){
		free(p->path);
		free(p->buff);
		free(p);
	}
}



/*
char* skipComments(FILE* file, char *tmp_str){
    // Skip comments from the file
	while(fgets(tmp_str, TMP_STR_SIZE, file) && tmp_str[0] == '#');
	return tmp_str;
}

image_t *loadImage(char *fileName){
	

	FILE *file; // pointeur vers le fichier;
	unsigned int nb_niveaux_gris ;
	char tmp_str[TMP_STR_SIZE];
	//enum format {BIN, ASCII} pgm_form;

	// creation de l'image
	image_t* p = createImage();
	p->path = strdup(fileName);
	// ouverture du fichier
	file = fopen(fileName, "r");
	if(!file){
		fprintf(stderr, "Erreur fichier innexistant");
		destructImage(p);
		fclose(file);
		return NULL;
	}
	// lecture de la premiere ligne du fichier
	fgets(tmp_str, TMP_STR_SIZE, file);

	if(!strncmp(tmp_str, "P2", 2)){
		// traitement pour le format ASCII
		//pgm_form = ASCII;

		skipComments(file, tmp_str);

		// lecture de W et H
		if(sscanf(tmp_str, "%lu %lu\n", &(p->w), &(p->h)) != 2){
			fprintf(stderr, "Erreur de lecture W = %lu, H = %lu", p->w, p->h);
			destructImage(p);
			fclose(file);
			return NULL;			
		}
	

		skipComments(file, tmp_str);

		// lecture du niveaux de gris

		if(sscanf(tmp_str, "%u", &nb_niveaux_gris) == 1){
			if(nb_niveaux_gris != 255){
				fprintf(stderr, "Erreur niveau gris non supportee");
				destructImage(p);
				fclose(file);
				return NULL;
			}

		}else{
			fprintf(stderr, "Erreur lecture de niveaux_gris");
			destructImage(p);
			fclose(file);
			return NULL;
		}
		// tout marche bien , on commence par lire les valeur des pixels
		int i, j;
		// allocation del'espace necessaire
		p->buff = (unsigned char*)malloc(sizeof(unsigned char)*p->w*p->h);

		if(!p->buff){
			fprintf(stderr, "Erreur d'allocation de buffer");
			destructImage(p);
			fclose(file);
			return NULL;
		}
		// lecture des pixels
		for(i = 0; i < p->h;i++){
			for(j = 0; j < p->w; j++){
				fscanf(file, " %hhu ", &VAL(p, i, j));
			}
		}

		fclose(file);

	}else if(!strncmp(tmp_str, "P5", 2)){
		// traitement format binaire
		//pgm_form = BIN;
        skipComments(file, tmp_str);

		// lecture de W et H
		if(sscanf(tmp_str, "%lu %lu\n", &(p->w), &(p->h)) != 2){
			fprintf(stderr, "Erreur de lecture W = %lu, H = %lu", p->w, p->h);
			destructImage(p);
			fclose(file);
			return NULL;			
		}
	

		skipComments(file, tmp_str);

		// lecture du niveaux de gris

		if(sscanf(tmp_str, "%u", &nb_niveaux_gris) == 1){
			if(nb_niveaux_gris != 255){
				fprintf(stderr, "Erreur niveau gris non supportee");
				destructImage(p);
				fclose(file);
				return NULL;
			}

		}else{
			fprintf(stderr, "Erreur lecture de niveaux_gris");
			destructImage(p);
			fclose(file);
			return NULL;
		}
		// tout marche bien , on commence par lire les valeur des pixels

		// allocation del'espace necessaire
		p->buff = (unsigned char*)malloc(sizeof(unsigned char)*p->w*p->h);

		if(!p->buff){
			fprintf(stderr, "Erreur d'allocation de buffer");
			destructImage(p);
			fclose(file);
			return NULL;
		}
		// lecture des pixels
		fread(p->buff, sizeof(unsigned), p->w*p->h, file);

		fclose(file);


	}else{

		fprintf(stderr, "Erreur enum format ");
		destructImage(p);
		fclose(file);
		return NULL;

	}

	return p;
}
*/

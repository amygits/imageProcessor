
/** 
* Purpose:
*
* Completion time: 
* 
* @author Amy Ma
* @version 08/28/2021
*
*/

#include "BmpProcessor.h"


/////////////////////////////////////////////////////////////
//  Function definitions

/*
 * Creates struct BMP_Header
 * @return pointer to new BMP_Header struct
 */
struct BMP_Header* init_BMP_Header() {
    
    struct BMP_Header *h = calloc(1, sizeof*h);
    return h;
    
}

/*
 * Creates struct DIB_Header
 * @return pointer to new DIB_Header struct
 */
struct DIB_Header* init_DIB_Header() {
    
    struct DIB_Header *h = calloc(1, sizeof*h);
    return h;
    
}
/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header) {
    
    printf("\nStarting BMPHeader read..\n");
    fread(&header->signature, sizeof(char) * 2, 1, file);
    //printf(">signature read success..\n");
    fread(&header->size, sizeof(int), 1, file);
    //printf(">size read success..\n");
    fread(&header->reserved1, sizeof(short), 1, file);
    //printf(">reserved1 read success..\n");
    fread(&header->reserved2, sizeof(short), 1, file);
    //printf(">reserved2 read success..\n");
    fread(&header->offset_pixel_array, sizeof(int), 1, file);
    //printf(">offset_pixel_array read success..\n");
    
    /*printf("signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("size: %d\n", header->size);
    printf("reserved1: %d\n", header->reserved1);
    printf("reserved2: %d\n", header->reserved2);
    printf("offset: %d\n", header->offset_pixel_array);*/
    printf("BMPHeader read Success\n");
}

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header) {
    
    printf("\nStarting BMPHeader write..\n");
    fwrite(&header->signature, sizeof(char) * 2, 1, file);
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->reserved1, sizeof(short), 1, file);
    fwrite(&header->reserved2, sizeof(short), 1, file);
    fwrite(&header->offset_pixel_array, sizeof(int), 1, file);
    printf("BMPHeader write complete\n");
}

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header) {
    
    printf("Starting DIB Header read..\n");
    //header = (DIB_Header*) malloc(sizeof(DIB_Header));
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->width, sizeof(int), 1, file);
    fread(&header->height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(short), 1, file);
    fread(&header->bits_per_pix, sizeof(short), 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->image_size, sizeof(int), 1, file);
    fread(&header->x_pix_per_m, sizeof(int), 1, file);
    fread(&header->y_pix_per_m, sizeof(int), 1, file);
    fread(&header->colors, sizeof(int), 1, file);
    fread(&header->impColors, sizeof(int), 1, file);
    /*printf("size: %d\n", header->size);
    printf("width: %d\n", header->width);
    printf("height: %d\n", header->height);
    printf("planes:: %d\n", header->planes);
    printf("bits_per_pix: %d\n", header->bits_per_pix);
    printf("compression: %d\n", header->compression);
    printf("image_size: %d\n", header->image_size);
    printf("x_pix_per_m: %d\n", header->x_pix_per_m);
    printf("y_pix_per_m: %d\n", header->y_pix_per_m);
    printf("colors: %d\n", header->colors);
    printf("impColors: %d\n", header->impColors);*/
    printf("DIB Header read Success\n");
}

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header) {
    
    printf("Starting DIB Header write..\n");
    //header = (DIB_Header*) malloc(sizeof(DIB_Header));
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->width, sizeof(int), 1, file);
    fwrite(&header->height, sizeof(int), 1, file);
    fwrite(&header->planes, sizeof(short), 1, file);
    fwrite(&header->bits_per_pix, sizeof(short), 1, file);
    fwrite(&header->compression, sizeof(int), 1, file);
    fwrite(&header->image_size, sizeof(int), 1, file);
    fwrite(&header->x_pix_per_m, sizeof(int), 1, file);
    fwrite(&header->y_pix_per_m, sizeof(int), 1, file);
    fwrite(&header->colors, sizeof(int), 1, file);
    fwrite(&header->impColors, sizeof(int), 1, file);
    printf("DIB Header write Success\n");
    
}

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height) {
    
    printf("Making new BMP Header..\n");
    struct BMP_Header *h = header;
    
    h->signature[0] = 'B';
    h->signature[1] = 'M';
    h->size = 69366;
    h->reserved1 = 0;
    h->reserved2 = 0;
    h->offset_pixel_array = 54;
    header = &h;
   printf("Make new BMP Header success\n");
}

 /**
 * Makes new DIB header based on width and height. Useful for converting files from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeDIBHeader(struct DIB_Header* header, int width, int height){
     printf("Making new DIB Header..\n");
    struct DIB_Header *h = header;
    h->size =  sizeof*h;
    h->width = width;
    h->height= height;
    h->planes = 1;
    h->compression = 0;
    h->image_size = 69312;
    h->x_pix_per_m = 3780;
    h->y_pix_per_m = 3780;
    h->colors = 0;
    h->impColors = 0;
    header = &h;
   printf("Make new DIB Header success\n");
}


/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    
    int counter = 0;
    struct Pixel* temp = pArr;
    printf("Entering Read BMP Pixels..\n");
    for (int x = 0; x < width; x++) {
       //printf("entering for layer 1, loop: %d\n", x);
       for (int y = 0; y < height; y++){
           //printf("entering for layer 2, loop: %d\n", y);
           fread(&temp[counter].b, sizeof(char), 1, file);
           //printf("b read success\n");
           fread(&temp[counter].g, sizeof(char), 1, file);
           //printf("g read success\n");
           fread(&temp[counter].r, sizeof(char), 1, file);
           //printf("r read success\n");
           printf("color: B=%d, G=%d, R=%d\n", temp[counter].b, temp[counter].g, temp[counter].r);
           //printf("exiting for layer 2, loop: %d\n", y);
           counter++;
       }
       fseek(file, sizeof(unsigned char) * width, SEEK_CUR);
       //printf("exiting for layer 1, loop: %d\n", x);
   }
   printf("Read BMP Pixels success\n");
    
}


/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    
    int counter = 0;
    struct Pixel* temp = pArr;
    printf("Entering Write BMP Pixels..\n");
    for (int x = 0; x < width; x++) {
       //printf("entering for layer 1, loop: %d\n", x);
       for (int y = 0; y < height; y++){
           //printf("entering for layer 2, loop: %d\n", y);
           fwrite(&temp[counter].b, sizeof(char), 1, file);
           //printf("r write success\n");
           fwrite(&temp[counter].g, sizeof(char), 1, file);
           //printf("g write success\n");
           fwrite(&temp[counter].r, sizeof(char), 1, file);
           //printf("b write success\n");
           printf("color: B=%d, G=%d, R=%d\n", temp[counter].b, temp[counter].g, temp[counter].r);
           //printf("exiting for layer 2, loop: %d\n", y);
           counter++;
       }
       fseek(file, sizeof(unsigned char) * width, SEEK_CUR);
       //printf("exiting for layer 1, loop: %d\n", x);
   }
   printf("Write BMP Pixels success");
}

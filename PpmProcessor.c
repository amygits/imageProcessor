
/** 
* Purpose: Defines PPM header structs and implements read, write functionality for header and pixel body of a specified input file
* Includes make headers for file conversion (between PPM and BMP)
*
*
* Completion time: 2 hours
* 
* @author Amy Ma
* @version 08/28/2021
*
*/

#include "PpmProcessor.h"


/////////////////////////////////////////////////////////////
//  Function definitions

/*
 * Creates struct PPM_Header
 * @return pointer to new PPM_Header struct
 */
struct PPM_Header* init_PPM_Header() {
    
    struct PPM_Header *h = calloc(1, sizeof*h);
    return h;
    
}
/**
 * read PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination PPM header
 */
void readPPMHeader(FILE* file, struct PPM_Header* header){
    
    printf("\nStarting PPMHeader read..\n");
    //fread(&header->signature, sizeof(char) * 2, 1, file);
    fscanf(file, "%2s %u %u %u", &header->signature, &header->width, &header->height, &header->maxval);
    //printf(">signature read success..\n");
    //fread(&header->width, sizeof(unsigned), 1, file);
    //printf(">width read success..\n");
    //fread(&header->height, sizeof(unsigned), 1, file);
    //printf(">height read success..\n");
    //fread(&header->maxval, sizeof(unsigned), 1, file);
    //printf(">maxval read success..\n");
    
    printf("signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("width: %u\n", header->width);
    printf("height: %u\n", header->height);
    printf("maxval: %u\n", header->maxval);
    printf("PPMHeader read Success\n");
}

/**
 * write PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makePPMHeader function

 */
void writePPMHeader(FILE* file, struct PPM_Header* header){
    
    printf("\nStarting PPM Header write..\n");
    fprintf(file, "%2s\n%u %u\n %u\n", header->signature, header->width, header->height, header->maxval);
    //fwrite(&header->signature, sizeof(char) * 2, 1, file);
    //printf(">signature write success..\n");
    //fwrite(&header->width, sizeof(int), 1, file);
    //printf(">width write success..\n");
    //fwrite(&header->height, sizeof(int), 1, file);
    //printf(">height write success..\n");
    //fwrite(&header->maxval, sizeof(unsigned short), 1, file);
    //printf(">maxval write success..\n");
    printf("PPM Header write complete\n");
}

/**
 * make PPM header based on width and height. Useful for converting files from BMP to PPM.
 *
 * @param  header: Pointer to the destination PPM header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makePPMHeader(struct PPM_Header* header, int width, int height){
    
    struct PPM_Header *h = header;
    
    h->signature[0] = 'P';
    h->signature[1] = '6';
    h->height = height;
    h->width = width;
    h->maxval = 225;
    header = h;
   
}

/**
 * read Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for 
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsPPM(FILE* file, struct Pixel** pArr, int width, int height){
    
     printf("Entering Read PPM Pixels..\n");
    int counter = 0;
    struct Pixel* temp = pArr;
   
    for (int x = 0; x < width; x++) {
       //printf("entering for layer 1, loop: %d\n", x);
       for (int y = 0; y < height; y++){
           //printf("entering for layer 2, loop: %d\n", y);
           fscanf(file, "%c", &temp[counter].r);
           fscanf(file, "%c", &temp[counter].g);
           fscanf(file, "%c", &temp[counter].b);
           //printf("b read success\n");
           //printf("g read success\n");
           //printf("r read success\n");
           //printf("color #%d: B=%d, G=%d, R=%d\n", counter, temp[counter].b, temp[counter].g, temp[counter].r);
           //printf("exiting for layer 2, loop: %d\n", y);
           counter++;
       }
       fseek(file, sizeof(unsigned char) * width, SEEK_CUR);
       //printf("exiting for layer 1, loop: %d\n", x);
   }
   
    printf("Read PPM Pixels success\n");
}

/**
 * write Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsPPM(FILE* file, struct Pixel** pArr, int width, int height){
    
    int counter = 0;
    struct Pixel* temp = pArr;
    printf("Entering Write PPM Pixels..\n");
    for (int x = 0; x < width; x++) {
       //printf("entering for layer 1, loop: %d\n", x);
       for (int y = 0; y < height; y++){
           //printf("entering for layer 2, loop: %d\n", y);
           //fprintf(file, "%c\n %c\n %c\n", temp[counter].r, temp[counter].g, temp[counter].b);
           //printf("color #%d: B=%d, G=%d, R=%d\n", counter, temp[counter].b, temp[counter].g, temp[counter].r);
           //printf("exiting for layer 2, loop: %d\n", y);
           counter++;
       }
       fseek(file, sizeof(unsigned char) * width, SEEK_CUR);
       //printf("exiting for layer 1, loop: %d\n", x);
   }    
   printf("Write PPM Pixels success\n");
}


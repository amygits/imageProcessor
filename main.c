
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
#include "PpmProcessor.h"



int main(int argc, char** argv) {
    
    struct Pixel* pixels = init_Pixel();
    
    //Load image files to make copy of
    printf("\n///////////////////////////////////////////\n");
    //FILE* bmpInput1 = fopen("test2.bmp", "rb");
    FILE* ppmInput1 = fopen("nehoymenoy.ppm", "r");
    
    //struct BMP_Header* header_bmp = init_BMP_Header();
    //struct DIB_Header* header_dib = init_DIB_Header();
    //struct PPM_Header* header_ppm = init_PPM_Header();
    
    struct PPM_Header* temp;
    makePPMHeader(temp, 100, 100);
    printf("signature: %c%c\n", temp->signature[0], temp->signature[1]);
    printf("width: %u\n", temp->width);
    printf("height: %u\n", temp->height);
    printf("maxval: %u\n", temp->maxval);
    printf("PPMHeader read Success\n");
    //readBMPHeader(bmpInput1, header_bmp);
    //readDIBHeader(bmpInput1, header_dib);
    //int width = header_dib->width;
    //int height = header_dib->height;
    
    //readPPMHeader(ppmInput1, temp);
    //int width = header_ppm->width;
    //int height = header_ppm->height;   
    //printf("width: %d\nheight: %d\n", width, height);
    //readPixelsPPM(ppmInput1, pixels, width, height);
    
    printf("\n///////////////////////////////////////////\n");
    
    // Manipulate the colors on binary level
    /*int r, g, b;
    r = 10;
    g = 11;
    b = -55;
    colorShiftPixels(pixels, width, height, r, g, b);*/
   
    // Write to files (Save copy)
    //printf("Preparing to write to file....\n");
    //FILE* bmpOutput1 = fopen("output1.bmp", "wb"); //write binary
    //FILE* bmpOutput2 = fopen("output2.bmp", "wb"); //write binary
    FILE* ppmOutput1 = fopen("output1.ppm", "w"); 
    //writeBMPHeader(bmpOutput1, header_bmp);
    //writeDIBHeader(bmpOutput1, header_dib);
    //writePixelsBMP(bmpOutput1, pixels, width, height);
    
    //fclose(bmpInput1);
    //fclose(bmpOutput1);
    
    printf("\n///////////////////////////////////////////\n");
    
    //writePPMHeader(ppmOutput1, header_ppm);
    //writePixelsPPM(ppmOutput1, pixels, width, height);
    
    //close files
    fclose(ppmInput1);
    fclose(ppmOutput1);    
    
    free(pixels);
    //free(header_bmp);
    //free(header_dib);
    
    return (EXIT_SUCCESS);
}


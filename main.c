
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
#include "PixelProcessor.h"
#include "PpmProcessor.h"



int main(int argc, char** argv) {
    
    //Load image files to make copy of
    printf("\n///////////////////////////////////////////\n");
    
    FILE* bmpInput1 = fopen("test2.bmp", "rb");
    //FILE* bmpInput1 = fopen("ttt.bmp", "rb");
    //FILE* bmpInput2 = fopen("wb.bmp", "rb");
    
    struct Pixel* pixels = (struct Pixel*) malloc(sizeof(struct Pixel));
    struct BMP_Header* header_bmp = init_BMP_Header();
    struct DIB_Header* header_dib = init_DIB_Header();
    
    readBMPHeader(bmpInput1, header_bmp);
    readDIBHeader(bmpInput1, header_dib);
    int width = header_dib->width;
    int height = header_dib->height;
    readPixelsBMP(bmpInput1, pixels, width, height);
    //printf("width from header dib: %d\nheight from header dib: %d\n", width, height);
    
    
    // Manipulate the colors on binary level
    int r, g, b;
    r = 10;
    g = 11;
    b = -55;
    colorShiftPixels(pixels, width, height, r, g, b);
    
    // Write to files (Save copy)
    printf("\n///////////////////////////////////////////\n");
    FILE* bmpOutput1 = fopen("output1.bmp", "wb"); //write binary
    //FILE* bmpOutput2 = fopen("output2.bmp", "wb"); //write binary
    
    writeBMPHeader(bmpOutput1, header_bmp);
    writeDIBHeader(bmpOutput1, header_dib);
    writePixelsBMP(bmpOutput1, pixels, width, height);
    
    
    //close files
    fclose(bmpInput1);
    fclose(bmpOutput1);
    
    return (EXIT_SUCCESS);
}


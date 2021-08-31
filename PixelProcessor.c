#include "PixelProcessor.h"


/////////////////////////////////////////////////////////////
//  Function definitions
     /*
 * Creates struct Pixel
 * @return pointer to new Pixel struct
 */ 
struct Pixel* init_Pixel(){
    struct Pixel *h = calloc(1, sizeof*h);
    return h;
}
/**
 * Shift color of Pixel array. The dimension of the array is width * height. The shift value of RGB is 
 * rShift, gShiftï¼ŒbShift. Useful for color shift.
 *
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 * @param  rShift: the shift value of color r shift
 * @param  gShift: the shift value of color g shift 
 * @param  bShift: the shift value of color b shift 
 */
void colorShiftPixels(struct Pixel** pArr, int width, int height, int rShift, int gShift, int bShift) {
    
    int counter = 0;
    struct Pixel* temp = pArr;
    printf("Entering Pixel color shift..\n");
    for (int x = 0; x < width; x++) {
       //printf("entering for layer 1, loop: %d\n", x);
       for (int y = 0; y < height; y++){
           //printf("entering for layer 2, loop: %d\n", y);
           if (rShift != 0) {
                int r = (temp[counter].r) + rShift; 
                //printf("r: %d\n", r );
                if (r > 255) {
                    r = 255;
                } 
                if (r < 0) {
                    r = 0;
                }
                //printf("r: %d\n", r );
                temp[counter].r = r;
           }
           if (bShift != 0) {
               int b = (temp[counter].b) + bShift;
               //printf("b: %d\n", b);
               if (b > 255) {
                    b = 255;
                } 
                if (b < 0) {
                    b = 0;
                }
                temp[counter].b = b;
           }
           if (gShift != 0) {
               int g = (temp[counter].g) + gShift;
               //printf("g: %d\n", g);
               if (g > 255) {
                    g = 255;
                } 
                if (g < 0) {
                    g = 0;
                }
               //printf("g: %d\n", g);
                temp[counter].g = g;
           }
           //printf("color: B=%d, G=%d, R=%d\n", temp[counter].b, temp[counter].g, temp[counter].r);
           //printf("exiting for layer 2, loop: %d\n", y);
           counter++;
       }
       //printf("exiting for layer 1, loop: %d\n", x);
   }
   printf("Pixel color shift success\n");
    
}
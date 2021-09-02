
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
#include <unistd.h>
#include <getopt.h>


int main(int argc, char** argv) {
    
    char* inputfile;
    char* outputfile;
    char* type;
    
    int opt;
    
    int rvalue = 0;
    int gvalue = 0;
    int bvalue = 0;
    
    int oFlag = 0;
    int rFlag = 0;
    int gFlag = 0;
    int bFlag = 0;
    int tFlag = 0;
    
        while((opt = getopt(argc, argv, ":i:o:r:g:b:t:")) != -1){
        switch(opt) {
            case 'i':
                inputfile = optarg;
                break;
            case ':':
                printf("Please enter a file name\n");
                break;
            case 'o':
                oFlag = 1;
                outputfile = optarg;
                //printf("output filename: %s\n", outputfile);
                break;
            case 'r':
                rFlag = 1;
                rvalue = atoi(optarg);
                //printf("r shift: %d", rvalue);
                break;
            case 'g':
                gFlag = 1;
                gvalue = atoi(optarg);
                //printf("g shift: %d", gvalue);
                break;
            case 'b':
                bFlag = 1;
                bvalue = atoi(optarg);
                //printf("b shift: %d", bvalue);
                break;
            case 't':
                tFlag = 1;
                type = optarg;
                //printf("type: %s\n", type);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
        }
    }
    
    printf("filename: %s\n", inputfile);
    printf("oFlag = %d, rFlag = %d, gFlag = %d, bFlag = %d, tFlag = %d\n", oFlag, rFlag, gFlag, bFlag, tFlag);
   printf("Values:\nrshift = %d, gshift = %d, bshift = %d\n", rvalue, gvalue, bvalue);
    for (; optind < argc; optind++){
        printf("Given extra arguments: %s\n", argv[optind]);
    }
    
    int dflen;
    // If inputfile is valid
    if(inputfile != NULL){
        dflen = strlen(inputfile);
        if (dflen >= 5 
                && ((strcmp(&inputfile[dflen - 4], ".bmp") == 0) ||
                (strcmp(&inputfile[dflen - 4], ".ppm") == 0))
                && (access(inputfile, F_OK) != -1)) {
            printf("Opening file %s\n", inputfile);
            FILE* fileImport = fopen(inputfile, "r");
            struct Pixel* pixelBody = init_Pixel();
            int height = 0;
            int width = 0;
            
            //check to see what type of file it is (ppm/bmp) before performing read/write actions
            
            // if bmp, performs read actions
            if (strcmp(&inputfile[dflen - 4], ".bmp") == 0) {
                struct BMP_Header* bmpheader = init_BMP_Header();
                struct DIB_Header* dibheader = init_DIB_Header();
                readBMPHeader(fileImport, bmpheader);
                readDIBHeader(fileImport, dibheader);
                width = dibheader->width;
                height = dibheader->height;
                readPixelsBMP(fileImport, pixelBody, width, height);
            } 
            //if ppm, performs read actions
            if (strcmp(&inputfile[dflen - 4], ".ppm") == 0) {
                struct PPM_Header* ppmheader = init_PPM_Header();
                readPPMHeader(fileImport, ppmheader);
                width = ppmheader->width;
                height = ppmheader->height;
                readPixelsPPM(fileImport, pixelBody, width, height);
            }
            // if any of the r/g/b options are flagged
            if (rFlag == 1 || bFlag == 1 || gFlag == 1) {
                colorShiftPixels(pixelBody, width, height, rvalue, gvalue, bvalue);
            }
            // if output file name is flagged
            if (oFlag == 1){
                //FILE* fileExport = fopen(outputfile, "w");
                //if type == PPM
                
                //else export as BMP
            }
            //
            printf("closing file %s\n", inputfile);
            fclose(fileImport);
        } else {
            printf("Data file has an invalid name or does not exist\n");
            //print_usage();
            exit(1);
        }
    } else { 
        printf("No data file name provided.  This is a required field\n");
        //print_usage();
        exit(1);
    }
    
    return (EXIT_SUCCESS);
}


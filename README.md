# Image Processor
## Simple image processor in C that will read BMP/PPM files with option to apply a pixel color shift "filter" then save a copy of the image.  

Usage: \n./MaImageProcessors -i <input_file_name(char*)> -o <out_file_name>"</br>
"-o exports to output file, optional argument following to specify file name"</br>
"-r, -g, -b refers to color shift options, followed by an integer argument"</br>
"-t followed by options 'PPM' or 'BMP' to specify export file type"</br>

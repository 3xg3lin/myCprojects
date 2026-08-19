#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

int main(){
    FILE* inputFile;
    FILE* outputFile;

    char inputFilename[] = "./input.data";
    char outputFilename[] = "./output.data";

    inputFile = fopen(inputFilename, "r");
    if (NULL == inputFile) {
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    outputFile = fopen(outputFilename, "w");
    if (NULL == outputFile) {
        fprintf(stderr, "input file: %s: %s\n", outputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\"%s\" opened for reading.\n", inputFilename);
    fprintf(stderr, "\"%s\" opened for writing.\n", outputFilename);
    fprintf(stderr, "Do work here.\n");
    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);
    fflush(outputFile);
    fclose(outputFile);
    fprintf(stderr, "Done.\n");
    return 0;
}

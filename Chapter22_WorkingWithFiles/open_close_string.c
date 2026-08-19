#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

int main(){
    FILE* inputFile;   // pointer to a FILE struct; fopen() will fill this in
    FILE* outputFile;  // same, for the output stream

    char inputFilename[] = "./input.data";
    char outputFilename[] = "./output.data";

    // fopen() returns a pointer to a FILE struct on success, or NULL on failure
    inputFile = fopen(inputFilename, "r");   // "r" = open for reading, file must already exist
    if (NULL == inputFile) {
        // errno was set by fopen(); strerror() turns it into a readable message
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    outputFile = fopen(outputFilename, "w");  // "w" = open for writing, creates file or truncates if it exists
    if (NULL == outputFile) {
        fprintf(stderr, "input file: %s: %s\n", outputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\"%s\" opened for reading.\n", inputFilename);
    fprintf(stderr, "\"%s\" opened for writing.\n", outputFilename);

    fprintf(stderr, "Do work here.\n");

    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);    // closes stream, releases the FILE struct
    fflush(outputFile);   // forces buffered data to be written out (fclose would do this anyway)
    fclose(outputFile);

    fprintf(stderr, "Done.\n");
    return 0;
}

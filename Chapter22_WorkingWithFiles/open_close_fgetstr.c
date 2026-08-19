#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno


char* safe_gets(char* buf, int size){
    if (fgets(buf, size, stdin)) {
        for (int i = 0; i < size; i++) {
            if ('\n' == buf[i]) {
                buf[i] = '\0';
                break;
            }
        }
        return buf;
    }
    else {
        return NULL;
    }
}

int main(){
    FILE* inputFile;   // pointer to a FILE struct; fopen() will fill this in
    FILE* outputFile;  // same, for the output stream

    printf( "FILENAME_MAX on this system is %d bytes\n", FILENAME_MAX );

    char* inputFilename = (char*)calloc(FILENAME_MAX, 1);
    char* outputFilename = (char*)calloc(FILENAME_MAX, 1);
    if (!inputFilename || !outputFilename) {
        fprintf(stderr, "FATAL ERROR: Not Enough memory for filename strings\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of input files: ");
    safe_gets(inputFilename, FILENAME_MAX);
    inputFile = fopen(inputFilename, "r");   // "r" = open for reading, file must already exist
    if (NULL == inputFile) {
        // errno was set by fopen(); strerror() turns it into a readable message
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of output file: ");
    safe_gets(outputFilename, FILENAME_MAX);
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
    free(inputFilename);
    free(outputFilename);

    fprintf(stderr, "Done.\n");
    return 0;
}

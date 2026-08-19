#include <stdio.h>
#include <stdlib.h>     // for exit(), calloc(), free()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

// Reads a line from stdin into buf (up to size bytes), and replaces the
// trailing newline with '\0' so the caller doesn't have to deal with it.
// Returns buf on success, NULL if fgets() failed (e.g. EOF/error).
char* safe_gets(char* buf, int size){
    if (fgets(buf, size, stdin)) {          // fgets() keeps the '\n' if it fits
        for (int i = 0; i < size; i++) {
            if ('\n' == buf[i]) {
                buf[i] = '\0';               // strip the newline, terminate string here
                break;
            }
        }
        return buf;
    }
    else {
        return NULL;                        // fgets failed: no input read
    }
}

int main(){
    FILE* inputFile;   // pointer to a FILE struct; fopen() will fill this in
    FILE* outputFile;  // same, for the output stream

    // FILENAME_MAX is a constant from stdio.h: the largest filename size
    // this system guarantees fopen() etc. can handle
    printf( "FILENAME_MAX on this system is %d bytes\n", FILENAME_MAX );

    // calloc() allocates memory on the heap and zero-initializes it
    // (unlike fixed-size arrays used before, this size is decided at runtime)
    char* inputFilename = (char*)calloc(FILENAME_MAX, 1);
    char* outputFilename = (char*)calloc(FILENAME_MAX, 1);

    if (!inputFilename || !outputFilename) {  // calloc() returns NULL if allocation fails
        fprintf(stderr, "FATAL ERROR: Not Enough memory for filename strings\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of input files: ");
    safe_gets(inputFilename, FILENAME_MAX);   // read filename typed by the user

    inputFile = fopen(inputFilename, "r");   // "r" = open for reading, file must already exist
    if (NULL == inputFile) {
        // errno was set by fopen(); strerror() turns it into a readable message
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of output file: ");
    safe_gets(outputFilename, FILENAME_MAX);  // read output filename from user

    outputFile = fopen(outputFilename, "w");  // "w" = open for writing, creates file or truncates if it exists
    if (NULL == outputFile) {
        fprintf(stderr, "input file: %s: %s\n", outputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\"%s\" opened for reading.\n", inputFilename);
    fprintf(stderr, "\"%s\" opened for writing.\n", outputFilename);

    fprintf(stderr, "Do work here.\n");  // placeholder: actual read/write logic goes here

    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);    // closes stream, releases the FILE struct
    fflush(outputFile);   // forces buffered data to be written out (fclose would do this anyway)
    fclose(outputFile);

    // heap memory must be freed manually — unlike the fixed arrays in the earlier version
    free(inputFilename);
    free(outputFilename);

    fprintf(stderr, "Done.\n");
    return 0;
}

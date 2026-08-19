#include <stdio.h>
#include <stdlib.h>     // for exit(), calloc(), free()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

// Reads a line from stdin into buf, removes the trailing '\n'.
// Returns buf on success, NULL on failure.
char* safe_gets(char* buf, int size){
    if (fgets(buf, size, stdin)) {          // read a line, '\n' may be included
        for (int i = 0; i < size; i++) {
            if ('\n' == buf[i]) {
                buf[i] = '\0';               // remove the newline
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

    // allocate filename buffers on the heap, zero-initialized
    char* inputFilename = (char*)calloc(FILENAME_MAX, 1);
    char* outputFilename = (char*)calloc(FILENAME_MAX, 1);

    if (!inputFilename || !outputFilename) {  // calloc() returns NULL on failure
        fprintf(stderr, "FATAL ERROR: Not Enough memory for filename strings\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of input files: ");
    safe_gets(inputFilename, FILENAME_MAX);   // get input filename from user

    inputFile = fopen(inputFilename, "r");   // "r" = open for reading, file must exist
    if (NULL == inputFile) {
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of output file: ");
    safe_gets(outputFilename, FILENAME_MAX);  // get output filename from user

    outputFile = fopen(outputFilename, "w");  // "w" = open for writing, creates/truncates
}

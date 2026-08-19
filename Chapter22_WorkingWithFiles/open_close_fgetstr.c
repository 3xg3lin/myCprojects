#include <stdio.h>
#include <stdlib.h>     // for exit(), calloc(), free()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

// Reads one line from stdin into buf (up to size bytes) and strips the
// trailing newline that fgets() leaves in place, so buf ends up holding
// a clean string with no '\n'.
// Returns buf on success, or NULL if fgets() failed (e.g. EOF was hit
// before any input was read).
char* safe_gets(char* buf, int size){
    if (fgets(buf, size, stdin)) {          // fgets() reads a line, keeps '\n' if it fits
        for (int i = 0; i < size; i++) {
            if ('\n' == buf[i]) {
                buf[i] = '\0';               // overwrite '\n' with the string terminator
                break;                        // stop scanning, nothing left to do
            }
        }
        return buf;
    }
    else {
        return NULL;                        // fgets failed, buf's contents are unreliable
    }
}

int main(){
    FILE* inputFile;   // will hold the pointer fopen() returns for the input stream
    FILE* outputFile;  // same, for the output stream

    // FILENAME_MAX (from stdio.h) is the largest filename size this
    // system guarantees functions like fopen() can handle
    printf( "FILENAME_MAX on this system is %d bytes\n", FILENAME_MAX );

    // Allocate the filename buffers on the heap instead of using fixed
    // arrays, since we don't know the filenames until runtime (user input).
    // calloc() also zero-initializes the memory, so an unfilled buffer is
    // still a valid empty string rather than garbage.
    char* inputFilename = (char*)calloc(FILENAME_MAX, 1);
    char* outputFilename = (char*)calloc(FILENAME_MAX, 1);

    if (!inputFilename || !outputFilename) {  // calloc() returns NULL on allocation failure
        fprintf(stderr, "FATAL ERROR: Not Enough memory for filename strings\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of input files: ");
    safe_gets(inputFilename, FILENAME_MAX);   // read input filename typed by the user

    inputFile = fopen(inputFilename, "r");    // "r" = open for reading, file must already exist
    if (NULL == inputFile) {
        // errno was set by fopen(); strerror() converts it to a readable message
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter name of output file: ");
    safe_gets(outputFilename, FILENAME_MAX);  // read output filename typed by the user

    outputFile = fopen(outputFilename, "w");  // "w" = open for writing, creates file or truncates it if it exists
    if (NULL == outputFile) {
        // fixed: this used to say "input file" — leftover copy-paste bug
        fprintf(stderr, "output file: %s: %s\n", outputFilename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\"%s\" opened for reading.\n", inputFilename);
    fprintf(stderr, "\"%s\" opened for writing.\n", outputFilename);

    fprintf(stderr, "Do work here.\n");  // placeholder: actual read/write logic goes here

    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);    // closes the stream and releases its FILE struct
    fflush(outputFile);   // forces buffered data out immediately (fclose would flush anyway)
    fclose(outputFile);

    // heap-allocated buffers must be freed manually, unlike fixed arrays
    free(inputFilename);
    free(outputFilename);

    fprintf(stderr, "Done.\n");
    return 0;
}

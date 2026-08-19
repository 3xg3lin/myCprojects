#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strerror()
#include <sys/errno.h>  // for errno

// Prints usage message and exits when command-line args are wrong
void usage(char* cmd){
    fprintf(stderr, "usage: %s inputFileName outputFileName\n", cmd);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    FILE* inputFile;   // pointer to a FILE struct; fopen() will fill this in
    FILE* outputFile;  // same, for the output stream

    // argv[0] = program name, argv[1] = input file, argv[2] = output file
    // so argc must be exactly 3
    if (argc != 3) {
        usage(argv[0]);
    }

    // open input file, assign and check for NULL in the same line
    if (NULL == (inputFile = fopen(argv[1], "r"))) {
        fprintf(stderr, "ERROR: input file: %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "%s opened for reading.\n", argv[1]);

    // open output file, same pattern
    if (NULL == (outputFile = fopen(argv[2], "w"))) {
        fprintf(stderr, "ERROR: output file %s: %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "%s opened for writing.\n", argv[2]);

    fprintf(stderr, "Do work here.\n");  // placeholder for the actual read/write logic

    fprintf(stderr, "Closing files.\n");
    fclose(inputFile);    // close input stream
    fflush(outputFile);   // flush output buffer (redundant, fclose flushes too)
    fclose(outputFile);   // close output stream

    fprintf(stderr, "Done.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>       // for getopt
#include <sys/errno.h>    // for errno

void usage(char* cmd){
    fprintf(stderr, "usage: %s [-i inputFileName] [-o outputFileName]\n", cmd);
    fprintf(stderr, "If -i inputFileName is not given," " stdin is used.\n");
    fprintf(stderr, "If -o outputFName is not given," " stdout is used.\n\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[]){
    int ch;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;

    while ((ch = getopt(argc, argv, "i:o:h?")) != -1) {
        switch (ch) {
            case 'i':
                if (NULL == (inputFile = fopen(optarg, "r"))) {
                    fprintf(stderr, "inputFile \"%s\": %s\n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using\"%s\" for input.\n", optarg);
                break;
            case 'o':
                if (NULL == (outputFile = fopen(optarg, "a"))) {
                    fprintf(stderr, "output file \"%s\": %s \n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using\"%s\" for output.\n", optarg);
                break;
            case '?':
            case 'h':
            default:
                usage(argv[0]);
                break;
        }
    }
}

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

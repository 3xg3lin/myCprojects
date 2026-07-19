#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

static char* options_string = "pra:t:y:";

typedef struct _book{
    bool bPublished;
    bool bReprint;
    char* title;
    char* author;
    char* year;
} Book;

void Usage(char* exec){
    printf( "\nUsage: %s -r -p -t 'title' -a 'name' -y year\n\n" , exec );
    exit(1);
}

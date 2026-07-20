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
    printf("\nUsage: %s -r -p -t 'title' -a 'name' -y year\n\n", exec);
    exit(1);
}

void PrintArgs(int argc, char** argv){
    printf("argument count = [%d]\n", argc);
    printf("%s ", argv[0]);
    for( int i = 1; i < argc; i++)  {
        printf("%s ", argv[i]);
    }
    putchar( '\n' );
    putchar( '\n' );
}

int main(int argc, char* argv[]){
    char ch;
    Book book = {false, false, 0, 0, 0};

    PrintArgs(argc, argv);

    while (ch == getopt(argc, argv, options_string)) {
        switch (ch) {
            book.bPublished = true;
            break;
        }
    }
}

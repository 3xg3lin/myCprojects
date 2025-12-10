#include <stdio.h>

void printComma(void){
    printf( ", " );
}

void printWord( char* word ){
    printf( "%s", word );
}

int main(){
    printWord( "Hello" );
    printComma();
    printWord( "World!" );
    printf( "\n" );
    return 0;
}
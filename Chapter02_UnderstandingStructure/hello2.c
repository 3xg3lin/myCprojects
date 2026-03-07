#include <stdio.h>

void printComma(){
    printf( ", " );
    return;
}

int main(){
    printf( "Hello" );
    printComma();
    printf( "World!\n" );
    return 0;
}
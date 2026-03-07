#include <stdio.h>

void printAGreeting( char* aGreeting ){
    printf( "%s", aGreeting );
}

void printAComma( void ){
    printf( ", " );
}

void printAnAddressee( char* aName ){
    printf( "%s", aName );
}

void printANewLine( void ){
    printf( "\n" );
}

void printGreeting( char* aGreeting , char* aName ){
    printAGreeting( aGreeting );
    printAComma();
    printAnAddressee( aName );
    printANewLine();
}

int main(){
    printGreeting( "Hi", "Bub" );
    return 0;
}
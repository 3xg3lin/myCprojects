#include <stdio.h>

// function prototypes
void printGreeting( char* aGreeting , char* aName );
void printAGreeting( char* aGreeting );
void printAnAddressee( char* aName );
void printAComma( void );
void printANewLine( void );

int main(){
    printGreeting( "Hi", "Bub" );
    return 0;
}

void printGreeting( char* aGreeting , char* aName ){
    printAGreeting( aGreeting );
    printAComma();
    printAnAddressee( aName );
    printANewLine();
}

void printAGreeting( char* aGreeting ){
    printf( "%s", aGreeting );
}

void printAnAddressee( char* aName ){
    printf( "%s", aName );
}

void printAComma( void ){
    printf( ", " );
}

void printANewLine( void ){
    printf( "\n" );
}



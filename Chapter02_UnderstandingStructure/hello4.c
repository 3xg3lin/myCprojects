#include <stdio.h>

void printComma( void ){
    printf( ", " );
}

void printWord( char* word ){
    printf( "%s", word );
}

void printGreeting( char* greeting , char* addressee ){
    printWord( greeting );
    printComma();
    printWord( addressee );
    printf( "!\n" );
}

int main(){
    printGreeting( "Hello", "World" );
    printGreeting( "Good Day", "Your Royal Highness" );
    printGreeting( "Howdy", "John Q. and Jane P. Doe" );
    printGreeting( "Hey" , "Allice, Moe and Teddy" );
    return 0;
}
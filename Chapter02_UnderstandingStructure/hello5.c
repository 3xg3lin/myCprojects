#include <stdio.h>

void printGreeting( char* greeting , char* who ){
    printf( "%s , %s!\n" , greeting , who );
}

int main(){
    printGreeting( "Hello", "World" );
    printGreeting( "Good Day", "Your Royal Highness" );
    printGreeting( "Howdy", "John Q. and Jane P. Doe" );
    printGreeting( "Hey" , "Allice, Moe and Teddy" );
    return 0;
}
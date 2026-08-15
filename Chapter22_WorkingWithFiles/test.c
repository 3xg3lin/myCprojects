#include <stdio.h>

int main(){
    unsigned char a = 255;  // converts to -1
    unsigned char b = 254; // converts to -2
    printf("%d \n%d \n",(signed char)a, (signed char)b);
}

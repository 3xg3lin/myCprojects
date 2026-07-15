#include <stdio.h>

int main(void){
    int smallInt = 12;
    int largeInt = 0x7fffffff;  // int32 max
    int negativeInt = -smallInt;
    unsigned anUnsigned = 130;
    long long int reallyLargeInt = 0x7fffffffffffffff;

    printf( " Signed Printf \n"
              "  Name         right        left        zero         right       left\n"
              "              aligned      aligned     filled       minimum     minimum    whatever\n"
              "  Specifier    %%10d        %%-10d       %%-.10d       %%10.3d     %%-10.3d     %%d\n" );
    printf(" ---------  ---------- " " ----------- "
        " ----------- " " ---------- " " ---------- " " ---------\n");

}

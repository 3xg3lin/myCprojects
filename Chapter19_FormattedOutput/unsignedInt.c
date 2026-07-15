#include <stdio.h>

int main(){
    int smallInt = 12;
    int largeInt = (1024*1024*3)+(1024*2)+512+128+64+32+16+8+4+2+1;
    int negativeInt = -smallInt;
    unsigned anUnsigned = 130;

    printf( " Unsigned Printf \n"
              "  Base        Base-8        Base-10         Base-16         BASE-16\n"
              "  Name         octal        unsigned     hexadeximal     HEXADECIMAL\n"
              "  Specifier     %%12o            %%12u            %%12x            %%12X \n" );

}

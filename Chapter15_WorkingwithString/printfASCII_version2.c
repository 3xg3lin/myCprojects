#include <stdio.h>

int main(int argc,char *argv[]){

    printf("| Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex |\n" );
    printf("|-------------|-------------|-------------|\n" );

    char c1 , c2 , c3 , c4;
    for (int i = 0; i < 32; i++){
        c1 = i;
        c2 = i + 32;
        c3 = i + 64;
        c4 = i + 96;
        printf( "|  %c %3d %#x |  %c %3d %#x |  %c %3d %#x |", c2, c2, c2, c3, c3 ,c3 , c4, c4, c4);
        printf("\n");
    }
    return 0;
}

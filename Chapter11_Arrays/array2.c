#include <stdio.h>

int main(){
    int anArray[10] = {0};
    int x,y,z;
    x = 11;
    y = 12;
    z = 13;

    //anArray[11] = 7;    // cause a compiler error
    anArray[x] = 0;       // cause a runtime error
    printf("anArray[%d] = %d", x, anArray[x]);
    return 0;
}

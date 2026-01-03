#include <stdio.h>

long int add( long int i1, long int i2 ){
    return i1 + i2;
}

int main( void ){
    unsigned char b1 = 254;
    unsigned char b2 = 253;
    long int r1;
    r1 = add(b1, b2);
    printf( "%d + %d = %ld\n", b1, b2, r1 );
    return 0;
}

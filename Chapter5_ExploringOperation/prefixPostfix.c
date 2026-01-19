#include <stdio.h>

int main( int argc, char *argv[] ){
    int aValue = 5;
    // Demonstrate prefix incrementation.
    printf( "Initial: %d\n", aValue );
    printf( "Prefix: %d\n", ++aValue );
    printf( "Final: %d\n", aValue );

    aValue = 5;

    // Demonstrate postfix incrementation.
    printf( "Initial: %d\n", aValue );
    printf( "Postfix: %d\n", aValue++);
    printf( "Final: %d\n", aValue );

    // A more predictable result: increment in isolation.
    aValue = 5;
    ++aValue;
    printf( "++aValue (alone) == %d\n", aValue );

    aValue = 5;
    aValue++;
    printf( "aValue++ (alone) == %d\n", aValue );

    return 0;
}

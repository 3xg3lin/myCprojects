#include <stdio.h>

const double inchesPerFoot = 12.0;
const double inchesPerMeter = 39.67;

void printLength( double meters );

int main( void ){
    printLength( 0.0 );
    printLength( 1.0 );
    printLength( inchesPerFoot / inchesPerMeter );
    printLength( 2.5 );
    return 0;
}

void printLength( double meters){
    double feet = meters * inchesPerMeter / inchesPerFoot;
    printf( "Length = %f meter%c\n", meters, meters == 1.0 ? ' ' : 's' );
    printf( "Length = %f %s\n\n", feet, 0.99995 < feet && feet < 1.00005 ? "foot" : "feet" );
}

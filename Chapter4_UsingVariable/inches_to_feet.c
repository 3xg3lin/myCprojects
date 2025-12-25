#include <stdio.h>

double inchesToFeet( double );

int main(void)
{
    double inches = 1024.0;
    double feet = 0.0;
    feet = inchesToFeet(inches);
    printf( "%12.3g inches is equal to %12.3g feet\n", inches, feet);
    return 0;
}

double inchesToFeet( double someInches)
{
    double someFeet = someInches / 12.0;
    return someFeet ;
}

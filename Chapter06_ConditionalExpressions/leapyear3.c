#include <stdio.h>
#include <stdbool.h>

bool isLeapYear( int );

int main( void ){
    int year;

    printf( "Determine if a year is a leap year or not.\n\n" );
    printf( "Enter year:" );
    scanf( "%d", &year );

    // A simple version of printing the result.
    if( isLeapYear( year ))
        printf( "%d year is a leap year.\n", year );
    else
        printf( "%d year is not a leap year.\n", year );

    // A more C-like version to print the result.
    printf( "%d year is%sa leap year.\n", year,isLeapYear( year ) ? " " : " not ");
}

bool isLeapYear( int year ){
    bool isLeap = false;

    if ( (year % 4) != 0)
        isLeap = false;
    else {
        if( ( year % 400 ) == 0 )
            isLeap = true;
        else if ( ( year % 100 ) == 0)
            isLeap = false;
        else
            isLeap = true;
    }

    return isLeap;
}

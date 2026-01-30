#include <stdio.h>
#include <stdbool.h>

int sumNviaFor( int n );
int sumNviaWhile( int n );
int sumNviaDoWhile( int n );
int sumNviaGoto( int n );

int main( int argc, char *argv[] ){
    int n = 100;

    printf( " The sum of 1..%d = %d (via while() ... loop)\n", n, sumNviaWhile( n ));
}

int sumNviaFor( int n ){
    int sum = 0;
    for ( int num = 0; num < n; num++ ) {
        sum += (num+1);
    }
    return sum;
}

int sumNviaWhile( int n ){
    int sum = 0;
    int num = 0;

    while ( num < n ) {
        sum += (num + 1);
        num++;
    }
    return sum;
}
int sumNviaDoWhile( int n ){

}
int sumNviaGoto( int n ){

}

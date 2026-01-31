#include <stdio.h>
#include <stdbool.h>


int sumNviaFor2(int N);
int sumNviaWhile2(int N);
int sumNviaDoWhile2(int N);


int main()  {
  int n = 100;

  printf( "The sum of 1..%d = %d (via while() ... loop 2)\n"  , n , sumNviaWhile2( n ) );
  printf( "The sum of 1..%d = %d (via for() ... loop 2)\n"    , n , sumNviaFor2( n ) );
  printf( "The sum of 1..%d = %d (via do...while() loop 2)\n" , n , sumNviaDoWhile2( n ) );

  return 0;
}

int sumNviaWhile2(int N){
    int sum = 0;

    while (N > 0) {
        sum += N;
        N--;
    }
    return sum;
}

int sumNviaFor2(int N){
    int sum = 0;

    for (int i = N; i > 0; i--){
        sum += i;
    }
    return sum;
}

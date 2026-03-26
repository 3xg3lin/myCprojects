#include <stdio.h>

void square(double* psize){
    *psize += 10.0;
}

int main(){
    double size = 5;
    double* psize = &size;  // point to the 'size' address (that is its target)
    square(psize);    // pass address of size to function
    printf("actual size after all computation = %lg \n", size); // new value of 'size' is 15
}

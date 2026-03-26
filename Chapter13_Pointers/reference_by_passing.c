#include <stdio.h>

void square(double* psize){
    *psize += 10.0;
}

int main(){
    double size = 5;
    double* psize = &size;
    square(psize);
    printf("actual size after all computation = %lg \n", size);
}

#include <stdio.h>

int main(){
    int height = 10;
    int width = 20;
    int length = 40;

    int* pDimension = NULL;

    printf("\nValues:\n\n");
    printf("sizeof(int) = %2lu\n", sizeof(int));
    printf("sizeof(int*) = %2lu\n", sizeof(int*));
    printf("[height, width, length] = [%2d, %2d, %2d] \n\n",height ,width, length);
    printf("address of pDimension = %p\n", &pDimension);
    printf("address kept by pDimension = %p\n", pDimension);
//    printf("value at NULL pDimension = %2d\n", *pDimension);

    printf("\nUsing address of each named variables...\n\n");
    pDimension = &height;
    printf("address kept by pDimension(address of height) = %p, value at address = %2d\n", pDimension, *pDimension);
    pDimension = &width;
    printf("address kept by pDimension(address of width) = %p, value at address = %2d\n", pDimension, *pDimension);
    pDimension = &length;
    printf("address kept by pDimension(address of length) = %p, value at address = %2d\n", pDimension, *pDimension);
    return 0;
}

#include <stdio.h>

int main(){
    int* pDim1 = (void*)0;
    int* pDim2 = (void*)0;

    int height = 5;
    int weight = 9;
    pDim1 = &height;
    printf("pDim1 address is %p and height address is %p\n", pDim1, &height);
    pDim1 = pDim2;
    printf("pDim1 address is %p and pDim2 address is %p\n", pDim1, pDim2);
    pDim2 = &weight;
    printf("pDim1 address is %p and pDim2 address is %p and weight addresss is %p\n", pDim1, pDim2, &weight);
    if (pDim1 == pDim2)
        printf( "pDim1 points to the same location as pDim2.\n" );
    if (pDim1 != pDim2)
        printf( "pDim1 and pDim2 are different locations.\n" );
    return 0;
}

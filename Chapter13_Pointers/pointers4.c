#include <stdio.h>

void showInfo(int height, int width, int length, int** ppDim){
    printf("sizeof(int) = %2lu\n", sizeof(int));
    printf( "sizeof(int*) = %2lu\n", sizeof(int*));
    printf("[height, width, length] = [%2d, %2d, %2d]\n\n", height, width, length);
    printf("address of pDimension = %#lx\n", (unsigned long)ppDim);
}

void showVariable(char* pId, int* pDim){
    printf("address of %s = %#lx value at address %2d\n", pId, (unsigned long)pDim, *pDim);
}

int main(){
    int height = 10;
    int width = 20;
    int length = 40;

    int* pDimension = NULL;
    int** ppDimension = &pDimension;
    char* pIdentifier = NULL;

    printf("\nValues:\n\n");
    showInfo(height, width, length, ppDimension);
    printf("address kept by pDimension = %p\n", pDimension);
//    printf("value at NULL pDimension = %2d\n", *pDimension);

    printf("\nUsing address of each named variables...\n\n");
    pIdentifier = "height";
    pDimension = &height;
    showVariable( pIdentifier , pDimension );
    pIdentifier = "width";
    pDimension = &width;
    showVariable( pIdentifier , pDimension );
    pIdentifier = "length";
    pDimension = &length;
    showVariable( pIdentifier , pDimension );
    return 0;
}

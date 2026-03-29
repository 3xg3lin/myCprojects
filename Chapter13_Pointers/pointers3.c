#include <stdio.h>

void showInfo(int height, int width, int length){
    printf("sizeof(int) = %2lu\n", sizeof(int));
    printf("sizeof(int*) = %2lu\n", sizeof(int*));
    printf("[height, width, length] = [%2d, %2d, %2d]\n\n", height, width, length);
}

void showVariable(char* pId, int* pDim){
    printf("address of %s = %#lx value at address %2d\n", pId, (unsigned long)pDim, *pDim);
}

int main(){
    int height = 10;
    int width = 20;
    int length = 40;

    printf("\nValues:\n\n");
    showInfo(height, width, length);

    printf("\nUsing address of each named variables...\n\n");
    showVariable("height", &height);
    showVariable("width" , &width);
    showVariable("length", &length);
    return 0;
}

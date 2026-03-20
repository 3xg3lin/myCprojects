#include <stdio.h>

int main(){
    int height = 10;
    void* aPtr = NULL;
    aPtr = &height;

    int h = *(int*)aPtr;
    printf("height = [%d]\n", height);
    printf("*(int*)aPtr = [%d]\n", *(int*)aPtr);
    printf("h = [%d]\n", h);
    printf("sizeof(height) = %lu\n", sizeof(height));
    printf("sizeof(*(int*)aPtr = %lu\n", sizeof(*(int*)aPtr));

    *(int*)aPtr = 3;
    printf("*(int*)aPtr = [%d]\n", *(int*)aPtr);
    printf("height = [%d]\n\n", height);
    return 0;
}

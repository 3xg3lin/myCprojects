#include <stdio.h>

int main() {
    int exArray[5] = {1, 2, 3, 4, 5};
    int *pArray = exArray;

    printf("*pArray       = %d\n", *pArray);
    printf("*(pArray + 1) = %d\n", *(pArray + 1));

    printf("pArray        = %p\n", (void*)pArray);
    printf("pArray + 1    = %p\n", (void*)(pArray + 1));

    printf("sizeof(int)   = %lu\n", sizeof(int));
    printf("sizeof pArray = %lu\n", sizeof(pArray));
}

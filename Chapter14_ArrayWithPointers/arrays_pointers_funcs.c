#include <stdio.h>

void traverse1(int size, int arr[]);
void traverse2(int size, int* pArr);
void traverse3(int size, int arr[]);
void traverse4(int size, int* pArr);

int main(int argc, char *argv[]){
    const int arraySize = 5;
    int array[5] = {10, 20, 30, 40, 50};

    printf("Pointer values(addresses) from initial assignments:\n\n");
    printf("address of array = %p, value at array = %d\n", array, *array);
    printf("address of &array[0] = %p, value at array[0] = %d\n", &array[0], array[0]);

    traverse1(arraySize, array);
    traverse2(arraySize, array);
    traverse3(arraySize, array);
    traverse4(arraySize, array);
}

void traverse1(int size, int arr[]){
    printf("\n(1) Function parameter is an array, ");
    printf("using array notation:\n\n");
    for(int i = 0; i < size; i++){
        printf("&(array[%1d]) = %p, array[%1d] = %1d, i++\n", i, &(arr[i]), i, arr[i]);
    }
}

void traverse2(int size, int* pArr){
    printf("\n(2) Function parameter is a pointer, ");
    printf("using pointer:\n\n");
    for(int i = 0; i < size; i++, pArr++){
        printf("pArr = %p, *pArr = %1d, pArr++\n", pArr, *pArr);
    }
}

void traverse3(int size, int arr[]){
    printf("\n(3) Function parameter is an array, ");
    printf("using pointer:\n\n");
    for(int i = 0; i < size; i++, arr++){
        printf("arr = %p, *arr = %1d, arr++\n", arr, *arr);
    }
}

void traverse4(int size, int* pArr){
    printf("\n(4) Function parameter is a pointer, ");
    printf("using array notation:\n\n");
    for (int i = 0; i < size; i++) {
        printf("&(pArr[%i]) = %p, pArr[%1d] = %1d, i++\n", i, &(pArr[i]), i, pArr[i]);
    }
}

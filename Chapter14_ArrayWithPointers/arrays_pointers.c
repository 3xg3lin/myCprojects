#include <stdio.h>

int main(){
    const int arraySize = 5;
    int array[5] = {1, 2, 3, 4, 5};
    int* pArray1 = array;
    int* pArray2 = &(array[0]);
    printf("Pointer values (addresses) from initial assignments:\n\n");
    printf( "address of array = %p,  value at array = %d\n", array, *array);
    printf( "address of &array[0] = %p,  value at array[0] = %d\n" ,&array[0], array[0]);
    printf( "address of pArray1 = %p,  value at pArray1[0] = %d\n", pArray1, pArray1[0]);
    printf( "address of pArray2 = %p,  value at pArray2 = %d\n", pArray2, *pArray2);
    printf("\n(1) Array values using array notation (index is incremented):\n\n");

    for( int i = 0; i < arraySize; i++ )  {
        printf( "&(array[%1d]) = %p, array[%1d] = %1d, i++\n", i, &(array[i]), i, array[i]);
    }
      printf("\n(2) Array values using a pointer addition (offset is incremented):\n\n");

    for( int i = 0; i < arraySize; i++ )  {
        printf( "pArray2+%1d = %p, *(pArray2+%1d) = %1d, i++\n", i, (pArray2+i), i, *(pArray2+i));
    }
      printf("\n(3) Array values using pointer referencing (pointer is incremented):\n\n");

    for( int i = 0; i < arraySize; i++, pArray1++) {
        printf( "pArray1 = %p, *pArray1 = %1d, pArray1++\n", pArray1, *pArray1);
    }
}

#include <stdio.h>

int main(void){
    int arrayStd[3][5] = {{11, 12, 13, 14, 15}, {21, 22, 23, 24, 25}, {31 ,32 ,33 ,34 ,35}};

    int* arrayPtr[3] = {NULL};

    const int rows = 3;
    const int cols = 5;

    int* pInteger;

    int array1[5] = {11, 12, 13, 14, 15};
    int array2[5] = {21, 22, 23, 24, 25};
    int array3[5] = {31 ,32 ,33 ,34 ,35};
    arrayPtr[0] = &(array1[0]);
    arrayPtr[1] = array2;
    arrayPtr[2] = array3;

    printf("Print both arrays using array notation, array[i][j].\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d\t", arrayStd[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d\t", arrayPtr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf( "Print both arrays using pointers, *pInteger++.\n\n");

    pInteger = &(arrayStd[0][0]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d\t", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");

 /*
    for (int i = 0; i < 3; i++) {       // Since `arrayPtr[i]++`, `arrayPtr[0]`, `arrayPtr[1]`, and `arrayPtr[2]` no longer point to the beginning of the arrays.
        for (int j = 0; j < 5; j++) {      // Use temporary pointer for this make sense.
            printf("%2d\t", *arrayPtr[i]);
            arrayPtr[i]++;
        }
        printf("\n");
    }
    printf("\n");
*/
#define EXPERIMENT 0

#if EXPERIMENT
    pInteger = arrayPtr[0];
#endif
    for (int i = 0; i < rows; i++) {

#if !EXPERIMENT
        pInteger = arrayPtr[i];
#endif

        for (int j = 0; j < cols; j++) {
            printf("%2d\t", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

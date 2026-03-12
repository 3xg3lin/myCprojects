#include <stdio.h>
#include <stdbool.h>
#include "arrayND.h"

enum {
    size1D = 5,
    size2D = 4,
    size3D = 3
};

int main(int argc, char *argv[]){

    bool pretty = true;
    int array2D[size2D][size1D] = {0};
    int array3D[size3D][size2D][size1D] = {0};

    int total = 0;

    initialize2DArray(size1D, size2D, array2D);

    if(!pretty)
        print2DArray(size1D, size2D, array2D);
    else
        prettyPrint2DArray(size1D, size2D, array2D);

    total = sum2DArray(size1D, size2D, array2D);
    printf("Total for array2D is %d\n\n", total);
    // 3D array
    initialize3DArray(size1D, size2D, size3D, array3D);

    if(!pretty)
        print3DArray(size1D, size2D, size3D, array3D);
    else
        prettyPrint3DArray(size1D, size2D, size3D, array3D);

    total = sum3DArray(size1D, size2D, size3D, array3D);
    printf("Total for array3D is %d\n\n", total);

    return 0;
}

void initialize3DArray(int x, int y, int z, int array[z][y][x]){
    for (int k = 0; k < z; k++){
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                array[k][j][i] = (100*(k+1)) + (10*(j+1)) + (i+1);
            }
        }
    }
}

void print2DArray(int col, int row, int array[row][col]){
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            printf("%4d", array[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void initialize2DArray(int col, int row, int array[row][col]){
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            array[j][i] = (10*(j+1)) + (i+1);
        }
    }
}

void prettyPrint2DArray(int col, int row, int array[row][col]){
    printf("    ");
    for (int i = 0; i < col; i++)
        printf(" [%1d]",i);
    printf("\n");

    for (int j = 0; j < row; j++) {
        printf("[%1d]", j);

        for (int i = 0; i < col; i++) {
            printf("%4d", array[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void print3DArray(int x, int y, int z, int array[z][y][x]){
    for (int k = 0; k < z; k++){
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                printf("%4d", array[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void prettyPrint3DArray(int x, int y, int z, int array[z][y][x]){
    for (int k = 0; k < z; k++) {
        printf(" [%1d]", k);

        printf("    ");
        for (int j = 0; j < y; j++) {
            printf("[%1d]", j);
            for (int i = 0; i < x; i++) {
                printf("%4d", array[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int sum2DArray(int col, int row, int array[row][col]){
    int sum = 0;
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            sum += array[j][i];
        }
    }
    return sum;
}

int sum3DArray(int x, int y, int z, int array[z][y][x]){
    int sum = 0;
    for (int k = 0; k < z; k++){
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                sum += array[k][j][i];
            }
        }
    }
    return sum;
}

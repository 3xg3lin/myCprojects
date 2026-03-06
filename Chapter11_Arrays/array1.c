#include <stdio.h>

int main(){
    int anArray[10] = {0};

    short typeSize = sizeof(short);
    short arraySize = sizeof(anArray);
    short elementNum = arraySize / typeSize;

    printf("sizeof(short) = %2d bytes\n", typeSize);
    printf("sizeof(anArray) = %2d bytes\n", arraySize);
    printf("anArray[] has %2d elements\n\n", elementNum);

    float lenghtArray[] = {1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0};

    typeSize = sizeof(float);
    arraySize = sizeof(lenghtArray);
    elementNum = arraySize / typeSize;

    printf("sizeof(float) = %2d bytes\n", typeSize);
    printf("sizeof(lengthArray) = %2d bytes\n", arraySize);
    printf("lengthArray[] has %2d elements\n\n", elementNum);

    const int kVLASize = 12;

    long vlArray[kVLASize];

    typeSize = sizeof(long);
    arraySize = sizeof(vlArray);
    elementNum = arraySize / typeSize;

    printf("sizeof(long) = %2d bytes\n", typeSize);
    printf("sizeof(vlArray) = %2d bytes\n", arraySize);
    printf("vlArray[] has %2d elements\n\n", elementNum);

    return 0;
}

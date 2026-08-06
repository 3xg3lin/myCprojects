#include <stdio.h>
#include <string.h>

enum {kBufferSize = 80};

int main(){
    int anInteger = -1;
    double aDouble = -1.0;
    int numScanned = 0, numPrinted = 0;

    char sIn[] = "1234 5678.9012";
    char sOut[kBufferSize];

    memset(sOut, 0, kBufferSize);

    printf("Using sscanf() on [%s]\n", sIn);
    // sscanf: Reads formatted data FROM a string (sIn) instead of the keyboard.
    // Returns the number of variables successfully assigned (0, 1, or 2).
    numScanned = sscanf(sIn, "%d%lf", &anInteger, &aDouble);
    printf("sscanf() was able to assign %d values.\n", numScanned);
    printf("1. integer: %d\n", anInteger);
    printf("2. double: %lf\n\n", aDouble);

    puts("Using sprintf() to format values to string buffer:");
    // sprintf: Writes formatted data TO a string (sOut) instead of the screen.
    // Returns the total number of characters written to the buffer.
    numPrinted = sprintf(sOut, "integer=[%d] double=[%9.4lf]", anInteger, aDouble);
    printf("%d characters in output string \"%s\"\n", numPrinted, sOut);
    return 0;
}

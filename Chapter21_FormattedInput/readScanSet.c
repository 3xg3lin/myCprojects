#include <stdio.h>

enum {kBufferSize = 80};

int main(){
    char stringBuffer[kBufferSize] = {0};
    printf("Enter only vowels: ");
    // THE SCANSET: "%[aeiouy]"
    // This tells scanf to read characters ONLY as long as they match
    // the characters inside the brackets.
    int numScanned = scanf("%[aeiouy]", stringBuffer);
    printf("Processed string: [%s]\n\n", stringBuffer);

    return 0;
}

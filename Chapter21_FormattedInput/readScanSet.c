#include <stdio.h>

enum {kBufferSize = 80};

int main(){
    char stringBuffer[kBufferSize] = {0};
    printf("Enter only vowels: ");
    int numScanned = scanf("%[aeiouy]", stringBuffer);
    printf("Processed string: [%s]\n\n", stringBuffer);

    return 0;
}

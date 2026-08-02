#include <stdio.h>

enum {
    kBufferSize = 80
};

int main(){
    char stringBuffer[kBufferSize] = {0};
    printf("Enter a string: ");
    scanf("%s", stringBuffer);
    printf("Processed string: [%s]\n\n", stringBuffer);
    return 0;
}

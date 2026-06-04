#include <stdio.h>
#include <string.h>

int main(){
    char* str[3] = {0};

    char mstr1[] = "kerem";
    char mstr2[] = "utku";
    char mstr3[] = "gul";

    str[0] = mstr1;
    str[1] = mstr2;
    str[2] = mstr3;

    for (int i=0; i < 3; i++) {
        for (int j = 0; j < strlen(str[i]); j++) {
            printf("%c \n", *(str[i]+j));    // str[i] is a pointer to the first character of the string. It then continues by appending the j-th character.
        }
    }

    for (int i=0; i < 3; i++) {
        printf("%s \n", str[i]);     // This %s is waiting for the string's address and str[i] already contains that address, so no dereference is needed
    }
}

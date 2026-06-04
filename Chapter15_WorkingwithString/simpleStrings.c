#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char string0[8] = {0};
    char string1[8] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char string2[8] = "hello";
    char string3[] = "hello";
    char* string4 = "hello";

    printf("A) 0:\"%s\"   1:\"%s\"   2:\"%s\"   3:\"%s\"   4:\"%s\"\n\n", string0, string1, string2, string3, string4);

    string0[0] = 'H';
    string1[0] = 'H';
    string2[0] = toupper(string2[0]);
    string3[0] = 'H';
//  string4[0] = 'H';       // Can't do this because its a pointer
                            // to a literal string (a constant).
    string4    = "Hello";   // assign pointer to new string.

    printf("B) 0:\"%s\"   1:\"%s\"   2:\"%s\"   3:\"%s\"   4:\"%s\"\n\n", string0, string1, string2, string3, string4);


// EXPERIMENTS

#if 0
    char string6[8] = "Ladies and Gentlemen";  // size specified but string too long.

    char string7[] = "Ladies and Gentlemen";   // size not specified; size determined by initializer.
#endif

// EXPERIMENT 2

#if 0
    int length = strlen(string2);
    for(int i = 0; i < length; i++){
        string2[i] = toupper(string2[i]);
    }
    printf("E2) \"%s\" \n", string2);
#endif

#if 0
    int i = 0;
    while(string3[i] != '\0') {
        string3[i] = toupper(string7[i]);
        i++;
    }
    printf("E3) \"%s\" \n", string3);
#endif
    return 0;
}

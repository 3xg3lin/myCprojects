#include <stdio.h>

int main(void){
    char aChar;
    int anInt1, anInt2;
    int numScanned;

    printf("1st: Enter <integer><char><integer>: ");
    numScanned = scanf("%d%c%d", &anInt1, &aChar, &anInt2);    // No space before %c -> %c does NOT skip whitespace, reads next char as-is
    printf("Values scanned = %d. Character selected: [%c]\n", numScanned, aChar);

    printf("2nd: Enter <integer> <char> <integer>: ");
    numScanned = scanf("%d %c%d", &anInt1, &aChar, &anInt2);   // Space before %c -> tells scanf to skip any whitespace before reading the char
    printf("Values scanned = %d. Character selected: [%c]\n\n", numScanned, aChar);

    return 0;
}

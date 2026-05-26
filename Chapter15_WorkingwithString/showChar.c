#include <stdio.h>

void showChar(char);
int main(void){
    signed char aChar = 'A';
    char c1 = 65;
    char c2 = 'a';
    char c3 = 0x61;
    char c4 = '7';
    unsigned char aByte = 7;

    showChar(aChar);
    showChar(c1);
    showChar(c2);
    showChar(c3);
    showChar(c4);
    showChar(aByte);
    return 0;
}

void showChar(char ch){
    printf("ch = '%c' (%d) [%#x] [%#b]\n", ch, ch, ch, ch);
}

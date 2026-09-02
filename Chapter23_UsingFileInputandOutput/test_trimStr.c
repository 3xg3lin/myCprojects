#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* trimStr(char* pStr);
int trimStrInPlace(char* pStr);
void testTrim(int testNum, char* pStr);

int main(){
    testTrim(1, "Hello, World!\n");
    testTrim(2, "Box of frogs \t \n");
    testTrim(3, " \t  Bag of hammers");
    testTrim(4, "\t\t  Sack of ferrets\t\t");
    testTrim(5, "   \t\n\v\t\r");
    testTrim(6, "");
    testTrim(7, "Goodbye, World!");
    return 0;
}

char* trimStr(char* pStr){
    size_t first,last,len;
    first = last = len = 0;

    while (isspace(pStr[first])) {
        first++;
    }
    pStr += first;

    len = strlen(pStr);
    if (len) {
        last = len - 1;
        while (isspace(pStr[last])) {
            last--;
        }
        pStr[last + 1] = 0;
    }
    return pStr;
}

int trimStrInPlace(char* pStr){
    size_t first, last, lenIn, lenOut;
    first = last = lenIn = lenOut = 0;

    lenIn = strlen(pStr);
    char tmpStr[lenIn + 1];
    strcpy(tmpStr, pStr);
    char* pTmp = tmpStr;

    while (isspace(pTmp[first])) {
        first++;
    }
    pTmp += first;

    lenOut = strlen(pTmp);
    if (lenOut) {
        last = lenOut - 1;
        while (isspace(pTmp[last])) {
            last--;
        }
        pTmp[last + 1] = '\0';
    }
    lenOut = strlen(pTmp);
    if (lenIn != lenOut) {
        strcpy(pStr, pTmp);
    }
    return lenOut;
}

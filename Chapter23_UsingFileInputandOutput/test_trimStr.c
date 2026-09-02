#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* trimStr(char* pStr);
int trimStrInPlace(char* pStr);
void testTrim(int testNum, char* pStr);

int main(){
    // Test different kinds of strings
    testTrim(1, "Hello, World!\n");
    testTrim(2, "Box of frogs \t \n");
    testTrim(3, " \t  Bag of hammers");
    testTrim(4, "\t\t  Sack of ferrets\t\t");
    testTrim(5, "   \t\n\v\t\r"); // only whitespace
    testTrim(6, "");             // empty string
    testTrim(7, "Goodbye, World!"); // no whitespace to trim
    return 0;
}

// Trim the string in place, no copy is made
char* trimStr(char* pStr){
    size_t first, last, len;
    first = last = len = 0;

    // Move first past the leading whitespace
    while (isspace(pStr[first])) {
        first++;
    }
    pStr += first; // pStr now points past the leading whitespace

    len = strlen(pStr);
    if (len) { // skip this part if string is now empty
        last = len - 1;
        // Move last back past the trailing whitespace
        while (isspace(pStr[last])) {
            last--;
        }
        pStr[last + 1] = 0; // cut the string here, new end of string
    }

    return pStr; // pStr points into the original string, no copy
}

// Trim the string using a temp copy, then write result back into pStr
int trimStrInPlace(char* pStr){
    size_t first, last, lenIn, lenOut;
    first = last = lenIn = lenOut = 0;

    lenIn = strlen(pStr);
    char tmpStr[lenIn + 1]; // temp buffer, same size as input
    strcpy(tmpStr, pStr);   // copy input into temp buffer
    char* pTmp = tmpStr;    // pTmp will move, tmpStr stays at start

    // Move first past the leading whitespace
    while (isspace(pTmp[first])) {
        first++;
    }
    pTmp += first; // pTmp now points past the leading whitespace

    lenOut = strlen(pTmp);
    if (lenOut) { // skip this part if string is now empty
        last = lenOut - 1;
        // Move last back past the trailing whitespace
        while (isspace(pTmp[last])) {
            last--;
        }
        pTmp[last + 1] = '\0'; // cut the temp string here
    }

    lenOut = strlen(pTmp);
    if (lenIn != lenOut) {     // only copy back if something changed
        strcpy(pStr, pTmp);   // write trimmed string into original pStr
    }

    return lenOut; // length of the trimmed string
}

// Run both trim functions on pStr and print the results
void testTrim(int TestNum, char* pStr){
    size_t len;
    char testStr[strlen(pStr) + 1]; // working copy, since pStr may be const
    char* pTest;

    strcpy(testStr, pStr);
    fprintf(stderr, "%1d. original: \"%s\" [len:%d]\n", TestNum, testStr, (int)strlen(pStr));

    pTest = trimStr(testStr); // first version, no copy inside
    fprintf(stderr, "trimStr: \"%s\" [len:%d]\n", pTest, (int)strlen(pTest));

    strcpy(testStr, pStr); // reset testStr, since trimStr changed it
    len = trimStrInPlace(testStr); // second version, uses a copy inside
    fprintf(stderr, "   trimStr2: \"%s\" [len:%d]\n\n", testStr, (int)len);
}

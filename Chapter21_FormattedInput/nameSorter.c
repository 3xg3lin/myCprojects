#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {
    kListMax = 100,
    kStringMax = 80
};

typedef char string[kStringMax];

void addName(string* names, string newOne, int* listSize);

void printNames(string* names, int listSize);

void removeNewline(string s){
    int len = strlen(s);
    s[len-1] = '\0';
}

// 1. Use fgets() for user input,
// 2. remove trailing '\n', and
// 3. return length of string or 0 if failure or empty.

int getName(char* buf, int size){
    if (fgets(buf, size, stdin)) {
        int len;
        for (len = 0; len < size; len++) {
            if ('\n' == buf[len]) {
                buf[len] = '\0';
                break;
            }
            if ('\0' == buf[len]) {
                break;
            }
        }
        return len;
    }
    else {
        return 0;
    }
}

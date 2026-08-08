#include <stdio.h>

enum {kBufferSize = 80};

// safe_gets() uses the fgets() function and then removes the last ‘\n’ character
// from the character buffer or input string. Like fgets(),
//  safe_gets() returns a pointer to the string to indicate that the operation was successful,
// or NULL to indicate invalid input, EOF, or another error.

char* safe_gets(char* buf, int size){
    if (fgets(buf, size, stdin)) {         // fgets() preserves '\n'
        for (int i = 0; i < size; i++) {   // Find the last '\n'
            if ('\n' == buf[i]) {
                buf[i] = '\0';              // Replace '\n' with '\0'
                break;
            }
        }
        return buf;            // fgets() succeeded; return the string pointer.
    }
    else {
        return NULL;           // fgets() failed; return NULL to indicate failure.
    }
}

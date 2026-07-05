#include <stdio.h>

int a = 5;              // Static storage duration, External linkage (Global variable)
static int b = 3;       // Static storage duration, Internal linkage (File-scope variable)

int main(){
    static int c = 8;   // Static storage duration, No linkage (Local static variable)
    printf("%d\n", a);
}
#include <stdio.h>

int main(){
    char* test = "hello, I'm ghost";
    printf("test address start point is %p ,test[8] address is = %p and test[8] value is %c\n", test, (test+7), test[8]);  //(test only store started address)
    printf("address of char* test = %p , only test = %p\n and value at that target %s\n", &test, test, test);
}
// char* test = "hello, I'm ghost";
//
// like array
// printf("%c\n", test[3]);
// --> output: l
//
// with pointer arithmetic
// printf("%c\n", *(test + 3));  --> (same thing) --> test[3] == *(test + 3)
// --> output: l                 --> h  e  l  l  o
//                                   0  1  2  3  4
//
// by shifting the pointer
// char* p = test + 3;
// printf("%c\n", *p);
//

#include <stdio.h>

int main(){
    void* p1 = (void*)3;
    int b = (int)&p1[5];
    printf("b = %d ,(int)&a[5]=%p", b,((int)&p1[5]));
}

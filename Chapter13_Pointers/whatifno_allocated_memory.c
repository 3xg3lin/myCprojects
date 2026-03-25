#include <stdio.h>

int main(){
    void* p1 = (void*)3;     //assigning address 0x3 to a pointer.
    int b = (int)&p1[5];     //p1 + 5 so (0x3) + 5 ;
    printf("b = %d ,(int)&a[5]=%p", b,((int)&p1[5]));   // This indicates an invalid memory address and invalid pointer arithmetic.
}

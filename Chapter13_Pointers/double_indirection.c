#include <stdio.h>

int main(){
    int digit = 5;
    int* pDigit = &digit;
    int** ppDigit = &pDigit;

    printf("(**ppDigit) = %d , (*pDigit) = %d , &ppDigit = [%p] , ppDigit = [%p] , &pDigit = [%p] , pDigit = [%p] , &digit = [%p]", **ppDigit, *pDigit, &ppDigit, ppDigit, &pDigit, pDigit, &digit);
}

#include <stdio.h>

int main(void){
    int anInteger = -1;
    double aDouble = -1.0;

    printf("Enter an integer and a decimal number: ");
    scanf("%d%lf", &anInteger, &aDouble);
    printf("1. integer:  %d\n", anInteger);
    printf("2.  double:  %lf\n\n", aDouble);

    return 0;
}

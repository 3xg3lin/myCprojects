#include <stdio.h>

int main(void){
    int year, month, day;
    int numScanned;
    while (printf("Enter mm*dd*yyyy (and other character to quit): "), numScanned = scanf("%2d%*c%2d%*c%4d", &month, &day, &year), numScanned > 0) {
        printf("%d/%d/%d\n", month, day, year);
    }
    printf("\nDone\n");
    return 0;
}

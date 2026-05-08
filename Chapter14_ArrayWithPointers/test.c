#include <stdio.h>

int add(int farray[]){
    int sum = 0;
    for (int i = 0;i < 4;i++){
        sum += farray[i];
    }
    return sum;
}

int main(){
    int array1[4] = {1,2,3,4};
    printf("sum is %d\n", add(array1));
}

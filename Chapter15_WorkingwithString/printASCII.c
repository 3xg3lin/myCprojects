#include <stdio.h>

int main(int argc,char *argv[]){
    char c2;
    for (int i = 0; i < 64; i++){
        c2 = i;
        printf("%c %3d %#x %#b",c2 ,c2 ,c2, c2);
        printf("\n");
    }
    return 0;
}

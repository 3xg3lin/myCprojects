#include <stdio.h>

enum suit {
    eSpade ,
    eHeart ,
    eDiamond ,
    eClub
};

int main(int argc, char *argv[]){
    enum suit s = eSpade;
    printf("%d\n", s);
    return 0;
}

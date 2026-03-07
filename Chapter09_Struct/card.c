#include <stdio.h>
#include <stdbool.h>

enum Suit {
    eClub  = 1,
    eDiamond,
    eHeart,
    eSpade
};

enum Face {
    eOne = 1,
    eTwo,
    eThree,
    eFour,
    eFive,
    eSix,
    eSeven,
    eEight,
    eNine,
    eTen,
    eJack,
    eQueen,
    eKing,
    eAce
};

struct Card {
    enum Suit suit;
    int suitValue;
    enum Face face;
    int faceValue;
    bool isWild;
};

int main(void){
    struct Card card;

    printf("enum Suit is %lu bytes\n" , sizeof(enum Suit));
    printf("enum Face is %lu bytes\n" , sizeof(enum Face));
    printf("int is %lu bytes\n" , sizeof(int));
    printf("bool is %lu bytes\n" , sizeof(bool));
    printf("struct Card is %lu bytes\n" , sizeof(struct Card));
    printf("card is %lu bytes\n" , sizeof(card));
    return 0;
}

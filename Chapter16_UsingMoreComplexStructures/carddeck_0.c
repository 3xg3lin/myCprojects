#include <stdio.h>
#include <stdbool.h>

typedef enum Suit {
    eClub  = 1,
    eDiamond,
    eHeart,
    eSpade
} Suit;

typedef enum Face {
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
} Face;

typedef struct Card {
    Suit suit;
    int suitValue;
    Face face;
    int faceValue;
    bool isWild;
} Card;

int GetCardFaceValue(Card* pCard);
int GetCardSuiteValue(Card* pCard);
void PrintCard( Card* pCard );

int main(void)  {
    Card aCard;
    aCard.suit = eDiamond;
    aCard.suitValue = GetCardSuiteValue(pCard);
    aCard.face = eSeven;
    aCard.faceValue = GetCardFaceValue(pCard);
    aCard.isWild = true;

    PrintCard(&aCard);
    printf("\n");
    return 0;
}

inline int GetCardFaceValue(Card* pCard) {
    return (int)pCard->face;
}

inline int GetCardSuiteValue(Card* pCard) {
    return (int)pCard->suitValue;
}

void PrintCard(Card* pCard){
    char cardStr[20] = {0};
    CardToString(pCard, cardStr);
    printf("%18s", cardStr);
}

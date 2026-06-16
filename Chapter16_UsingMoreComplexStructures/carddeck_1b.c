#include <string.h>
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
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool w);

enum  {
  kCardsInDeck = 52,
  kCardsInSuit = 13
};

const bool kWildCard    = true;
const bool kNotWildCard = false;


int main(void)  {
    Card deck[kCardsInDeck];
    Card* pCard = &deck[3];
    InitializeCard(pCard, eSpade, eFive, kNotWildCard);
    PrintCard(pCard);
    printf("\n");
    return 0;
}


// Implement the following functions in this file
void InitializeCard(Card* pCard, Suit s, Face f, bool w){
    pCard->suit = eSpade;
    pCard->suitValue = GetCardSuiteValue(pCard);
    pCard->face = eFive;
    pCard->faceValue = GetCardFaceValue(pCard);
    pCard->isWild = kNotWildCard;

}

inline int GetCardFaceValue(Card* pCard) {       // An inline function is a small function that asks compiler to insert
    return (int)pCard->face;                     // its code directly where it is called, instead of jumping to it.
}

inline int GetCardSuiteValue(Card* pCard) {
    return (int)pCard->suitValue;
}

void PrintCard(Card* pCard){
    char cardStr[20] = {0};
    CardToString(pCard, cardStr);
    printf("%18s", cardStr);
}

void CardToString(Card* pCard, char pCardStr[20]){
    switch ((*pCard).face) {                                 // the same implementation: pCard->face and (*pCard).face
        case eTwo:   strcpy(pCardStr, "  2"); break;         // This is just an abbreviation
        case eThree: strcpy(pCardStr, "  3"); break;
        case eFour:  strcpy(pCardStr, "  4"); break;
        case eFive:  strcpy(pCardStr, "  5"); break;
        case eSix:   strcpy(pCardStr, "  6"); break;
        case eSeven: strcpy(pCardStr, "  7"); break;
        case eEight: strcpy(pCardStr, "  8"); break;
        case eNine:  strcpy(pCardStr, "  9"); break;
        case eTen:   strcpy(pCardStr, "  10"); break;
        case eJack:  strcpy(pCardStr, "  Jack"); break;
        case eQueen: strcpy(pCardStr, "  Queen"); break;
        case eKing:  strcpy(pCardStr, "  King"); break;
        case eAce:   strcpy(pCardStr, "  Ace"); break;
        default:    strcpy(pCardStr, "  ???"); break;
    }
    switch (pCard->suit) {
        case eSpade:   strcat(pCardStr, "of Spades"); break;
        case eHeart:   strcat(pCardStr, "of Hearts"); break;
        case eDiamond: strcat(pCardStr, "of Diamonds"); break;
        case eClub:    strcat(pCardStr, "of Clubs"); break;
        default:       strcat(pCardStr, "of ???s"); break;
    }
}

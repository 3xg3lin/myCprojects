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

typedef struct{
    int cardsDealt;
    Card card1;
    Card card2;
    Card card3;
    Card card4;
    Card card5;
} Hand;

void InitializeHand(Hand* pHand);
void AddCardToHand(Hand* pHand, Card* pCard);
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr);
Card* GetCardInHand(Hand* pHand, int cardIndex);


int GetCardFaceValue(Card* pCard);
int GetCardSuiteValue(Card* pCard);
void PrintCard( Card* pCard );
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool w);
void InitializeDeck(Card* pDeck);
void PrintDeck(Card* pDeck);

enum  {
    kCardsInHand = 5,
    kCardsInDeck = 52,
    kCardsInSuit = 13,
    kNumHand = 4
};

const bool kWildCard    = true;
const bool kNotWildCard = false;


int main(void)  {
    Card deck[kCardsInDeck];
    InitializeDeck(&deck[0]);

    Hand h1;

    PrintDeck(&deck[0]);
    return 0;
}

void AddCardToHand(Hand* pHand, Card* pCard){
    int numInHand = pHand->cardsDealt;
    if(numInHand == kCardsInHand) return;

    Card* pC = GetCardInHand(pHand,numInHand);
    InitializeCard(pC, pCard->suit, pCard->face, pCard->isWild);

    pHand->cardsDealt++;
}

Card* GetCardInHand(Hand* pHand, int cardIndex){
    Card* pC = NULL;
    switch (cardIndex) {
        case 0:
            pC = &(pHand->card1); break;
        case 1:
            pC = &(pHand->card2); break;
        case 3:
            pC = &(pHand->card3); break;
        case 4:
            pC = &(pHand->card4); break;
    }
    return pC;
}

void InitializeHand(Hand* pHand){
    pHand->cardsDealt = 0;
}

// Implement the following functions in this file
void InitializeCard(Card* pCard, Suit s, Face f, bool w){
    pCard->suit = s;
    pCard->suitValue = GetCardSuiteValue(pCard);
    pCard->face = f;
    pCard->faceValue = GetCardFaceValue(pCard);
    pCard->isWild = w;
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

void InitializeDeck(Card* pDeck){
    Face f[] = {eTwo, eThree, eFour, eFive, eSix, eSeven, eEight, eNine, eTen, eJack, eQueen, eKing, eAce};

    Card* pC;
    for (int i = 0; i < kCardsInSuit; i++){
        pC = &(pDeck[i + (0 * kCardsInSuit)]);
        InitializeCard(pC, eSpade, f[i], kNotWildCard);

        pC = &(pDeck[i + (1 * kCardsInSuit)]);
        InitializeCard(pC, eHeart, f[i], kNotWildCard);

        pC = &(pDeck[i + (2 * kCardsInSuit)]);
        InitializeCard(pC, eDiamond, f[i], kNotWildCard);

        pC = &(pDeck[ i + (3 * kCardsInSuit) ]);
        InitializeCard( pC , eClub , f[i], kNotWildCard );
    }
}

void PrintDeck(Card* pDeck){
    printf("%d cards in the deck\n\n", kCardsInDeck);
    printf("The ordered deck:\n");
    for (int i = 0; i < kCardsInSuit ; i++){
        int index = i + (0* kCardsInSuit);
        printf("(%2d)", index + 1);
        PrintCard(&pDeck[index]);
        printf("\n");

        index = i + (1 * kCardsInSuit);
        printf("(%2d)", index + 1);
        PrintCard(&pDeck[index]);
        printf("\n");

        index = i + (2 * kCardsInSuit);
        printf("(%2d)", index + 1);
        PrintCard(&pDeck[index]);
        printf("\n");

        index = i + (3 * kCardsInSuit);
        printf("(%2d)", index + 1);
        PrintCard(&pDeck[index]);
        printf("\n\n");
    }
}

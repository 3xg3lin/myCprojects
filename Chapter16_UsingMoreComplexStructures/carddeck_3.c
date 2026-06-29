#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const bool kWildCard    = true;
const bool kNotWildCard = false;

typedef enum Suit {
    eClub  = 1,
    eDiamond,
    eHeart,
    eSpade
} Suit;

enum  {
    kCardsInHand = 5,
    kCardsInDeck = 52,
    kCardsInSuit = 13,
    kNumHand = 4
};

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
    Card* hand[kCardsInHand];
    int cardsDealt;
} Hand;

void InitializeHand(Hand* pHand);
void AddCardToHand(Hand* pHand, Card* pCard);
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr);
void PrintAllHands(Hand* hands[kNumHand]);
int GetCardFaceValue(Card* pCard);
int GetCardSuiteValue(Card* pCard);
void PrintCard( Card* pCard );
void CardToString(Card* pCard, char pCardStr[20]);
void InitializeCard(Card* pCard, Suit s, Face f, bool w);
void InitializeDeck(Card* pDeck);
void PrintDeck(Card* pDeck);


typedef struct {
    Card* shuffled[ kCardsInDeck ];
    int numDealt;
    bool bIsShuffled;
} Shuffled;


typedef struct  {
  Card  ordered[ kCardsInDeck ];
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;

Card* DealCardFromDeck(Card pDeck[], int index){
    Card* pCard = &pDeck[index];
    return pCard;
}

void ShuffleDeck(Shuffled* pShuffled);

int main(void)  {
    Card deck[kCardsInDeck];
    Card* pDeck = deck;
    InitializeDeck(&deck[0]);

    Hand h1, h2, h3, h4;
    InitializeHand(&h1);
    InitializeHand(&h2);
    InitializeHand(&h3);
    InitializeHand(&h4);

    for (int i = 0; i < kCardsInHand; i++) {
        AddCardToHand(&h1, DealCardFromDeck(pDeck, i));
        AddCardToHand(&h2, DealCardFromDeck(pDeck, i + 13));
        AddCardToHand(&h3, DealCardFromDeck(pDeck, i + 26));
        AddCardToHand(&h4, DealCardFromDeck(pDeck, i + 39));
    }

    PrintHand(&h1, "Hand 1: ", "   ");
    PrintHand(&h2, "Hand 2: ", "   ");
    PrintHand(&h3, "Hand 3: ", "   ");
    PrintHand(&h4, "Hand 4: ", "   ");

    return 0;
}

void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr){
    printf("%s%s\n", pLeadStr, pHandStr);
    for (int i = 0; i < kCardsInHand; i++) {
        printf("%s", pLeadStr);
        PrintCard(pHand->hand[i]);
        printf("\n");
    }
}

void PrintAllHands(Hand* hands[kNumHand])  {
  PrintHand(hands[0], "Hand 1:", "                  ");
  PrintHand(hands[1], "Hand 2:", "  ");
  PrintHand(hands[2], "Hand 3:", "                                    ");
  PrintHand(hands[3], "Hand 4:", "                  ");
}

void AddCardToHand(Hand* pHand, Card* pCard){
    if(pHand->cardsDealt == kCardsInHand) return;
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}


void InitializeHand(Hand* pHand){
    pHand->cardsDealt = 0;
    for (int i = 0; i < kCardsInHand; i++){
        pHand->hand[i] = NULL;
    }
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

void ShuffleDeck(Shuffled* pDeck){
    long randIndex;
#if 1
    srand(8*1024*1024);
#else
    srand(time());
#endif

    //shuffle
    Card* pTmpCard;
    for (int thisIndex = 0; thisIndex < kCardsInDeck; thisIndex++){
        randIndex = rand() % kCardsInDeck;      // 0..51
        //swap
        pTmpCard = pDeck->shuffled[thisIndex];
        pDeck->shuffled[thisIndex] = pDeck->shuffled[randIndex];
        pDeck->shuffled[randIndex] = pTmpCard;
    }
    pDeck->bIsShuffled = true;
}

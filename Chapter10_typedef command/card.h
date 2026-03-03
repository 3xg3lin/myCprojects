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

typedef struct Hand  {
  int cardsDealt;
  Card c1, c2, c3, c4, c5;
} Hand;

Hand addCard(Hand oldHand, Card card);
void printHand(Hand h);
void printHand2(Hand h);
void printCard(Card c);

#ifndef CARDSSET_H
#define CARDSSET_H

#include "Card.h"
#include <cstdlib>
#include <ctime>

class CardsSet {
public:
  CardsSet() : number(0) {}
  void novSet();
  void shuffle();
  int numCards() { return number; }
  Card take();
  void put(Card k);
  Card lookIn(int no);
  void empty() { number = 0; }

private:
  Card set[52];
  int number;
};

inline void CardsSet::novSet() {
  int i = 0; // i: the index of the card to be init

  // iter for all colors
  for (enum color c = club; c <= spade; c = (color)(c + 1))
    // iter for all value
    for (int v = 1; v < 14; ++v) {
      // create the current card
      Card *card = new Card(c, v);
      set[i++] = *card;
    }

  number = 52;
}

// shuffle by using rand
inline void CardsSet::shuffle() {
  // seeding by the current time
  srand(time(NULL));

  // shuffle
  for (int i = 51; i > 0; --i) {
    // generate a index in range [0, range_max]
    int randPos = rand() % i;
    // get the last card
    Card tail = set[i];
    // swap card in the random position with the last card
    set[i] = set[randPos];
    set[randPos] = tail;
  }
}

inline Card CardsSet::take() { return set[--number]; }

inline void CardsSet::put(Card k) { set[number++] = k; }

inline Card CardsSet::lookIn(int no) { return set[no - 1]; }

#endif

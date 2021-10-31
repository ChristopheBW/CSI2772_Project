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
  Card origin_set[52];
  int insert_index = 0;

  // copy the origin set
  for (int i = 0; i < 52; ++i) {
    origin_set[i] = set[i];
  }

  // seeding by the current time
  srand(time(NULL));

  // shuffle
  for (int range_max = 51; range_max >= 0; --range_max) {
    // generate a index in range [0, range_max]
    int origin_index = ((double)rand() / RAND_MAX) * range_max;
    // insert this element, increase insert_index for the next insertion
    set[insert_index++] = origin_set[origin_index];
    // use the last element (in the range) to replace current element
    origin_set[origin_index] = origin_set[range_max];
  }
}

inline Card CardsSet::take() { return set[--number]; }

inline void CardsSet::put(Card k) { set[number++] = k; }

inline Card CardsSet::lookIn(int no) { return set[no - 1]; }

#endif

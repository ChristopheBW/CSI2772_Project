#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cassert> //for assert()

using namespace std;

enum color { club, diamond, heart, spade };

class Card {
public:
  Card(color c = club, int v = 1);
  int value() { return val; }
  void write();

private:
  color col;
  int val;
};

/*Constructor*/
inline Card::Card(color c, int v) {
  assert(v >= 1 &&
         v <= 13); // we use a standard function void assert (int expression)
  // which indicates an error message if the expression is false.
  col = c;
  val = v;
}

inline void Card::write() {
  switch (val) {
  case 13:
    cout << "King";
    break;
  case 12:
    cout << "Queen";
    break;
  case 11:
    cout << "Jack";
    break;
  case 1:
    cout << "Ace";
    break;
  default:
    cout << val;
  }

  cout << " of ";

  switch (col) {
  case club:
    cout << "Club";
    break;
  case diamond:
    cout << "Diamond";
    break;
  case heart:
    cout << "Heart";
    break;
  case spade:
    cout << "Spade";
    break;
  default:
    cerr << "ERROR: unexpected color!" << endl;
  }
}

#endif

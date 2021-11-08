/*
 * Card.h
 *
 * This file is part of CSI2772A_2021F_GROUP23_PROJECT
 */
#ifndef CARD_H // header OVR guardian
#define CARD_H

#include <ostream>   // support ostream operation
#include <stdexcept> // support std exceptions
#include <string>    // support string operation

namespace card_game // namespace declaration

{
enum Bean {
  Bean_Blue,
  Bean_Chili,
  Bean_Stink,
  Bean_Green,
  Bean_Soy,
  Bean_Black,
  Bean_Red,
  Bean_Garden
};

class Card {
public:
  virtual int getCardsPerCoin(int coins) = 0;
  virtual std::string getName() = 0;
  virtual void print(std::ostream &out) = 0;
};

class Blue : public Card {
public:
  int getCardsPerCoin(int coins) {
    switch (coins) {
    case 1:
      return 4;
    case 2:
      return 6;
    case 3:
      return 8;
    case 4:
      return 10;
    default:
      throw std::invalid_argument("The given coins is out of game definition!");
    }
  }

  std::string getName() { return "Blue"; }

  void print(std::ostream &out) { out << 'B'; }
};

class Chili : public Card {
public:
  int getCardsPerCoin(int coins) {
    switch (coins) {
    case 1:
      return 3;
    case 2:
      return 6;
    case 3:
      return 8;
    case 4:
      return 9;
    default:
      throw std::invalid_argument("The given coins is out of game definition!");
    }
  }

  std::string getName() { return "Chili"; }

  void print(std::ostream &out) { out << 'C'; }
};
} // namespace card_game
#endif

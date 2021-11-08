#ifndef PLAYER_H
#define PLAYER_H

#include "CardsSet.h"

class Player {
public:
  Player(CardsSet &cardPacket, bool isComputer)
      : packet(cardPacket), computer(isComputer) {}
  int play();

private:
  CardsSet inHand;
  CardsSet &packet;
  const bool computer;
  int countPoints();
};

inline int Player::countPoints() {
  int ctr = 0;
  int aceCtr = 0;

  // iter all the cards in hand
  for (int i = 1; i <= inHand.numCards(); ++i) {
    int cardVal = inHand.lookIn(i).value();
    // handle ace cards, consider all ace as value 14
    if (cardVal == 1) {
      ++aceCtr;
      cardVal = 14;
    }
    // update hand counter
    ctr += cardVal;
  }

  // if the final result exceeds 21, use 1 as the ace value instead of 14
  return ctr > 21 ? ctr - aceCtr * 13 : ctr;
}

inline int Player::play() {
  // init a new game
  int points;
  inHand.empty();
  bool continuous;

  // play the game
  do {
    // draw card
    Card card = packet.take();
    inHand.put(card);
    points = countPoints();

    // print card info
    if (!computer) {
      cout << endl << "You get Card: ";
      card.write();
      cout << "\nYour score is " << points << " points" << endl;
    }

    // if current points are more than 21 then gameover
    if (points >= 21)
      break;

    // ask if want additional card
    if (!computer) {
      cout << "Any additional Card ?" << endl;
      char answer[3];
      cin >> answer;
      continuous = answer[0] == 'y';
    } else {
      // computer will ask additional card if the current point < 15
      continuous = points < 15;
    }
  } while (continuous); // start another round if player want

  // print computer game result
  if (computer)
    cout << "Computer played the game and got: " << points << endl;

  return points;
}

#endif

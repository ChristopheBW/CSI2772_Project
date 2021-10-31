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
  int ace_num = 0;
  int points = 0;

  for (int i = 0; i < inHand.numCards(); ++i) {
    int val = inHand.lookIn(i + 1).value();
    if (val == 1)
      ++ace_num;
    else
      points += val;
  }

  if (ace_num != 0) {
    points += (points + ace_num + 13) > 21 ? ace_num : ace_num + 13;
  }

  return points;
}

inline int Player::play() {
  int points = 0;
  inHand.empty();
  bool continuous;

  do {
    Card card = packet.take();
    inHand.put(card);
    points = countPoints();

    if (!computer) {
      cout << endl << "You get Card: ";
      card.write();
      cout << "\nYour score is " << points << " points" << endl;
    }

    if (points >= 21)
      break;

    if (!computer) {
      cout << "Any additional Card ?" << endl;
      char answer[3];
      cin >> answer;
      continuous = answer[0] == 'y';
    } else {
      continuous = points < 15;
    }

  } while (continuous);

  if (computer)
    cout << "Computer played the game and got: " << points << endl;

  return points;
}

#endif

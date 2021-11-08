#include <iostream>

using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
  Color color;
  Face face;
};

int main() {
  Card game[32]; // create 32 empty card

  int i = 0; // i: the index of the card to be init

  // iter for all colors
  for (enum Color color = club; color <= heart; color = (Color)(color + 1))
    // iter for all faces
    for (enum Face face = seven; face <= ace; face = (Face)(face + 1))
      // init the card and increace i to be the index of the next card
      game[i++] = {color, face};

  return 0;
}

// if the original main has some problem in your compiler,
// please use this main function :)
int main_mac() {
  Card game[32];
  int i = 0;
  const Color colorVector[] = {club, diamond, spades, heart};
  const Face faceVector[] = {seven, eight, nine, ten, jack, queen, king, ace};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      game[i * j].color = colorVector[i];
      game[i * j].face = faceVector[j];
    }
  }

  return 0;
}

/*Ex1a - Devoir 3 CSI2772A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
  Color color;
  Face face;
};

typedef Card Hand[5];

/* testPair() function*/
// bool testPair_classic(const Hand &h) {
//   Face existed[5]; // existed: a list store all visited card
//
//   for (int i = 0; i < 5; i++) { // iter for each card in the hand
//     Face current = h[i].face;   // current: the face of the current card
//
//     // check if the current face match the previous cards
//     for (int j = 0; j < i; j++) { // iter for each card we have visited
//       if (current == existed[j])  // matched (is pair)
//         return true;
//     }
//
//     existed[i] = current; // flag the current card to existed
//   }
//
//   return false; // no cards are pairs
// }

/* testPair() function*/
bool testPair(const Hand &h) {
  int face[8] = {0};            // list to store the number of each face
  for (int i = 0; i < 5; i++) { // iter for each card in the hand
    face[h[i].face]++;          // increace the number of the current face
  }

  for (int i = 0; i < 8; i++) { // iter for each face in the list
    if (face[i] > 1) { // if any face has more than 1 card, it is a pair
      return true;
    }
  }
  return false;
}

/*Example of main()*/
int main() {
  bool testPair(const Hand &);
  Hand myHand = {{club, nine},
                 {diamond, eight},
                 {spades, ace},
                 {spades, jack},
                 {club, ace}};
  cout << "\nI have at least: " << testPair(myHand) << "pair" << endl;
  return 0;
}

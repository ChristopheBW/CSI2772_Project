//
// Created by Xiang Li on 2021-11-11.
//

#ifndef CSI2772_PROJECT_DECK_H
#define CSI2772_PROJECT_DECK_H

#include "Card.h"

class Deck : public vector<Card*> {

    public:
        //Default constructor
        Deck() {};
        //Construct a deck from the input stream
        Deck(istream&, const CardFactory*) {};
        //Remove and return the top card from deck
        Card* draw() {};
        //Destructor
        ~Deck() {};
        //print the deck to the output stream
        friend void print(std::ostream&, Deck&);
};


#endif //CSI2772_PROJECT_DECK_H

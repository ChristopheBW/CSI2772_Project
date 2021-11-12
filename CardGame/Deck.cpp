//
// Created by Xiang Li on 2021-11-11.
//

#include "Deck.h"
#include "CardFactory.h"

//Constructor which accepts an istream and reconstruct the Deck from file
Deck::Deck(istream& in, const CardFactory* factory) {
    //CardFactory *pCardFactory = CardFactory::getFactory();

    //while input stream not empty, keep reading and insert new cards at the back of deck
    while (!in.eof()) {
        this->push_back(CardFactory::CreateCard(in.get()));
    }
}

//Remove and return the top card from deck
Card* Deck::draw() {
    Card* ret = nullptr;
    if (!this->empty()) {
        tmp = this.front();
        this->erase(this->begin());
    }
    return ret;
}

//print the deck to the output stream
void print(std::ostream& out, Deck& d) {
    for (int i = 0; i < (int)d.size(); ++i) {
        cout << d.at(i);
    }
}




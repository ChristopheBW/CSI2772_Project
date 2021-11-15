//
// Created by Xiang Li on 2021-11-15.
//

#include <iostream>
#include <list>
#include "Card.h"
#include "CardFactory.h"

#ifndef CSI2772_PROJECT_HAND_H
#define CSI2772_PROJECT_HAND_H

namespace cardgame {
    class Hand {
    public:
        //default constructor
        Hand() = default;

        //reconstruct hand from file
        Hand(std::istream& in, const CardFactory* factory) {
            while (!in.eof()) {
                char c = (char) in.get();
                if (std::isalpha(c)) {
                    hand.push_back(CardFactory::CreateCard(c));
                }
            }
        }

        //Adds the card to the rear of the hand.
        Hand& operator+=(Card* c) {
            hand.push_back(c);
            return *this;
        }

        //Returns and removes the top card from the player's hand.
        Card* play() {
            Card* pCard = nullptr;
            if (!hand.empty()) {
                pCard = hand.front();
                hand.pop_front();
            }
            return pCard;
        }

        //Returns but does not remove the top card from the player's hand.
        Card* top() {
            return hand.front();
        }

        //Returns and removes the Card at a given index.
        Card* operator[](int index) {
            Card* pCard = hand.front() + index;
            if (!hand.empty() && hand.size() >= unsigned(index)) {
                auto itr = hand.begin();
                advance(itr, index);
                hand.erase(itr);
            }
        }

        //Getter for hand
        list<Card*>& getHand() { return hand; }

        //Destructor
        ~Hand() {};

        //To insert all the cards in the Hand to an ostream.
        friend void print(std::ostream& out,Hand& h) {
            out << "Cards in Hand: ";
            for (auto& c : h.getHand()) {
                out << c << " ";
            }
            out << " " << std::endl;
        }



    private:
        /*Stores all the card in the players hand.*/
        list<Card*> hand;
    };


}




#endif //CSI2772_PROJECT_HAND_H;
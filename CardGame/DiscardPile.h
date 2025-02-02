//
// Created by Xiang Li on 2021-11-23.
//

#include "CardFactory.h"

#ifndef CARDGAME_DISCARDPILE_H
#define CARDGAME_DISCARDPILE_H


namespace cardgame {
    class PileEmptyException : public std::exception {
        const char *what() const noexcept override {
            return "Discard Pile empty! Taking cards failed!";
        }
    };

    class DiscardPile {
    private:
        std::vector<Card *> discardedCards;
    public:
        DiscardPile() = default;

        DiscardPile(std::istream &in, CardFactory *factory) {
            while (!in.eof()) {
                char c = (char) in.get();
                // if c is the end of current info flag
                if (c == '\n')
                    break;
                if (std::isalpha(c)) {
                    discardedCards.push_back(factory->CreateCard(c));
                }
            }
        }

        DiscardPile &operator+=(Card *card) {
            discardedCards.push_back(card);
            return *this;
        }

        //remove the top card and return
        Card *pickUp() {
            if (!discardedCards.empty()) {
                Card *pCard = discardedCards.front();
                discardedCards.erase(discardedCards.begin());
                return pCard;
            } else {
                throw PileEmptyException();
            }
        }

        //return the top card but not remove
        Card *top() {
            if (!discardedCards.empty()) {
                return discardedCards.front();
            } else {
                throw PileEmptyException();
            }
        }

        bool empty() { return discardedCards.empty(); }

        void print(std::ostream &out) {
            for (auto &card: discardedCards) {
                card->print(out);
            }
        }

        friend std::ostream &operator<<(std::ostream &out, DiscardPile &dp) {
            try {
                out << dp.top()->getName() << std::endl;
            } catch (PileEmptyException &e) {
                out << "---Discard Pile is empty" << std::endl;
            }

            return out;
        }

    };
}

#endif //CARDGAME_DISCARDPILE_H

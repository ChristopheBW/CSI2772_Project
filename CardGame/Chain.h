//
// Created by Xiang Li on 2021-11-21.
//
#include "Card.h"

#ifndef CARDGAME_CHAIN_H
#define CARDGAME_CHAIN_H

namespace cardgame {
    class IllegalType : public std::exception {
        const char *what() const noexcept {
            return "Try to put different cards in the same chain";
        }
    };


    class Chain_Base {
    protected:
        //virtual void insertCard(Card*) = 0;
        std::vector<Card *> cardChain;

        bool addCard(Card *card) {
            if (cardChain.empty() || typeid(*card) == typeid(*(cardChain.front()))) {
                cardChain.push_back(card);
                return true;
            } else {
                return false;
            }
        }


    public:
        virtual void print(std::ostream &) const = 0;

        //virtual int sell() = 0;
        friend std::ostream &operator<<(std::ostream &out, const Chain_Base &chain) {
            if (!chain.cardChain.empty()) {
                out << (chain.cardChain.at(0))->getName() << "\t";
                for (auto &card: chain.cardChain) {
                    card->print(out);
                    out << " ";
                }
            }
            out << std::endl;
            return out;
        };

        virtual int sell() = 0;

        virtual Chain_Base &operator+=(Card *) = 0;


    };


    template<class T>
    class Chain : public Chain_Base {
    public:
        //Default constructor
        Chain() = default;

        /*Constructor*/
        Chain(std::istream &in, CardFactory *factory) {
            while (!in.eof()) {
                char c = (char) in.get();
                if (c == ' ')
                    return;
                if (std::isalpha(c)) {
                    if (!this->addCard(factory->CreateCard(c))) {
                        throw IllegalType();
                    }
                    //cardChain.push_back();
                }
            }
        }

        Chain<T> &operator+=(Card *card) {
            if (this->addCard(card)) {
                return *this;
            } else {
                throw IllegalType();
            }
        }

        int sell() {
            T card;
            int ret = 0;
            int length = cardChain.size();
            while (length >= card.getCardsPerCoin(1)) {
                for (int coin = 4; coin > 0; --coin) {
                    if (length >= card.getCardsPerCoin(coin)) {
                        length -= card.getCardsPerCoin(coin);
                        ret += coin;
                        break;
                    }
                }
            }
            return ret;
        }

        void print(std::ostream &out) const override {
            if (!cardChain.empty()) {
                for (auto &card : cardChain) {
                    card->print(out);
                }
            }
        }
    };
}

#endif //CARDGAME_CHAIN_H

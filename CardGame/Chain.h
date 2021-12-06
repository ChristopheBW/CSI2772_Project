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
            return card.getCoinsWithCards(cardChain.size());
        }

        void print(std::ostream &out) const override {
            if (!cardChain.empty()) {
                for (auto &card : cardChain) {
                    card->print(out);
                }
            }
        }
    };

    inline Chain_Base *createChain(char name, std::istream &in, CardFactory *factory) {
        Chain_Base *chain;

        // match the first char of the card name with
        switch (name) {
            case 'B':
                chain = new Chain<Blue>(in, factory);
                break;
            case 'C':
                chain = new Chain<Chili>(in, factory);
                break;
            case 'S':
                chain = new Chain<Stink>(in, factory);
                break;
            case 'G':
                chain = new Chain<Green>(in, factory);
                break;
            case 's':
                chain = new Chain<Soy>(in, factory);
                break;
            case 'b':
                chain = new Chain<Black>(in, factory);
                break;
            case 'R':
                chain = new Chain<Red>(in, factory);
                break;
            case 'g':
                chain = new Chain<Garden>(in, factory);
                break;
            default: // if this char is not defined in our Card
                // then the given argument is invalid, throw exception
                throw std::invalid_argument("This card name is not defined in the game!");
        }

        return chain;
    }
}

#endif //CARDGAME_CHAIN_H

//
// Created by Xiang Li on 2021-11-21.
//
#include "Card.h"
#ifndef CARDGAME_CHAIN_H
#define CARDGAME_CHAIN_H



namespace cardgame {
    class IllegalType : public std::exception {
        const char * what() const throw () {
            return "Try to put different cards in the same chain";
        }
    };


    class Chain_Base {
        protected:
            //virtual void insertCard(Card*) = 0;
            std::vector<Card*> cardChain;
            bool addCard(Card* card) {
                if (cardChain.size() == 0 || typeid(*card) == typeid(*(cardChain.front()))) {
                    cardChain.push_back(card);
                    return true;
                }
                else {
                    return false;
                }
            }

            virtual void printChain(std::ostream&) const  = 0;

        public:
            //virtual int sell() = 0;
            friend std::ostream& operator << (std::ostream& out, const Chain_Base& chain) {
                chain.printChain(out);
                return out;
            };

            virtual int sell() = 0;

            virtual Chain_Base& operator += (Card*) = 0;


    };


    template<class T>
    class Chain : public Chain_Base {
        protected:
            void printChain(std::ostream& out) const override {
                if (cardChain.size() > 0) {
                    for (auto& card : this->cardChain) {
                        out << card->getName() << " ";
                    }
                }
                out << std::endl;
            }


        public:
            //Default constructor
            Chain() = default;

            /*Constructor*/
            Chain(std::istream &in, CardFactory *factory) {
                while (!in.eof()) {
                    char c = (char) in.get();
                    if (std::isalpha(c)) {
                        if(!this->addCard(factory->CreateCard(c))) {
                            throw IllegalType();
                        }
                        //cardChain.push_back();
                    }
                }
            }

            Chain<T>& operator += (Card* card) {
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


    };
}

#endif //CARDGAME_CHAIN_H

/**
 * Player.h
 *
 * This file is part of CardGame
 * Developed for the CSI2772A Group32 Project.
 *
 * This header include the class 'Player'
 *
 * Created by Bowen Zeng in Nov 8 2021
 */

#ifndef CARDGAME_PLAYER_H // header file OVR guard
#define CARDGAME_PLAYER_H // define guard

#include <exception>
#include <vector>
#include "CardFactory.h" // include factory class for the reconstruction
#include "Chain.h"
#include "Hand.h"

namespace cardgame // namespace declaration
{
    class NotEnoughCoins : public std::exception {
        const char *what() const noexcept override {
            return "The player does not have enough coins.";
        }
    };

    class Player {
    public:
        // constructor
        explicit Player(const std::string &name) : _name(name), _coins(0), _bThirdChain(false), _hand() {}

        Player(std::istream &in, CardFactory *factory) {
            in >> _name;
            in >> _coins;
            in >> _bThirdChain;
            in.get();

            while (!in.eof()) {
                char c = (char) in.get();

                if (c == ' ')
                    break;
                if (std::isalpha(c)) {
                    _hand += factory->CreateCard(c);
                }
            }

            while (!in.eof()) {
                Chain_Base *chain;
                char c = (char) in.get();

                // match the first char of the card name with
                switch (c) {
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

                *chain += factory->CreateCard(c);
                _chains.push_back(chain);
            }
        }

        std::string getName() const { return _name; }

        int getNumCoins() const { return _coins; }

        Player &operator+=(int income) {
            _coins += 1;
            return *this;
        }

        int getMaxNumChains() const { return _bThirdChain ? 3 : 2; }

        int getNumChains() const { return (int) _chains.size(); }

        Chain_Base &operator[](int i) {
            return *_chains.at(i);
        }

        void buyThirdChain() {
            if (_coins < 3) {
                throw NotEnoughCoins();
            } else {
                _coins -= 2;
                _bThirdChain = true;
            }
        }

        void printHand(std::ostream &os, bool bOnlyTop) {
            if (bOnlyTop) {
                os << _hand.top();
            } else {
                os << _hand;
            }
        }

        void printChains(std::ostream &out) {
            for (auto &chain : _chains) {
                out << *chain;
            }
        }

        /**
         * An example of the player save file:
         *  Dave 10 0 CgbRG RRR BB
         *
         * @param os
         */
        void save(std::ostream &os) {
            os << _name << ' ' << _coins << ' ' << _bThirdChain << ' ';
            _hand.print(os);
            for (auto &chain : _chains) {
                os << ' ';
                chain->print(os);
            }
        }

        friend std::ostream &operator<<(std::ostream &out, Player &player) {
            out << player.getName() << '\t' << player.getNumCoins() << " coins" << std::endl;
            player.printChains(out);
            return out;
        }

    private:
        std::string _name;
        int _coins;
        bool _bThirdChain;
        Hand _hand;
        std::vector<Chain_Base*> _chains;
    };
}

#endif //CARDGAME_PLAYER_H

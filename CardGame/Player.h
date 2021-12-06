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

#include <iostream>
#include <sstream>
#include <exception> // derive our new exception
#include <utility> // include std::move() instead of using 'const string &'
#include <vector> // store chains


namespace cardgame // namespace declaration
{
    class NotEnoughCoins : public std::exception {
        const char *what() const noexcept override {
            return "The player does not have enough coins.";
        }
    };

    class ThirdChainExist : public std::exception {
        const char *what() const noexcept override {
            return "The player already buy the third chain slot!.";
        }
    };

    class Player {
    public:
        /**
         * Constructor by using name
         * @param name the name string
         */
        explicit Player(std::string name) : _name(std::move(name)), _coins(0), _bThirdChain(false), _hand() {}

        /**
         * Constructor, reconstruct Player from file
         * @param in input stream contains reconstruct data
         * @param factory a pointer point to the CardFactory
         */
        Player(std::istream &in, CardFactory *factory) {
            // basic info reconstruction (name, coins, have third chain or not)
            in >> _name;
            in >> _coins;
            in >> _bThirdChain;
            in.get();

            // hands info reconstruction
            while (!in.eof()) {
                char c = (char) in.get();

                // ' ' means we are at the end of the hand, stop read stream
                if (c == ' ')
                    break;
                if (std::isalpha(c)) {
                    _hand += factory->CreateCard(c);
                }
            }

            // chains info reconstruction
            while (!in.eof()) {
                // get the card type of the chain
                char c = (char) in.get();

                // if c is the end of current info flag
                if (c == '\n')
                    break;

                Chain_Base *chain = createChain(c, in, factory);

                // insert the last card
                *chain += factory->CreateCard(c);
                // add it to the chains
                _chains.push_back(chain);
            }

        }

        /**
         * Get the name of player
         * @return the name of player
         */
        std::string getName() const { return _name; }

        /**
         * Get the current coins player have
         * @return the current coins player have
         */
        int getNumCoins() const { return _coins; }

        int getNumCardInHand() const { return _hand.getNumCard(); }

        Player &operator+=(int income) {
            _coins += income;
            return *this;
        }

        /**
         * Get the max chains player could have
         * @return the max chains player could have
         */
        int getMaxNumChains() const { return _bThirdChain ? 3 : 2; }

        /**
         * Get the current chains player have
         * @return the current chains player have
         */
        int getNumChains() const { return (int) _chains.size(); }

        /**
         * Index operator of the player
         * @param i index of the chains
         * @return the chain at index i
         */
        Chain_Base &operator[](int i) {
            return *_chains.at(i);
        }

        /**
         * Buy the third chain for player.
         * If player already have third chain then throw ThirdChainExist exception
         * If player doesn't have enough coins then throw NotEnoughCoins exception
         * If everything OK then reduce player's coins by 2 and add the third chain
         */
        void buyThirdChain() {
            if (_bThirdChain) { // if player already have the third chain
                throw ThirdChainExist();
            }
            if (_coins < 2) { // if player doesn't have enough coins
                throw NotEnoughCoins();
            } else { // everything OK
                _coins -= 2; // reduce player's coins by 2
                _bThirdChain = true; // set third chain flag to TRUE
            }
        }

        void play(CardFactory *factory) {
            Card *topmost = _hand.play();
            if (topmost == nullptr) {
                std::cout << "[Hand Error] Hand is empty!";
            } else {
                addToChains(topmost, factory);
            }
        }

        Card *discardCard(int index) { return _hand[index]; }

        /**
         * Prints the top card of the player's hand (with argument false) or all of
         * the player's hand (with argument true) to the supplied ostream.
         * @param out output stream
         * @param bOnlyTop true if only want print the top card
         */
        void printHand(std::ostream &out, bool bOnlyTop) {
            if (bOnlyTop) {
                out << _hand.top()->getName();
            } else {
                out << _hand;
            }
        }

        /**
         * Check if hand is empty
         * @return true if hand is empty
         */
        bool emptyHand() {
            return _hand.getNumCard() == 0;
        }

        /**
         * Add a card to hand
         * @param c card pointer
         */
        void addToHand(Card *c) {
            _hand += c;
        }

        /**
         * Add a card to chains, if no chains is available
         * then ask for sell an old chain
         * @param c card pointer
         * @param factory card factory pointer
         */
        void addToChains(Card *c, CardFactory *factory) {
            for (auto &chain: _chains) {
                try {
                    *chain += c;
                    return;
                } catch (const IllegalType &e) {}
            }

            // if not match any chain
            if (getMaxNumChains() > getNumChains()) { // if player has empty chain
                std::string s(1, (c->getName()).at(0));
                std::istringstream in(s);
                Chain_Base *chain = createChain((c->getName()).at(0), in, factory);
                _chains.push_back(chain);
            } else { // if player need to sell a chain to add this card
                std::cout << "[Chain Info]" << std::endl;
                printChains(std::cout);
                std::cout << std::endl;

                while (true) {
                    std::cout << "[Chain - Sold Request] Choice a chain to be tied and sold. "
                                 "(Please enter the index of chain like 1, 2 or 3)" << std::endl;
                    int index;
                    std::cin >> index;

                    if (index < 1 || index > getMaxNumChains()) { // if index is illegal
                        std::cout << "[Input Error] The chain with the specified index was not found!" << std::endl;
                    } else {
                        Chain_Base *chain = _chains.at(index - 1);
                        _chains.erase(_chains.begin() + index - 1);

                        _coins += chain->sell();
                        std::string s(1, (c->getName()).at(0));
                        std::istringstream in(s);
                        _chains.push_back(createChain((c->getName()).at(0), in, factory));

                        return;
                    }
                }

            }
        }

        /**
         * Print all player's chains to output stream
         * @param out output stream
         */
        void printChains(std::ostream &out) {
            int i = 0;
            for (auto &chain: _chains) {
                out << ++i << ": " << *chain;
            }
        }

        /**
         * An example of the player save file:
         *  Dave 10 0 CgbRG RRR BB
         *
         * @param out output stream
         */
        void save(std::ostream &out) {
            out << _name << ' ' << _coins << ' ' << _bThirdChain << ' ';
            _hand.print(out);
            out << ' ';
            for (auto &chain: _chains) {
                chain->print(out);
                out << ' ';
            }

            out << '\n';
        }

        /**
         * Insertion operator which print all info of the player
         * @param out output stream
         * @param player the player to be display
         * @return output stream after insert player's info
         */
        friend std::ostream &operator<<(std::ostream &out, Player &player) {
            out << player.getName() << '\t' << player.getNumCoins() << " coins" << std::endl;
            player.printChains(out);
            return out;
        }

    private:
        std::string _name;                 // the name of the player
        int _coins{};                      // the coins that player has
        bool _bThirdChain{};               // player has third chain or not
        Hand _hand;                        // card in hand of the player
        std::vector<Chain_Base *> _chains; // all chains that player has
    };
}

#endif //CARDGAME_PLAYER_H

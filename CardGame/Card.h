/**
 * Card.h
 *
 * This file is part of CardGame
 * Developed for the CSI2772A Group32 Project.
 *
 * This header include the base class 'Card' and all of its derived classes.
 *
 * Created by Bowen Zeng in Nov 7 2021
 */


#ifndef CARDGAME_CARD_H // header file OVR guard
#define CARDGAME_CARD_H // define guard

#include <ostream>   // support ostream operation
#include <stdexcept> // support std exceptions
#include <string>    // support string operation

namespace cardgame // namespace declaration

{
    // Base class for all Card, abstract
    class Card {
    public:
        /**
         * A virtual method to obtain how many cards are necessary to receive
         * the corresponding number of coins.
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        virtual int getCardsPerCoin(int coins) const = 0;

        /**
         * A virtual method return the full name of bean card
         * like "Blue", "Red" ...etc defined in the card game
         *
         * @return the name of the card
         */
        virtual std::string getName() const = 0;

        /**
         * A virtual method inserts the first character for the card into
         * the output stream supplied as argument.
         *
         * @param out the output stream
         */
        virtual void print(std::ostream &out) const = 0;
    };

    // derived class: Blue
    class Blue : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 4;
                case 2:
                    return 6;
                case 3:
                    return 8;
                case 4:
                    return 10;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Blue")
         */
        std::string getName() const override {
            return "Blue";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'B' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'B';
        }
    };

    // derived class: Chili
    class Chili : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 3;
                case 2:
                    return 6;
                case 3:
                    return 8;
                case 4:
                    return 9;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Chili")
         */
        std::string getName() const override {
            return "Chili";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'C' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'C';
        }
    };

    // derived class: Stink
    class Stink : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 3;
                case 2:
                    return 5;
                case 3:
                    return 7;
                case 4:
                    return 8;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Stink")
         */
        std::string getName() const override {
            return "Stink";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'S' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'S';
        }
    };

    // derived class: Green
    class Green : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 3;
                case 2:
                    return 5;
                case 3:
                    return 6;
                case 4:
                    return 7;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Green")
         */
        std::string getName() const override {
            return "Green";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'G' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'G';
        }
    };

    // derived class: Soy
    class Soy : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 2;
                case 2:
                    return 4;
                case 3:
                    return 6;
                case 4:
                    return 7;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Soy")
         */
        std::string getName() const override {
            return "Soy";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 's' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 's';
        }
    };

    // derived class: Black
    class Black : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 2;
                case 2:
                    return 4;
                case 3:
                    return 5;
                case 4:
                    return 6;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Black")
         */
        std::string getName() const override {
            return "Black";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'b' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'b';
        }
    };

    // derived class: Red
    class Red : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 1:
                    return 2;
                case 2:
                    return 3;
                case 3:
                    return 4;
                case 4:
                    return 5;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Red")
         */
        std::string getName() const override {
            return "Red";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'R' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'R';
        }
    };

    // derived class: Garden
    class Garden : public Card {
    public:
        /**
         * Implementation of the virtual method defined in Card
         *
         * @param coins the number of coins wish to be received
         * @return number of cards necessary to receive the corresponding number of coins.
         */
        int getCardsPerCoin(int coins) const override {
            // match coins with the table (represented in the instruction file)
            switch (coins) {
                case 2:
                    return 2;
                case 3:
                    return 3;
                default: // if the coins doesn't define in the table
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("The given coins is out of game definition!");
            }
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * @return the name of the card (in this class is "Garden")
         */
        std::string getName() const override {
            return "Garden";
        }

        /**
         * Implementation of the virtual method defined in Card
         *
         * In this class we insert 'g' to the output stream
         *
         * @param out the output stream
         */
        void print(std::ostream &out) const override {
            out << 'g';
        }
    };

    /**
     * Global stream insertion operator for printing any objects of Card
     *
     * @param os the output stream
     * @param c the card to insert in the stream
     * @return the stream inserted
     */
    std::ostream &operator<<(std::ostream &os, const Card &c) {
        c.print(os);
        return os;
    }

} // namespace cardgame

#endif //CARDGAME_CARD_H

/**
 * CardFactory.h
 *
 * This file is part of CardGame
 * Developed for the CSI2772A Group32 Project.
 *
 * This header include the factory class 'CardFactory'
 *
 * Created by Bowen Zeng in Nov 8 2021
 */

#ifndef CARDGAME_CARDFACTORY_H // header file OVR guard
#define CARDGAME_CARDFACTORY_H // define guard

#include "Card.h" // include base class 'Card' and all of its derived classes

namespace cardgame // namespace declaration
{
    // Factory class for Card
    class CardFactory {
    public:
        /**
         * A method to obtain the only instance of CardFactory.
         *
         * This is a factory class, only one instance can ever be instantiated.
         *
         * So CardFactory should **NOT** be created as an object like:
         *   CardFactory cardFactory(); // ERROR! private constructor
         *
         * When you want to obtain the only instance of this factory,
         * the correct usage is:
         *   CardFactory::getFactory()
         * for example:
         *   CardFactory *pCardFactory = CardFactory::getFactory();
         * then pCardFactory is the pointer to the only instance
         *
         * @return a pointer to the only instance of CardFactory
         */
        static CardFactory *getFactory() {
            static CardFactory cardFactory;
            return &cardFactory;
        }

        /**
         * A method create single card with the correspond card name
         *
         * @param name the first char of the card name
         * If the first character is the same for two cards,
         * use uppercase for the first one and lowercase for the second one
         * (For example B for Blue and b for Black).
         * @return a pointer to the created card
         */
        static Card *CreateCard(char name) {
            Card *card;

            // match the first char of the card name with
            switch (name) {
                case 'B':
                    card = new Blue;
                    break;
                case 'C':
                    card = new Chili;
                    break;
                case 'S':
                    card = new Stink;
                    break;
                case 'G':
                    card = new Green;
                    break;
                case 's':
                    card = new Soy;
                    break;
                case 'b':
                    card = new Black;
                    break;
                case 'R':
                    card = new Red;
                    break;
                case 'g':
                    card = new Garden;
                    break;
                default: // if this char is not defined in our Card
                    // then the given argument is invalid, throw exception
                    throw std::invalid_argument("This card name is not defined in the game!");
            }

            return card;
        }

    private:

    };
}

#endif //CARDGAME_CARDFACTORY_H

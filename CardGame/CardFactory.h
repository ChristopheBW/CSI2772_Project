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
         * So CardFactory should NOT be created as an object like:
         *   CardFactory cardFactory();
         * because the constructor is private (RunTimeError), or
         *   CardFactory *pCardFactory = CardFactory::getFactory()
         * because of it will return a static object (Bad habit).
         *
         * When you want to obtain the only instance of this factory,
         * the correct usage is:
         *   CardFactory::getFactory()
         * as a statement directly, for example, to create a new card Blue:
         * Card *card = cardgame::CardFactory::CreateCard('B');
         *
         * @return a pointer to the only instance of CardFactory
         */
        static CardFactory *getFactory() {
            static CardFactory cardFactory;
            return &cardFactory;
        }

        static Card *CreateCard(char name) {
            Card *card;

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
                default:
                    throw std::invalid_argument("This card name is not defined in the game!");
            }

            return card;
        }

    private:
        CardFactory() = default;

        // CardFactory &operator=(const CardFactory &) { return *this; }

    };
}

#endif //CARDGAME_CARDFACTORY_H

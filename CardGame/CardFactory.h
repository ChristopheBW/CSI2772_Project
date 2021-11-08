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
    enum Bean {
        Bean_Blue,
        Bean_Chili,
        Bean_Stink,
        Bean_Green,
        Bean_Soy,
        Bean_Black,
        Bean_Red,
        Bean_Garden
    };

    class CardFactory {
    };
}

#endif //CARDGAME_CARDFACTORY_H

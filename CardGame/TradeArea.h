//
// Created by Xiang Li on 2021-11-14.
//

#include <iostream>
#include <list>
#include "Card.h"
#include "CardFactory.h"

#ifndef CSI2772_PROJECT_TRADEAREA_H
#define CSI2772_PROJECT_TRADEAREA_H

namespace cardgame {
    typedef std::list<Card*> CardList;


    class TradeArea {
    public:
        //Default constructor
        TradeArea() = default;

        /*Constructor*/
        TradeArea(std::istream& in, const  CardFactory* factory) {
            while (!in.eof()) {
                char c = (char) in.get();
                if (std::isalpha(c)) {
                    trade_area.push_back(CardFactory::CreateCard(c));
                }
            }
        }

        /*Adds a card to the TradeArea*/
        TradeArea& operator+=(Card* card) {
            trade_area.push_back(card);
            return *this;
        }
        /*Returns true if the card can be leaglly added to the Trade Area*/
        bool legal(Card* card) {
            for (Card* c : trade_area) {
                if (c->getName() == card->getName()) {
                    return true;
                }
            }
            return false;
        }
        /*Removes a card of the corresonding bean name from the trade Area*/
        Card* trade(std::string name) {
            Card* pCard = nullptr;
            for (CardList::iterator iter = trade_area.begin(); iter != trade_area.end(); ++iter) {
                if ((*iter)->getName() == name) {
                    pCard = (*iter);
                    trade_area.erase(iter);
                }
            }
            return pCard;
        }
        /*Number of cards currently in the trade Area.*/
        int numCards() {
            return trade_area.size();
        }
        /*Returns all the cards in the TradeArea*/
        CardList getTradeArea() { return trade_area; };
        /*Destructor*/
        ~TradeArea() {};
        /*To insert all cards in the TradeArea to an ostream.*/
        friend void print(std::ostream& out, TradeArea& td) {
            cout << "Trade Area [ ";
            for (auto v : td.trade_area) {
                v->print(out);
            }
            cout << " ]" << endl;
        }

    private:
        /*Stores all the card in the TradeArea.*/
        CardList trade_area;
    };

}




#endif //CSI2772_PROJECT_TRADEAREA_H

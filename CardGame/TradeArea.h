//
// Created by Xiang Li on 2021-11-14.
//

#include <iostream>
#include <list>

#ifndef CSI2772_PROJECT_TRADEAREA_H
#define CSI2772_PROJECT_TRADEAREA_H

namespace cardgame {

    class TradeArea {
    public:
        //Default constructor
        TradeArea() = default;

        /*Constructor*/
        TradeArea(std::istream &in, CardFactory *factory) {
            while (!in.eof()) {
                char c = (char) in.get();
                // if c is the end of current info flag
                if (c == '\n')
                    break;
                if (std::isalpha(c)) {
                    trade_area.push_back(factory->CreateCard(c));
                }
            }
        }

        /*Adds a card to the TradeArea*/
        TradeArea &operator+=(Card *card) {
            trade_area.push_back(card);
            return *this;
        }

        /*Returns true if the card can be legally added to the Trade Area*/
        bool legal(Card *card) {
            for (Card *c: trade_area) {
                if (c->getName() == card->getName()) {
                    return true;
                }
            }
            return false;
        }

        /*Removes a card of the corresponding bean name from the trade Area*/
        Card *trade(const std::string &name) {
            Card *pCard = nullptr;

            for (auto iter = trade_area.begin(); iter != trade_area.end(); ++iter) {
                if ((*iter)->getName() == name) {
                    pCard = *iter;
                    trade_area.erase(iter);
                    break;
                }
            }

            return pCard;
        }

        /*Number of cards currently in the trade Area.*/
        int numCards() {
            return trade_area.size();
        }

        /*Returns all the cards in the TradeArea*/
        std::list<Card *> getTradeArea() { return trade_area; };

        /*Destructor*/
        ~TradeArea() {
            trade_area.~list();
        };

        void print(std::ostream &out) {
            for (auto &card: trade_area) {
                card->print(out);
            }
        }

        /*To insert all cards in the TradeArea to an ostream.*/
        friend std::ostream &operator<<(std::ostream &out, TradeArea &td) {
            out << "Trade Area [ ";

            for (auto &v: td.trade_area) {
                out << *v << ' ';
            }

            out << " ]" << std::endl;

            return out;
        }

    private:
        /*Stores all the card in the TradeArea.*/
        std::list<Card *> trade_area;
    };

}


#endif //CSI2772_PROJECT_TRADEAREA_H

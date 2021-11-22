//
// Created by Xiang Li on 2021-11-23.
//

#ifndef CARDGAME_TABLE_H
#define CARDGAME_TABLE_H

using namespace cardgame;

class Table {
private:
    Player* player1;
    Player* player2;
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;

public:
    Table(std::string& name1, std::string& name2, CardFactory* factory) {
        player1 = new Player(name1);
        player2 = new Player(name2);
        deck = factory->getDeck();
        discardPile = new DiscardPile();
        tradeArea = new TradeArea();
    }

    Table(std::istream& in, CardFactory* factory) {
        player1 = new Player(in, factory);
        player2 = new Player(in, factory);
        deck = new Deck(in, factory);
        discardPile = new DiscardPile(in, factory);
        tradeArea = new TradeArea(in, factory);
    }

    TradeArea* getTradeArea() {
        return tradeArea;
    }

    DiscardPile* getDiscardPile() {
        return discardPile;
    }

    Player* getPlayer(int id) {
        switch (id) {
            case 1:
                return player1;
            case 2:
                return player2;
            default:
                throw std::invalid_argument("player does not exist.");
        }
    }

    bool win(std::string& name) {
        if (!deck.empty()) {
            return false;
        }
        if (player1->getNumCoins() >= player2->getNumCoins()) {
            return player1.getName() == name;
        } else {
            return player2.getName() == name;
        }
    }

    void printHand(bool printAll) {
        std::cout << player1->getName << ": ";
        player1->printHand(std::cout, printAll);

        std::cout << player2->getName << ": ";
        player2->printHand(std::cout, printAll);
    }

    std::ostream& operator << (std::ostream& out, Table& t) {
        out << "Player1:" << std::endl << *(t.player1) << std::endl;
        out << "Player2:" << std::endl << *(t.player2) << std::endl;
        out << "Deck:" << std::endl << *(t.deck) << std::endl;
        out << "Discard Pile:" << std::endl << *(t.discardPile) << std::endl;
        out << "Trade Area:" << std::endl << *(t.tradeArea) << std::endl;
        return out;
    }
};




#endif //CARDGAME_TABLE_H

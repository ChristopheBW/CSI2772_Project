#include <iostream>
#include <fstream>
#include "Card.h"
#include "CardFactory.h"
#include "TradeArea.h"

using namespace cardgame;
using namespace std;

int main() {
    CardFactory *pCardFactory = CardFactory::getFactory();
    CardFactory::Deck deck{};

    deck.push_back(pCardFactory->CreateCard('b'));
    deck.push_back(pCardFactory->CreateCard('B'));
    deck.push_back(pCardFactory->CreateCard('C'));
    deck.push_back(pCardFactory->CreateCard('R'));
    deck.push_back(pCardFactory->CreateCard('g'));

    ofstream outfile;
    outfile.open("save.txt");
    outfile << deck;
    outfile.close();

    ifstream infile;
    infile.open("save.txt");

    TradeArea *tradeArea = new TradeArea(infile, pCardFactory);
    cout << *tradeArea << endl;


    Card *d1 = tradeArea->trade("Blue");


    if (d1 == nullptr)
        cout << "NULL" << endl;
    cout << d1->getName() << endl;


    cout << tradeArea->numCards() << endl;


    return 0;
}

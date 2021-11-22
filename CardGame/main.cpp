#include <iostream>
#include <fstream>
#include "Card.h"
#include "CardFactory.h"
#include "TradeArea.h"
#include "Hand.h"
#include "Chain.h"

using namespace cardgame;
using namespace std;

int main() {
    CardFactory *pCardFactory = CardFactory::getFactory();
    CardFactory::Deck deck{};

//    deck.push_back(pCardFactory->CreateCard('b'));
//    deck.push_back(pCardFactory->CreateCard('B'));
//    deck.push_back(pCardFactory->CreateCard('C'));
//    deck.push_back(pCardFactory->CreateCard('R'));
//    deck.push_back(pCardFactory->CreateCard('g'));

    deck.push_back(pCardFactory->CreateCard('b'));
    deck.push_back(pCardFactory->CreateCard('b'));
    deck.push_back(pCardFactory->CreateCard('b'));
    deck.push_back(pCardFactory->CreateCard('b'));
    deck.push_back(pCardFactory->CreateCard('b'));

    for (int i = 0; i < 20; ++i) {
        deck.push_back(pCardFactory->CreateCard('b'));
    }

    ofstream outfile;
    outfile.open("save.txt");
    outfile << deck;
    outfile.close();

    ifstream infile;
    infile.open("save.txt");

    Chain_Base* chain = new Chain<Black>(infile, pCardFactory);
    *chain += pCardFactory->CreateCard('b');
    cout << *chain;
    cout << chain->sell() << endl; //should sell 17 coins


//    Card *c = hand->play();
//
//    cout << (*hand)[2]->getName() << endl;
//
//    cout << *hand << endl;

    infile.close();
    return 0;
}
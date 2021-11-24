#include <iostream>
#include <fstream>
#include "Card.h"
#include "CardFactory.h"
#include "TradeArea.h"
#include "Hand.h"
#include "Chain.h"
#include "DiscardPile.h"
#include "Player.h"

using namespace cardgame;
using namespace std;

int main() {
    CardFactory *pCardFactory = CardFactory::getFactory();
    CardFactory::Deck deck{};


    //Code to test Chain
//    deck.push_back(pCardFactory->CreateCard('b'));
//    deck.push_back(pCardFactory->CreateCard('b'));
//    deck.push_back(pCardFactory->CreateCard('b'));
//    deck.push_back(pCardFactory->CreateCard('b'));
//    deck.push_back(pCardFactory->CreateCard('b'));
//
//    for (int i = 0; i < 20; ++i) {
//        deck.push_back(pCardFactory->CreateCard('b'));
//    }
//
//    ofstream outfile;
//    outfile.open("save.txt");
//    outfile << deck;
//    outfile.close();
//
//    ifstream infile;
//    infile.open("save.txt");
//
//    Chain_Base* chain = new Chain<Black>(infile, pCardFactory);
//    *chain += pCardFactory->CreateCard('b');
//    cout << *chain;
//    cout << chain->sell() << endl; //should sell 17 coins
//
//    infile.close();



    //Code to test DiscardPile


    //for (int i = 0; i < 4; ++i) {
    //deck.push_back(pCardFactory->CreateCard('R'));
    //}

    //ofstream outfile;
    //outfile.open("save.txt");
    //outfile << deck;
    //outfile.close();

    //ifstream infile;
    //infile.open("save.txt");

    ifstream player_file;
    // text in the player_save0.txt: Dave 10 0 CgbRG RRR BB
    player_file.open("player_save0.txt");
    Player *player = new Player(player_file, pCardFactory);
    player_file.close();

    player->printHand(cout, false);

    cout << *player << player->getMaxNumChains() << endl << player->getNumChains() << endl;
    player->buyThirdChain();
    cout << *player << player->getMaxNumChains() << endl << player->getNumChains() << endl;

    ofstream player_save;
    player_save.open("player_save1.txt");
    player->save(player_save);
    player_save.close();

    // text in the player_save1.txt should be : Dave 8 1 CgbRG RRR BB

    return 0;
}
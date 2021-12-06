#include <iostream>
#include <fstream>
#include "Card.h"
#include "CardFactory.h"
#include "TradeArea.h"
#include "Hand.h"
#include "Chain.h"
#include "DiscardPile.h"
#include "Player.h"
#include "Table.h"

using namespace cardgame;
using namespace std;

int main() {
    CardFactory *pCardFactory = CardFactory::getFactory();
    Table *pTable;

    char cLoad;
    cout << "[Game Init] Load the previous game? (y/N)" << endl;
    cin >> cLoad;

    if (cLoad == 'y' || cLoad == 'Y') {
        ifstream loadFile;
        loadFile.open("save.txt");
        pTable = new Table(loadFile, pCardFactory);
        loadFile.close();
    }
    else {
        // Enter player name info
        string name1, name2;
        cout << "[Game Init] Please enter the name of Player 1 (Do not include spaces):" << endl;
        cin >> name1;
        cout << "[Game Init] Please enter the name of Player 2 (Do not include spaces):" << endl;
        cin >> name2;
        pTable = new Table(name1, name2, pCardFactory);
    }


    // Init game instances
    Player *pPlayer1 = pTable->getPlayer(1);
    Player *pPlayer2 = pTable->getPlayer(2);
    CardFactory::Deck *pDeck = pTable->getDeck();
    TradeArea *pTradeArea = pTable->getTradeArea();
    DiscardPile *pDiscardPile = pTable->getDiscardPile();

    // Init game
    for (int count = 0; count < 5; ++count) {
        pPlayer1->addToHand(pDeck->draw());
        pPlayer2->addToHand(pDeck->draw());
    }

    // Start main loop
    while (!pDeck->empty()) {
        char choice; // store user's choice
        cout << "[Save - Request] Pause and save the game? (y/N):" << endl;
        cin >> choice;

        // Save file
        if (choice == 'y' || choice == 'Y') {
            ofstream saveFile;
            saveFile.open("save.txt");
            pTable->save(saveFile);
            saveFile.close();
            cout << "[Saved] Program terminated." << endl;
            return 0;
        }

        // Playing the game
        for (int id = 1; id <= 2; ++id) {
            Player *pPlayer = pTable->getPlayer(id); // current player playing the game
            string name = pPlayer->getName(); // current player name
            cout << endl << "[" << name << " - Start Turn] Now is your turn." << endl;
            cout << "[Table Info] " << endl << *pTable << endl; // print the pTable to the screen
            Card *newCard = pDeck->draw(); // draw card
            cout << "[Draw Card] You draw the card: " << *newCard << endl;
            pPlayer->addToHand(newCard);

            // Step 1: Trade Area
            while (pTradeArea->numCards() != 0) {
                cout << "[TradeArea Info] " << *pTradeArea << endl;
                cout << "[Hand Info] ";
                pPlayer->printHand(cout, false);
                cout << endl;
                cout << "[TradeArea - Operation Request] Add or discard bean cards from the trade area? "
                        "(Type 'a' for add, 'd' for discard, others for skip change):" << endl;
                cin >> choice;
                if (choice == 'a' || choice == 'A') { // choice: add
                    cout << "[TradeArea -  Pick Card Request] Which card would you want to add to your chains? "
                            "(Please enter the full name of the card like: Blue, not B):" << endl;
                    string cardName;
                    cin >> cardName;
                    Card *c = pTradeArea->trade(cardName); // try to get the card user desire
                    if (c == nullptr) { // if the card not found
                        cout << "[TradeArea - Card Not Found] This card name doesn't match any card in the trade area!"
                             << endl;
                    } else { // card found
                        pPlayer->addToChains(c, pCardFactory); // add the card to the player's chains
                        cout << "[TradeArea Updated] " << *pTradeArea << endl;
                        cout << "[Player - Chains Updated]" << endl;
                        pPlayer->printChains(cout);
                        cout << endl;
                    }
                } else if (choice == 'd' || choice == 'D') { // choice: discard
                    cout << "[TradeArea -  Discard Card Request] Which card would you want to discard? "
                            "(Please enter the full name of the card like: Blue, not B):" << endl;
                    string cardName;
                    cin >> cardName;
                    Card *c = pTradeArea->trade(cardName); // try to get the card user desire
                    if (c == nullptr) { // if the card not found
                        cout << "[TradeArea - Card Not Found] This card name doesn't match any card in the trade area!"
                             << endl;
                    } else { // card found
                        *pDiscardPile += c; // discard it
                        cout << "[TradeArea Updated] " << *pTradeArea << endl;
                    }
                } else { // choice: don't change
                    cout << "[TradeArea - Change Completed]" << endl;
                    break;
                }
            }

            // Step 2 and 3: Play the top card
            do {
                cout << "[Hand Info] ";
                pPlayer->printHand(cout, false);
                cout << endl;

                if (pPlayer->emptyHand()) {
                    cout << "[Hand Info] Your hand is empty." << endl;
                    break;
                } else {
                    cout << "[Hand Top] Topmost card in your hand: ";
                    pPlayer->printHand(cout, true);
                    cout << endl << "[Chain - Add Card] Adding the topmost card to your chains." << endl;
                    pPlayer->play(pCardFactory); // play the top card here
                    cout << "[Chain Updated]" << endl << "[Player Info] " << *pPlayer << endl;
                }

                if (pPlayer->emptyHand()) {
                    cout << "[Hand Info] Your hand is empty." << endl;
                    break;
                } else {
                    cout << "[Hand Top] Next Topmost card in your hand: ";
                    pPlayer->printHand(cout, true);
                    cout << endl << "[Repeat Request] Repeat play your topmost card? (y/N)" << endl;
                    cin >> choice;
                }
            } while (choice == 'y' || choice == 'Y');

            // Step 4: Discard card from the hand
            cout << "[Hand Info] ";
            pPlayer->printHand(cout, false);
            cout << endl;
            choice = 'n';

            if (pPlayer->emptyHand()) {
                cout << "[Hand Info] No card can be discard." << endl;
            } else {
                cout << "[Hand - Discard Request] Would you want to discard one card from your hand? (y/N)" << endl;
                cin >> choice;
            }

            if (choice == 'y' || choice == 'Y') {
                while (true) { // loop until give a valid number
                    cout << "[Hand - Pick Discard Card] Which card would you want to discard? "
                            "(Please enter the index of card like 1, 2 or 3; 0 for cancel)" << endl;
                    int index;
                    cin >> index;

                    if (index == 0) {
                        break;
                    }

                    if (index < 1 || index > pPlayer->getNumCardInHand()) {
                        cout << "[Input Error] The chain with the specified index was not found!" << endl;
                    } else {
                        Card *discard = pPlayer->discardCard(index - 1);
                        *pDiscardPile += discard;
                        cout << "[Hand Updated] Card " << *discard << " discarded." << endl;
                        break;
                    }
                }
            }

            // Step 5: Draw card | Chain operation
            for (int count = 0; count < 3; ++count) { // draw 3 card from deck
                *pTradeArea += pDeck->draw();
            }

            while (!pDiscardPile->empty() && pTradeArea->legal(pDiscardPile->top())) {
                *pTradeArea += pDiscardPile->pickUp();
            }

            cout << "[TradeArea Info] " << *pTradeArea << endl;

            while (pTradeArea->numCards() != 0) {
                cout << "[TradeArea - Add Card Request] Would you want add card from trade area to your chains? (y/N):"
                     << endl;
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    cout << "[TradeArea -  Pick Card Request] Which card would you want to add to your chains? "
                            "(Please enter the full name of the card like: Blue, not B):" << endl;
                    string cardName;
                    cin >> cardName;
                    Card *c = pTradeArea->trade(cardName); // try to get the card user desire
                    if (c == nullptr) { // if the card not found
                        cout << "[TradeArea - Card Not Found] This card name doesn't match any card in the trade area!"
                             << endl;
                    } else { // card found
                        pPlayer->addToChains(c, pCardFactory); // add the card to the player's chains
                        cout << "[TradeArea Updated] " << *pTradeArea << endl;
                        cout << "[Player - Chains Updated]" << endl;
                        pPlayer->printChains(cout);
                        cout << endl;
                    }
                } else {
                    cout << "[TradeArea - End Adding]" << endl;
                    break;
                }
            }

            pPlayer->addToHand(pDeck->draw());
            pPlayer->addToHand(pDeck->draw());

            cout << "[Hand - Card Added] Draw 2 card from deck to your hand." << endl;
            cout << "[Hand Info] ";
            pPlayer->printHand(cout, false);
            cout << endl << "[" << name << " - End Turn] Your turn is over." << endl;

            bool bWin;
            bWin = pTable->win(name);

            if (bWin) {
                cout << "[Game Over] " << name << " win the game." << endl;
                return 0;
            }
        }

    }

    return 1;
}
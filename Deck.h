//
// Created by uzer on 02.02.2021.
//

#ifndef CARDS_DECK_H
#define CARDS_DECK_H

#include "Card.h"
#include <vector>

class Deck{
private:
    std::vector<Card> dc;

public:
    Deck();

/*    Card& operator[](int index)
    {
        return dc[index];
    }*/


    void Shuffle();

    int getSize();

    Card getCard();

};


#endif //CARDS_DECK_H

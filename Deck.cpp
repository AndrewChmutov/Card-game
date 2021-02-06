//
// Created by uzer on 02.02.2021.
//

#include "Deck.h"


    Deck::Deck()
    {
        dc.resize(g_dsize);

        for(int i = 0; i < 4; i++){

            for(int j = 0; j < 9; j++){
                dc[i * 9 + j].setMast(static_cast<Mast>(i));
                dc[i * 9 + j].setNumber(static_cast<Number>(j));
            }
        }
    }

/*    Card& operator[](int index)
    {
        return dc[index];
    }*/


    void Deck::Shuffle()
    {
        for(int i = 0; i < g_dsize; i++){
            Card* temp = new Card;
            temp->setMast(dc[i].getMast());
            temp->setNumber(dc[i].getNumber());

            int x{ rand() % g_dsize };

            dc[i] = dc[x];
            dc[x] = *temp;

            delete temp;
        }

        const Mast k = dc[g_dsize - 1].getMast();

        for(int i = 0; i < g_dsize; i++){
            if (k == dc[i].getMast()){

            }
        }

    }

    int Deck::getSize()
    {
        return dc.size();
    }

    Card Deck::getCard()
    {
        Card temp = dc[0];
        dc.erase(dc.begin());

        return temp;
    }

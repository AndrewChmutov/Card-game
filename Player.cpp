//
// Created by uzer on 02.02.2021.
//
#include "Player.h"

    Player::Player()
    {
        nr.resize(g_rsize);
    }

    Card& Player::operator[](int index)
    {
        return nr[index];
    }

    int Player::getCardsCnt()
    {
        return nr.size();
    }

    void Player::takeCard(Card take)
    {
        nr.push_back(take);
    }
    /*
    void showCards()
    {
        for(auto i = nr.begin(); i < nr.end(); i++){

            cout << getNameMast( (*i).getMast() ) << ' ' << getNameNumb( (*i).getNumber() ) << endl;
        }
    }*/

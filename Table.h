//
// Created by uzer on 02.02.2021.
//

#ifndef CARDS_TABLE_H
#define CARDS_TABLE_H

#include "Card.h"
#include "User.h"
#include "Deck.h"

class Table {
private:
    std::vector<User *> us;
    Deck d;
    Mast k;

    std::vector<Card> attack;
    std::vector<Card> defend;


    void distribution();


    void ring(int fPl);

public:
    Table();

    void addUser(User *u1);

    void play();
};




    /*//два метода для итерирования по вектору атакующих карточек
    int GetSize()                 {    return attack.size();    }
    Card& GetAttackCard(int index){    return attack[index];    }

    методы для выкладывания карточек на стол
    void PutAttack(vector<Card>& crdA)
    {
        attack = crdA;
    }
    void PutDefend(vector<Card>& crdD)
    {
        defend = crdD;
    }

    vector<Card> zagreb()
    {
        vector<Card> temp;
        temp.insert(temp.begin(), attack.begin(), attack.end());
        temp.insert(temp.end(), defend.begin(), defend.end());
        return temp;
    }

    void Clear()
    {
        attack.clear();
        defend.clear();
    }

    void distribution(Deck& d, vector<Player*>& pl)
    {
        for(int i = 0; i < pl.size(); i++){
            (*pl[i]).setCards(*this, g_rsize * i);
        }

        const int minus_cards( static_cast<int>((pl.size() + 1) * g_rsize) );
        const int new_size( static_cast<int>((d.getSize() - minus_cards) ) );


        vector<Card> temp(new_size);
        for(int i = 0; i < new_size; i++){

            temp[i] = d.dc[i + minus_cards];
        }

        d.dc = temp;

        d.trump = d.dc[g_dsize - 1].getMast();
        cout << "Trump card is " << getNameMast( d.trump ) << '.' << endl;
    }
     */



#endif //CARDS_TABLE_H

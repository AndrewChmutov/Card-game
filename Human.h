//
// Created by uzer on 02.02.2021.
//

#ifndef CARDS_HUMAN_H
#define CARDS_HUMAN_H

#include "Player.h"

class Human : public Player{
public:
    Human()
    {
        nr.resize(g_rsize);
    }
/*

    void getCardFromPlayer(vector<Card>& attack)
    {
        //запрашивем пераую карточку от человека
        cout << "Card for attack: ";

        string act;
        cin.ignore();

        getline(cin, act);

        //сравниваем с имеющимся, если же
        //таковой нет, вызываем метод повторно
        bool b = false;
        for(auto i = nr.begin(); i < nr.end(); i++){

            if(act == (getNameMast( (*i).getMast() ) + getNameNumb( (*i).getNumber() ))){
                attack[0] = (*i);
                nr.erase(i);
                b = true;
                break;
            }
        }
        if(!b){
            cout << "Something went wrong!" << endl;
            getCardFromPlayer(attack);
        }

        //запрашиваем остальные карточки
        GetAnotherCard(attack);
    }

    void GetAnotherCard(vector<Card>& attack)
    {
        cout << "Add another card or press ENTER:";

        string act;
        act = "";
        cin.ignore();
        getline(cin, act);

        //если человек нажал на энтер, то мы выходим из метода
        if (act.empty())
            return;


        //тут то же, что и когда мы чекаем первую карточку
        bool b = false;
        for(int i = 0; i < nr.size(); i++){

            if((act == (getNameMast( nr[i].getMast() ) + getNameNumb( (nr[i].getNumber() )))) &&
                (nr[i].getNumber() == attack[i - 1].getNumber()))
            {
                attack.push_back( nr[i] );
                nr.erase(nr.begin() + i);
                b = true;
            }

        }

        //в любом случае, если заканчиваем цикл, вызываем повторно, но с обработкой ошибки
        if (!b){
            cout << "Something went wrong!" << endl;
        }


        GetAnotherCard(attack);
    }
*/
    void getAttack(const std::vector<Card>& c_att, std::vector<Card>& att) override
    {

    }

    void getDefence(const std::vector<Card>& att, std::vector<Card>& def) override
    {

    }

};


#endif //CARDS_HUMAN_H

//
// Created by uzer on 02.02.2021.
//

#ifndef CARDS_BOT_H
#define CARDS_BOT_H

#include "Player.h"
#include "Deck.h"

class Bot : public Player{
public:
    Bot()
    {
        nr.resize(g_rsize);
    }

    void getAttack(const std::vector<Card>& c_att, std::vector<Card>& att) override
    {
        att[0] = nr[0];

        for(auto i = nr.begin() + 1; i < nr.end(); i++){
            if( (*i).getNumber() < att[0].getNumber() ){
                att[0] = (*i);
            }
        }
    }

    void getDefence(const std::vector<Card>& att, std::vector<Card>& def) override
    {
        def.resize(att.size());

        for(auto i = att.cbegin(); i < att.cend(); i++)
        {

            for(int j = 0; j < nr.size(); j++)
            {
                if(nr[j].compare(*i))
            }
        }
    }



    void Defend(Deck& d, Table& table)
    {
        //карточки, которые мы будем выкладывать на стол
        vector<Card> def(table.GetSize());

        //если игрок может отбится, то в этом векторе будут все тру
        vector<bool> can(table.GetSize());
        for(auto el : can){
            el = false;
        }

        vector<int> indexes(table.GetSize());

        for(int i = 0; i < table.GetSize(); i++){

            def[i] = table.GetAttackCard(i);

            //если атакующая карта козырь
            if(table.GetAttackCard(i).getMast() == d.GetTrump()){
                for(int j = 0; j < nr.size(); j++){
                    if  ((nr[j].getMast() == d.GetTrump()) &&
                         (nr[j].getNumber() > table.GetAttackCard(i).getNumber()) &&
                         (nr[j].getNumber() < def[i].getNumber()) )
                    {
                        def[i] = nr[j];
                        can[i] = true;
                        indexes[i] = j;
                    }
                }
            }
            else{
                for(int j = 0; j < nr.size(); i++){
                    if  (((nr[j].getMast() == table.GetAttackCard(i).getMast()) &&
                          (nr[j].getNumber() > table.GetAttackCard(i).getNumber())) &&
                         (nr[j].getNumber() < def[i].getNumber())){
                        if((i != 1) && (def[i].getNumber() != def[i - 1].getNumber())){

                            def[i] = nr[j];
                            can[i] = true;
                            //indexes[i] = j;
                        }
                    }
                }

                if(!CheckTruth(can)){
                    for(int j = 0; j < nr.size(); i++){
                        if(nr[j].getMast() == d.GetTrump()){
                            if((i != 1) && (def[i].getNumber() != def[i - 1].getNumber())) {

                                def[i] = nr[j];
                                can[i] = true;
                                indexes[i] = j;
                            }
                        }
                    }
                }
            }
        }

        if(!CheckTruth(can)){
            vector<Card> temp;
            temp = table.zagreb();
            nr.insert(nr.end(), temp.begin(), temp.end());
            return;
        }
        else{
            for(int i = 0; i < table.GetSize(); i++){

                nr.erase(nr.begin() + indexes[i]);

            }
        }

    }

};


#endif //CARDS_BOT_H

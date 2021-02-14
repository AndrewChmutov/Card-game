//
// Created by uzer on 02.02.2021.
//

#include "Bot.h"

Bot::Bot()
{
    nr.resize(g_rsize);
    nr.resize(0);
}

void Bot::getAttack(const std::vector<Card>& c_att, std::vector<Card>& att)
{
    Card temp = nr[0];

    for(auto i = nr.begin() + 1; i < nr.end(); i++){
        if( (*i).getNumber() < temp.getNumber() ){
            temp = (*i);
        }
    }
    att.push_back(temp);
}

void Bot::getDefence(const std::vector<Card>& att, std::vector<Card>& def, const Mast& k)
{

    //Если по итогу в массиве индексов будет -1, то отбится невозможно
    std::vector<int> index(att.size(), -1);



    //В каждой итерации выбираем карточку для обороны
    for(int i = 0; i < att.size(); i++)
    {
        index[i] = 0;

        //В каждой итерации перебираем карты на руках
        for(int j = 0; j < nr.size(); j++)
        {
            //Сравниваем карты
            if ((nr[j].compare(att[i], k)) && (!nr[j].compare(nr[index[i]], k)))
            {
                //Смотрим, чтобы карты защиты не повторялись
                bool b = true;
                for (int check : index) {
                    if (check == j){
                        b = false;
                        break;
                    }
                }

                if(b){
                    index[i] = j;
                }

            }
        }
    }

    for(int& el : index)
    {
        if(el == -1)
        {
            return;
        }
    }

    std::vector<Card> nw_nr(nr.size() - att.size());

    for(int i = 0; i < nr.size(); i++)
    {
        for(int j = 0; j < att.size(); j++)
        {
            if(index[j] != i)
            {
                nw_nr[i - j] = nr[i];
            }
        }
    }

    for(int i = 0; i < att.size(); i++)
    {
        def[i] = nr[index[i]];
    }

    nr = nw_nr;


}

/*
void Bot::sortCardsFall(std::vector<Card>& v, const Mast& k)
{
    for(auto i = v.begin(); i < v.end(); i++)
    {
        Card max = v[0];
        for(auto j = v.end() - 1; j <= v.begin(); j--)
        {
            if(!max.compare(*i, k))
            {
                Card temp = max;
                max = *i;
                (*i) = temp;
            }
        }
    }
}*/

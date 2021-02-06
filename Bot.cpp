//
// Created by uzer on 02.02.2021.
//

#include "Bot.h"

Bot::Bot()
{
    nr.resize(g_rsize);
}

void Bot::getAttack(const std::vector<Card>& c_att, std::vector<Card>& att)
{
    att[0] = nr[0];

    for(auto i = nr.begin() + 1; i < nr.end(); i++){
        if( (*i).getNumber() < att[0].getNumber() ){
            att[0] = (*i);
        }
    }
}

void Bot::getDefence(const std::vector<Card>& att, std::vector<Card>& def)
{
    def.resize(att.size());

    for(auto i = att.cbegin(); i < att.cend(); i++)
    {

        for(int j = 0; j < nr.size(); j++)
        {
            if(nr[j].compare((*i), TREF)){};
        }
    }
}
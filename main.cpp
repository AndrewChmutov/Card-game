#include <iostream>
#include "global.h"
#include "Card.h"

#include "Deck.h"
#include "Bot.h"

int main()
{
    Deck d;
    d.Shuffle();
    d.Shuffle();
    Bot b;

    for(int i = 0; i < 6; i++)
    {
        b.takeCard(d.getCard());
        std::cout << getNameMast(b[i].getMast()) << " " << getNameNumb(b[i].getNumber()) << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<Card> v1;
    Card c1, c2;
    c1.setMast(PIKA);
    v1.push_back(c1);

    c2.setMast(CHERVU);
    c2.setNumber(SIX);

    v1.push_back(c2);

    std::vector<Card> v2(v1.size());

    b.getDefence(v1, v2, CHERVU);

    std::cout << std::endl;
    for(auto& el : v2)
        std::cout << getNameMast(el.getMast()) << " " << getNameNumb(el.getNumber()) << std::endl;

    return 0;
}
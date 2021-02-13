#ifndef CARDS_CARD_H
#define CARDS_CARD_H

#include "global.h"
class Card {
protected:
    Mast c_m;
    Number c_n;

    Card* c_ptr;
public:

    Card();

    Card(Mast m, Number n) : c_m(m), c_n(n){};

    void setMast(Mast m);

    Mast getMast();

    void setNumber(Number n);

    Number getNumber();


    Card& operator=(Card other);

    bool compare(const Card& other, const Mast& k);

    void choosePoint(Card* other);

    bool isFree();
};



#endif //CARDS_CARD_H

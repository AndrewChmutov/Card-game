#ifndef CARDS_PLAYER_H
#define CARDS_PLAYER_H
#include "Card.h"
#include "User.h"

class Player : public User {
protected:
    std::vector<Card> nr;
public:
    Player();

    Card& operator[](int index) override;

    int getCardsCnt() override;

    void takeCard(Card take) override;
    /*
    void showCards()
    {
        for(auto i = nr.begin(); i < nr.end(); i++){

            cout << getNameMast( (*i).getMast() ) << ' ' << getNameNumb( (*i).getNumber() ) << endl;
        }
    }*/
};


#endif //CARDS_PLAYER_H

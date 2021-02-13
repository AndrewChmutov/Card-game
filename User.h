#ifndef CARDS_USER_H
#define CARDS_USER_H
#include <vector>

class User
{
public:
    virtual void getAttack(const std::vector<Card>& c_att, std::vector<Card>& att) = 0;
    virtual void getDefence(const std::vector<Card>& att, std::vector<Card>& def, const Mast& k) = 0;
    virtual int getCardsCnt() = 0;
    virtual Card& operator[](int index) = 0;
    virtual void takeCard(Card take) = 0;
};

#endif //CARDS_USER_H

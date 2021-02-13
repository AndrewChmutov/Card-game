#include "Card.h"



    Card::Card()
    {
        c_m = TREF;
        c_n = SIX;
    }

    void Card::setMast(Mast m)
    {
        c_m = m;
    }
    Mast Card::getMast()
    {
        return c_m;
    }

    void Card::setNumber(Number n)
    {
        c_n = n;
    }
    Number Card::getNumber()
    {
        return c_n;
    }


    Card& Card::operator=(Card other)
    {
        this->c_m = other.getMast();

        this->c_n = other.getNumber();

        return (*this);
    }

    bool Card::compare(const Card& other, const Mast& k)
    {
        if(this->c_m == k){
            if(other.c_m == k){
                return (this->c_n > other.c_n);
            }
            else{
                return true;
            }
        }
        else{
            if(other.c_m == k){
                return false;
            }
            else{
                return ((this->c_n > other.c_n) && (this->c_m == other.c_m));
            }
        }
    }

    void Card::choosePoint(Card* other)
    {
        c_ptr = other;
    }

    bool Card::isFree()
    {
        return c_ptr != nullptr;
    }
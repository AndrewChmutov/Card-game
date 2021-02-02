#ifndef CARDS_GLOBAL_H
#define CARDS_GLOBAL_H


#include <string>
//количество карт в колоде
const int g_dsize = 36;
//количество карт на руках изначально
const int g_rsize = 6;


//создаю тип и номер для карточек
enum Mast{
    TREF,
    Chervu,
    Bubna,
    Pika
};
enum Number{
    SIX = 6,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    VALET,
    DAMA,
    KOROL,
    TUZ
};

//функции для вывода типа и номера на консоль
std::string getNameMast(int x)
{
    switch(x) {
        case 0:    return "TREF";
        case 1:    return "CHERVU";
        case 2:    return "BUBNA";
        case 3:    return "PIKA";
        default:   return "error";
    }
}
std::string getNameNumb(int x)
{
    switch(x) {
        case 6:    return "SIX";
        case 7:    return "SEVEN";
        case 8:    return "EIGHT";
        case 9:    return "NINE";
        case 10:    return "TEN";
        case 11:    return "VALET";
        case 12:    return "DAMA";
        case 13:    return "KOROL";
        case 14:    return "TUZ";
        default:   return "error";
    }
}



#endif //CARDS_GLOBAL_H
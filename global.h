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
std::string getNameMast(int x);
std::string getNameNumb(int x);



#endif //CARDS_GLOBAL_H
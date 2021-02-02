#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
//количество карт в колоде
const int g_dsize = 36;
//количество карт на руках изначально
const int g_rsize = 6;


using namespace std;

//прототипы
class Card;
class Deck;
class Player;
class Human;
class Bot;
class Table;


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
string getNameMast(int x)
{
    switch(x) {
        case 0:    return "TREF";
        case 1:    return "CHERVU";
        case 2:    return "BUBNA";
        case 3:    return "PIKA";
        default:   return "error";
    }
}
string getNameNumb(int x)
{
    switch(x) {
        case 0:    return "SIX";
        case 1:    return "SEVEN";
        case 2:    return "EIGHT";
        case 3:    return "NINE";
        case 4:    return "TEN";
        case 5:    return "VALET";
        case 6:    return "DAMA";
        case 7:    return "KOROL";
        case 8:    return "TUZ";
        default:   return "error";
    }
}



class Card{
protected:
    Mast c_m;
    Number c_n;

public:

    Card()
    {
        c_m = TREF;
        c_n = SIX;
    }

    Card(Mast m, Number n) : c_m(m), c_n(n)
    {}


    void setMast(Mast m)
    {
        c_m = m;
    }
    Mast getMast()
    {
        return c_m;
    }

    void setNumber(Number n)
    {
        c_n = n;
    }
    Number getNumber()
    {
        return c_n;
    }


    Card& operator=(Card other)
    {
        this->c_m = other.getMast();

        this->c_n = other.getNumber();

        return (*this);
    }

    bool compare(const Card& other, const Mast& k)
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

};
class GCard
{
private:
    Card* btn;
};

/*void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}*/

class User
{
public:
    virtual void getAttack(const vector<Card>& c_att, vector<Card>& att) = 0;
    virtual void getDefence(const vector<Card>& att, vector<Card>& def) = 0;
    virtual int getCardsCnt() = 0;
    virtual Card& operator[](int index) = 0;
    virtual void takeCard(Card take) = 0;
};


class Player : public User {
protected:
    vector<Card> nr;
public:
    Player()
    {
        nr.resize(g_rsize);
    }

    Card& operator[](int index) override
    {
        return nr[index];
    }

    int getCardsCnt() override
    {
        return nr.size();
    }

    void takeCard(Card take) override
    {
        nr.push_back(take);
    }
    /*
    void showCards()
    {
        for(auto i = nr.begin(); i < nr.end(); i++){

            cout << getNameMast( (*i).getMast() ) << ' ' << getNameNumb( (*i).getNumber() ) << endl;
        }
    }*/
};


class Human : public Player{
public:
    Human()
    {
        nr.resize(g_rsize);
    }
/*

    void getCardFromPlayer(vector<Card>& attack)
    {
        //запрашивем пераую карточку от человека
        cout << "Card for attack: ";

        string act;
        cin.ignore();

        getline(cin, act);

        //сравниваем с имеющимся, если же
        //таковой нет, вызываем метод повторно
        bool b = false;
        for(auto i = nr.begin(); i < nr.end(); i++){

            if(act == (getNameMast( (*i).getMast() ) + getNameNumb( (*i).getNumber() ))){
                attack[0] = (*i);
                nr.erase(i);
                b = true;
                break;
            }
        }
        if(!b){
            cout << "Something went wrong!" << endl;
            getCardFromPlayer(attack);
        }

        //запрашиваем остальные карточки
        GetAnotherCard(attack);
    }

    void GetAnotherCard(vector<Card>& attack)
    {
        cout << "Add another card or press ENTER:";

        string act;
        act = "";
        cin.ignore();
        getline(cin, act);

        //если человек нажал на энтер, то мы выходим из метода
        if (act.empty())
            return;


        //тут то же, что и когда мы чекаем первую карточку
        bool b = false;
        for(int i = 0; i < nr.size(); i++){

            if((act == (getNameMast( nr[i].getMast() ) + getNameNumb( (nr[i].getNumber() )))) &&
                (nr[i].getNumber() == attack[i - 1].getNumber()))
            {
                attack.push_back( nr[i] );
                nr.erase(nr.begin() + i);
                b = true;
            }

        }

        //в любом случае, если заканчиваем цикл, вызываем повторно, но с обработкой ошибки
        if (!b){
            cout << "Something went wrong!" << endl;
        }


        GetAnotherCard(attack);
    }
*/
    void getAttack(const vector<Card>& c_att, vector<Card>& att) override
    {

    }

    void getDefence(const vector<Card>& att, vector<Card>& def) override
    {

    }

};


class Bot : public Player{
public:
    Bot()
    {
        nr.resize(g_rsize);
    }

    void getAttack(const vector<Card>& c_att, vector<Card>& att) override
    {
        att[0] = nr[0];

        for(auto i = nr.begin() + 1; i < nr.end(); i++){
            if( (*i).getNumber() < att[0].getNumber() ){
                att[0] = (*i);
            }
        }
    }

    void getDefence(const vector<Card>& att, vector<Card>& def) override
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


//инфа о матче перед каждым ходом игрока


/*void showPlayerCards(Player& pl)
{
    for(int i = 0; i < pl.getSize(); i++){

        cout << getNameMast( pl[i].getMast() ) << ' ' << getNameNumb( pl[i].getNumber() ) << endl;
    }
}*/

/*Card& getAttackCard(Player& pl)
{
    string act;
    cin.ignore();

    getline(cin, act);

    for(int i = 0; i < pl.getSize(); i++){

        if(act == (getNameMast( pl[i].getMast() ) + getNameNumb( pl[i].getNumber() )){
            Card temp;
            temp = pl[i];

        }
    }
}*/


//на столе будут два вектора карточек: атака и защита. По идеи, на атаку потом смогут подбрасывать и остальные игроки


class Deck{
private:
    vector<Card> dc;

public:
    Deck()
    {
        dc.resize(g_dsize);

        for(int i = 0; i < 4; i++){

            for(int j = 0; j < 9; j++){
                dc[i * 9 + j].setMast(static_cast<Mast>(i));
                dc[i * 9 + j].setNumber(static_cast<Number>(j));
            }
        }
    }

/*    Card& operator[](int index)
    {
        return dc[index];
    }*/


    void Shuffle()
    {
        for(int i = 0; i < g_dsize; i++){
            Card* temp = new Card;
            temp->setMast(dc[i].getMast());
            temp->setNumber(dc[i].getNumber());

            int x{ rand() % g_dsize };

            dc[i] = dc[x];
            dc[x] = *temp;

            delete temp;
        }

        const Mast k = dc[g_dsize - 1].getMast();

        for(int i = 0; i < g_dsize; i++){
            if (k == dc[i].getMast()){
                dc[i].setK();
            }
        }

    }

    int getSize()
    {
        return dc.size();
    }

    Card getCard()
    {
        Card temp = dc[0];
        dc.erase(dc.begin());

        return temp;
    }

};

class Table{
private:
    vector<User*> us;
    Deck d;
    Mast k;

    vector<Card> attack;
    vector<Card> defend;



    void distribution()
    {
        for(auto i = us.begin(); i < us.end(); i++){

            for(int j = 0; j < g_rsize; j++){
                (*i)->takeCard( d.getCard() );

            }
        }
    }


    void ring(int fPl)
    {
        bool b = true;

        for(int i = fPl; b; i++){
            if (i == us.size()){
                i = 0;
            }

            vector<Card> temp_attack;
            us[i]->getAttack(NULL, )
            for(int j = i; ; j++){

                if ((j == i) && (j != 0)) {
                    break;
                }

                if (j == us.size()){
                    j = 0;
                }
            }
            public:
            Table()
            {
                attack.resize(6);
                defend.resize(6);
            }

            void addUser(User* u1)
            {
                if(us.size() < 4){
                    cout << "Too much players" << endl;
                    return;
                }
                us.insert(us.end(), u1);
            }

            void play()
            {
                if(us.empty()){
                    cout << "There is no players!";
                }
                if(us.size() == 1){
                    cout << "Not enough players!";
                }




                d.Shuffle(k);
//
                int firstPl = rand() % us.size();

                ring(firsrPl)








            }

            b = false;
        }

    }



    /*//два метода для итерирования по вектору атакующих карточек
    int GetSize()                 {    return attack.size();    }
    Card& GetAttackCard(int index){    return attack[index];    }

    методы для выкладывания карточек на стол
    void PutAttack(vector<Card>& crdA)
    {
        attack = crdA;
    }
    void PutDefend(vector<Card>& crdD)
    {
        defend = crdD;
    }

    vector<Card> zagreb()
    {
        vector<Card> temp;
        temp.insert(temp.begin(), attack.begin(), attack.end());
        temp.insert(temp.end(), defend.begin(), defend.end());
        return temp;
    }

    void Clear()
    {
        attack.clear();
        defend.clear();
    }

    void distribution(Deck& d, vector<Player*>& pl)
    {
        for(int i = 0; i < pl.size(); i++){
            (*pl[i]).setCards(*this, g_rsize * i);
        }

        const int minus_cards( static_cast<int>((pl.size() + 1) * g_rsize) );
        const int new_size( static_cast<int>((d.getSize() - minus_cards) ) );


        vector<Card> temp(new_size);
        for(int i = 0; i < new_size; i++){

            temp[i] = d.dc[i + minus_cards];
        }

        d.dc = temp;

        d.trump = d.dc[g_dsize - 1].getMast();
        cout << "Trump card is " << getNameMast( d.trump ) << '.' << endl;
    }
     */
};

int main()
{


    return 0;
}
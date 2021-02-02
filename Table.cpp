//
// Created by uzer on 02.02.2021.
//

#include "Table.h"


    void Table::distribution()
    {
        for(auto i = us.begin(); i < us.end(); i++){

            for(int j = 0; j < g_rsize; j++){
                (*i)->takeCard( d.getCard() );

            }
        }
    }


    void Table::ring(int fPl){
        bool b = true;

        for (int i = fPl; b; i++) {
            if (i == us.size()) {
                i = 0;
            }

            std::vector<Card> temp_attack;
            us[i]->getAttack(NULL,)
            for (int j = i;; j++) {

                if ((j == i) && (j != 0)) {
                    break;
                }

                if (j == us.size()) {
                    j = 0;
                }
            }
        }
    }

    Table::Table()
    {
        attack.resize(6);
        defend.resize(6);
    }

    void Table::addUser(User* u1)
    {
        if(us.size() < 4){
            cout << "Too much players" << endl;
            return;
        }
        us.insert(us.end(), u1);
    }

    void Table::play()
    {
            if (us.empty()) {
                cout << "There is no players!";
            }
            if (us.size() == 1) {
                cout << "Not enough players!";
            }


            d.Shuffle(k);
//
            int firstPl = rand() % us.size();

            ring(firsrPl);


            b = false;
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

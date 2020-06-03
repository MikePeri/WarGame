#include <iostream>
#include "SniperCommander.hpp"
#include "Sniper.hpp"
void SniperCommander::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    pair<int,int> loc;
    int max = 0;
    Soldier* attacker=board[location.first][location.second];
    Soldier* enemy=nullptr;
    //cout<<"SniperCommander activate other snipers."<<endl;
    for (size_t row = 0; row < board.size(); row++)
    {
        for (size_t column = 0; column < board[0].size(); column++)
        {
           Soldier* soldier=board[row][column];
           if(soldier!=nullptr && attacker->getID()!=soldier->getID())
            {
                double health=soldier->getHealth();
                if(max<health)
                {
                    max=health;
                    enemy=soldier;
                    loc=make_pair(row,column);
                }//if
            }//if 
            else if(soldier!=nullptr && attacker->getID()==soldier->getID())
            {
                if(Sniper* s=dynamic_cast<Sniper*>(soldier))
                {
                    pair<int,int> loc=make_pair(row,column);
                    s->specialAbillity(board,loc);
                }//if
            }//else if
        }//for  
    }//for
    if(enemy==nullptr)
        return;
    int health=((enemy->getHealth())-_Damage);
    cout<<"SniperCommander Attack... enemy health from: "<<enemy->getHealth()<<" to: "<<health<<endl;
    if(health<=0)
    {
        delete enemy;
        board[loc.first][loc.second]=nullptr;
    }//if
    else
        enemy->setHealth(health);
}//specialAbillity
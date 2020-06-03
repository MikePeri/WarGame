#include "Sniper.hpp"
#include <iostream>

void Sniper::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    pair<int,int> loc;
    int max = 0;
    Soldier* attacker=board[location.first][location.second];
    Soldier* enemy=nullptr;
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
        }//for  
    }//for
    if(enemy==nullptr)
    {
        //cout<<"Sniper dont catch!"<<endl;
        return;
    }
    int health=((enemy->getHealth())-_Damage);
    
    if(health<=0)
    {
        cout<<"Sniper Attack... enemy health from: "<<enemy->getHealth()<<" to: "<<health<<endl;
        delete enemy;
        board[loc.first][loc.second]=nullptr;
        
    }//if
    else
    {
        //cout<<"Sniper Attack... enemy health from: "<<enemy->getHealth()<<" to: "<<health<<endl;
        enemy->setHealth(health);
    }
}//specialAbillity
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>
using namespace std;

void FootCommander::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    pair <int,int> loc;
    //cout<<"FootCommander activate foot soldiers..."<<endl;
    double min = 9999;
    Soldier* attacker=board[location.first][location.second];
    Soldier* enemy=nullptr;
    for (size_t row = 0; row < board.size(); row++)
    {
        for (size_t column = 0; column < board[0].size(); column++)
        {
           Soldier* soldier=board[row][column];
           if(soldier!=nullptr && attacker->getID()!=soldier->getID())
            {
                double dis=distance(row,column,location.first,location.second);
               //cout<<"DISTANCE = "<<dis<<" ("<<row<<","<<column<<")"<<endl;
                if(min>=dis)
                {
                      
                    min=dis;
                    enemy=soldier;
                    loc=make_pair(row,column);
                }//if
            }//if 
            else if(soldier!=nullptr && attacker->getID()==soldier->getID())
            {
                if(FootSoldier* fs=dynamic_cast<FootSoldier*>(soldier))
                    fs->specialAbillity(board,{row,column});
            }//else if
        }//for  
    }//for
    if(enemy==nullptr)
        return;
    int health=((enemy->getHealth())-_Damage);
    cout<<"FootCommander Attack... enemy: "<<enemy->getID()<< " health from: "<<enemy->getHealth()<<" to: "<<health<<" from location: ("<<location.first<<","<<location.second<<")"<<" to location ("<<loc.first<<","<<loc.second<<")"<<endl;
    if(health<=0)
    {
        cout<<"enemy is down!"<<endl;
        delete enemy;
        board[loc.first][loc.second]=nullptr;
    }//if
    else
        enemy->setHealth(health);
}//Attack
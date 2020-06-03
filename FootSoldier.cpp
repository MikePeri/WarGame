#include "FootSoldier.hpp"
#include <iostream>
void FootSoldier::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    
    pair <int,int> loc;
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
                //cout<<"INSIDE"<<endl;
                double dis=distance(row,column,location.first,location.second);
                 cout<<"DISTANCE = "<<dis<<" ("<<row<<","<<column<<")"<<endl;
                //cout<<"DISTANCE = "<<dis<<endl;
                if(min>=dis)
                {
                    //cout<<"Catch enemy!"<<endl;
                    min=dis;
                    enemy=soldier;
                    loc=make_pair(row,column);
                }//if
            }//if 
        }//Inner Loop  
    }//Outer Loop
    if(enemy!=nullptr)
    {
        
        int health=((enemy->getHealth())-_Damage);
        cout<<"FootSoldier Attack... enemy: "<<enemy->getID()<< " health from: "<<enemy->getHealth()<<" to: "<<health<<" from location: ("<<location.first<<","<<location.second<<")"<<" to location ("<<loc.first<<","<<loc.second<<")"<<endl;
        if(health<=0)
        {
            cout<<"enemy is down!"<<endl;
            delete enemy;
            board[loc.first][loc.second]=nullptr;
        }//Inner If
        else
            enemy->setHealth(health);
            
    }//Outer If
    // else
    //     cout<<"Didnt catch enemy!!"<<endl;
    
}//specialAbillity
#include "Paramedic.hpp"
#include <iostream>
void Paramedic::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    Soldier* paramedic=board[location.first][location.second];
    Soldier* soldier=board[location.first][location.second-1];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        cout<<"Paramedic ReHealth soldier in: ("<<location.first<<","<<location.second-1<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first][location.second+1];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        cout<<"Paramedic ReHealth soldier in: ("<<location.first<<","<<location.second+1<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first+1][location.second];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        cout<<"Paramedic ReHealth soldier in: ("<<location.first+1<<","<<location.second<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first-1][location.second];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        cout<<"Paramedic ReHealth soldier in: ("<<location.first<<","<<location.second-1<<")"<<endl;
        soldier->reHealth();
    }//if
}//specialAbillity
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include <iostream>
void ParamedicCommander::specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)
{
    Soldier* paramedic=board[location.first][location.second];
    Soldier* soldier=board[location.first][location.second-1];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        //cout<<"ParamedicCommander ReHealth soldier in: ("<<location.first<<","<<location.second-1<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first][location.second+1];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        //cout<<"ParamedicCommander ReHealth soldier in: ("<<location.first<<","<<location.second+1<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first+1][location.second];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        //cout<<"ParamedicCommander ReHealth soldier in: ("<<location.first+1<<","<<location.second<<")"<<endl;
        soldier->reHealth();
    }//if
    soldier=board[location.first-1][location.second];
    if(soldier!=nullptr && soldier->getID()==paramedic->getID())
    {
        //cout<<"ParamedicCommander ReHealth soldier in: ("<<location.first<<","<<location.second-1<<")"<<endl;
        soldier->reHealth();
    }//if
   // cout<<"ParamedicCommander Activate other Paramedics..."<<endl;
    for(int row=0;row<board.size();row++)
    {
        for(int column=0;column<board[0].size();column++)
        {
            soldier=board[row][column];
            if(soldier!=nullptr && soldier->getID()==paramedic->getID())
            {
                 if(Paramedic* fs=dynamic_cast<Paramedic*>(soldier))
                     soldier->specialAbillity(board,{row,column});
            }
                
        }//for
    }//for
}//specialAbillity
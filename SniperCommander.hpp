#include "Soldier.hpp"
#define uint unsigned
#pragma once
class SniperCommander: public Soldier{
    public:
       SniperCommander(uint id): Soldier(id,120,100){};
       void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander

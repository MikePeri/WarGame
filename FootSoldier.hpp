#pragma once
#include "Soldier.hpp"
#include <stdexcept>
class FootSoldier: public Soldier{
   public:
        FootSoldier(uint id): Soldier(id,100,10){};
        void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander
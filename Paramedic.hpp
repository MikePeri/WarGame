#define uint unsigned
#include "Soldier.hpp"
class Paramedic: public Soldier{
    public:
        Paramedic(uint id): Soldier(id,100,0){};
       void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander
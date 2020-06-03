#include "Soldier.hpp"
#define uint unsigned
class ParamedicCommander: public Soldier{
    public:
        ParamedicCommander(uint id): Soldier(id,200,0){};
       void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander

#include "Soldier.hpp"
class FootCommander: public Soldier{
   public:
       FootCommander(uint id): Soldier(id,150,20){};
       void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander
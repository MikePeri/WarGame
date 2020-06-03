#include "Soldier.hpp"
#define uint unsigned
using namespace std;
class Sniper: public Soldier{
    public:
        Sniper(uint id): Soldier(id,100,50){};
        void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location);
};//FootCommander
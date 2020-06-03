#pragma once
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
//#define uint unsigned
//Soldier Pure Abstract Class
class Soldier
{  
protected:
    int _ID;
    int _MaxHealth;
    int _Health;
    int _Damage;

public:
    Soldier(int id,int health, int damage): _ID(id), _MaxHealth(health),_Health(health), _Damage(damage){};
    virtual ~Soldier(void){};
    int getID(){return this->_ID;};
    int getHealth(){return this->_Health;};
    int getDamage(){return this->_Damage;};
    void setID(int id){this->_ID=id;};
    void setHealth(int health){this->_Health=health;};
    void setDamage(int damage){this->_Damage=damage;};
    void reHealth(){this->_Health=_MaxHealth;}; 
    virtual void specialAbillity(std::vector<std::vector<Soldier*>>& board,pair<int,int> location)=0;
    double distance(int p1x, int p1y, int p2x, int p2y)
        {
                return sqrt(pow(p1x - p2x,2) + pow(p1y - p2y,2));
        }
};
 
    

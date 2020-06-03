#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <stdbool.h>
using namespace std;
#include <iostream>
namespace WarGame 
{
     Soldier*& Board::operator[](std::pair<int,int> location)
     {
        //cout<<"Putting soldiers on the game-board"<<endl;
        
        if(location.first<0 || location.second<0 || location.first>=board.size() || location.second>=board.size())
            throw std::invalid_argument("Invalid argument.");
        //if(board[location.first][location.second]!=nullptr)
           //  throw std::invalid_argument("Invalid argument.");
        return board[location.first][location.second];
     }
     Soldier* Board::operator[](std::pair<int,int> location) const
     {
         if(location.first<0 || location.second<0 || location.first>=board.size() || location.second>=board.size())
            return nullptr;
         return board[location.first][location.second];
     }
     void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
     {
        //cout<< "Moving from: (" << source.first << "," << source.second << ")" << endl;
        Soldier* sol=board[source.first][source.second];
        pair<int,int> dest;
        if(sol == nullptr)
            throw std::invalid_argument("ERR:There is no such a Soldier there.");
        else if(sol->getID()!= player_number)
             throw std::invalid_argument("ERR:This soldier not belong to this player.");
        else
        {
            switch (direction)
            {
            case Up:
                dest=make_pair(source.first+1,source.second);
                break;
            case Down:
                dest=make_pair(source.first-1,source.second);
                break;
            case Right:
                dest=make_pair(source.first,source.second+1);
                break;
            case Left:
                dest=make_pair(source.first,source.second-1);
                break;
            
            }//switch
        }//else
        //cout<< "Moved to: (" << dest.first << "," << dest.second << ")" << endl;
        if(dest.first<0 || dest.second<0 || dest.first>=board.size() || dest.second>=board[0].size())
            throw std::invalid_argument("ERR:Passing argument over the limits.");
        
        
        if(board[dest.first][dest.second]!=nullptr)
            throw std::invalid_argument("ERR:There is another soldier there!");
        board[dest.first][dest.second]=sol;
        board[source.first][source.second]=nullptr;
        sol->specialAbillity(board,dest);
        
     }//move
      bool Board::has_soldiers(uint player_number) const
      {
          int line=board.size();
          int column=board[0].size();
          for (size_t i = 0; i < line; i++)
          {
              for (size_t j = 0; j < column; j++)
              {
                  if(board[i][j]!=nullptr && board[i][j]->getID()==player_number){
                     //cout<< board[i][j]->getHealth()<<endl;
                     return true;
                  }//if
              }//Inner Loop
              
          }//Outer Loop
          return false;
      }//has_soldiers
}//WarGame

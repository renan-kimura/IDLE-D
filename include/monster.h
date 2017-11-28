#ifndef __MONSTER__
#define __MONSTER__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Monster {
  public:
  
  //Constructors and Destructor
    Monster();
    Monster(std::string,int,int,int,int,int);
    ~Monster();
  
  //Getters
  std::string const& getName() const;
  int const& getHp() const;
  int const& getAtk() const;
  int const& getDef() const;
  int const& getExp() const;
  int const& getLoot() const;
  
  //Setters
  void setName(string);
  void setHp(int);
  void setAtk(int);
  void setDef(int);
  void setExp(int);
  void setLoot(int);
  
  //Funcoes
  void assignName(string infoType,int contador,Monster &current);
  void assign(int infoType,int contador,Monster &current);
  vector<Monster> loadMonster();

  private:
    std::string name;
    int hp,
        atk,
        def,
        exp,
        loot;
};



#endif /* MONSTER */

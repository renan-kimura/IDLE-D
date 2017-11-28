#ifndef __MONSTER__
#define __MONSTER__

#include <iostream>
#include <string>

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
  void setHp(int);
  void setAtk(int);
  void setDef(int);
  
  private:
    std::string name;
    int hp,
        atk,
        def,
        exp,
        loot;
};

#endif /* MONSTER */

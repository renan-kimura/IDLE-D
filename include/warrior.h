#ifndef __WARRIOR__
#define __WARRIOR__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

class Warrior : public Character{
  public:    
    //constructors and destructors.
    Warrior(std::string,int,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    Warrior();
    ~Warrior();
    
    //Getters

    //Functions
    int lvl_up() {
      std::cout << "Warrior" << std::endl;
      return 1;
    }
    int attack(int);
  
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
    int const label = 0;
};

#endif /* WARRIOR */
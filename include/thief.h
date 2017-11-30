#ifndef __THIEF__
#define __THIEF__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

class Thief : public Character{
  public:    
    //constructors and destructors.
    Thief(std::string,int,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    ~Thief();
    
    //Getters
  
    //Functions
    int lvl_up() {
      std::cout << "Thief" << std::endl;
      return 3;
    }
    int attack(int);
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
    int const label = 2;
};

#endif /* THIEF */
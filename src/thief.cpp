#include "../include/thief.h"   

    //constructors and destructors.
    Thief::Thief(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Thief::~Thief() = default;
     //Getters

    //Functions
 int Thief::attack(int monsterDef){
      if (rand()%100>=90){
          return (this->equiped[0].getAtk()+getDex())*2.5;
      }
      else{
        if(this->getDex()>monsterDef){
          return this->equiped[0].getAtk()+getDex();
        }else{
          return 0;
        }
      }
    }
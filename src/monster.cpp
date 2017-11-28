#include "../include/monster.h"

//Constructors and Destructor
Monster::Monster() = default;

Monster::Monster(std::string name, int hp, int atk, int def, int exp, int loot){
  this->name = name;
  this->hp = hp;
  this->atk = atk;
  this->def = def;
  this->exp = exp;
  this->loot = loot;
}

Monster::~Monster() = default;

//Getters
  std::string const& Monster::getName() const{
  return this->name;
  }

  int const& Monster::getHp() const{
    return this->hp;
  }

  int const& Monster::getAtk() const{
    return this->atk;
  }

  int const& Monster::getDef() const{
    return this->def;
  }

  int const& Monster::getExp() const{
    return this->exp;
  }

  int const& Monster::getLoot() const{
    return this->loot;
  }
  
  //Setters
  void Monster::setHp(int hp){
    this->hp = hp;
  }

  void Monster::setAtk(int atk){
    this->atk = atk;
  }

  void Monster::setDef(int def){
    this->def = def;
  }
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
  void Monster::setName(string name){
    this->name = name;
  }

  void Monster::setHp(int hp){
    this->hp = hp;
  }

  void Monster::setAtk(int atk){
    this->atk = atk;
  }

  void Monster::setDef(int def){
    this->def = def;
  }

  void Monster::setExp(int exp){
    this->exp = exp;
  }

  void Monster::setLoot(int loot){
    this->loot = loot;
  }

  void Monster::assignName(string infoType,int contador,Monster& current){
    if(contador == 0)
      this->setName(infoType);
    else{
      cout<<"Dado invalido";
    }
  }

  void Monster::assign(int infoType,int contador,Monster& current){
    if(contador == 1)
      this->setHp(infoType);
    if(contador == 2)
      this->setAtk(infoType);
    if(contador == 3)
      this->setDef(infoType);
    if(contador == 4)
      this->setExp(infoType);
    if(contador == 5)
      this->setLoot(infoType);
  }



  vector<Monster> Monster::loadMonster(){
    vector<Monster> monsters;
    Monster currentMonster;
    string atributo;
    int contador=0, atributoInt;
    ifstream monsterFile("Monsters.txt");
    if(monsterFile){
      while(getline(monsterFile, atributo, ';')){
        if(!monsterFile.eof()){
          if(contador == 0)
            assignName(atributo, contador, currentMonster);
          atributoInt = atoi(atributo.c_str());
          assign(atributoInt, contador, currentMonster);

          if(contador>5){
            monsters.push_back(currentMonster);
            contador = 0;
          }
          else
            contador++;
        }
      }
    }
    monsterFile.close();
    return monsters;
  }
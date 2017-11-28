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
  std::string const& Monster::getMonName() const{
  return this->name;
  }

  int const& Monster::getMonHp() const{
    return this->hp;
  }

  int const& Monster::getMonAtk() const{
    return this->atk;
  }

  int const& Monster::getMonDef() const{
    return this->def;
  }

  int const& Monster::getMonExp() const{
    return this->exp;
  }

  int const& Monster::getMonLoot() const{
    return this->loot;
  }
  
  //Setters
  void Monster::setMonName(string name, Monster &current){
    current.name = name;
    cout<<"Name:"<<current.name<<endl;
  }

  void Monster::setMonHp(int hp, Monster &current){
    current.hp = hp;
    cout<<"Hp:"<<current.hp<<endl;
  }

  void Monster::setMonAtk(int atk, Monster &current){
    current.atk = atk;
    cout<<"Atk:"<<current.atk<<endl;
  }

  void Monster::setMonDef(int def, Monster &current){
    current.def = def;
    cout<<"Def:"<<current.def<<endl;
  }

  void Monster::setMonExp(int exp, Monster &current){
    current.exp = exp;
    cout<<"Exp:"<<current.exp<<endl;
  }

  void Monster::setMonLoot(int loot, Monster &current){
    current.loot = loot;
    cout<<"Loot:"<<current.loot<<endl;
  }

  void Monster::assignMonName(string infoType,int contador,Monster& current){
    if(contador == 0)
      this->setMonName(infoType, current);
    else{
      cout<<"Dado invalido";
    }
  }

  void Monster::assignMon(int infoType,int contador,Monster& current){
    if(contador == 1)
      this->setMonHp(infoType, current);
    if(contador == 2)
      this->setMonAtk(infoType, current);
    if(contador == 3)
      this->setMonDef(infoType, current);
    if(contador == 4)
      this->setMonExp(infoType, current);
    if(contador == 5)
      this->setMonLoot(infoType, current);
  }



  vector<Monster> Monster::loadMonster(vector<Monster> &monsters){
    Monster currentMonster;
    string atributo;
    int contador=0, atributoInt;
    ifstream monsterFile("Monsters.txt");
    if(monsterFile){
      while(getline(monsterFile, atributo, ';')){
        if(!monsterFile.eof()){
          if(contador == 0)
            assignMonName(atributo, contador, currentMonster);
          atributoInt = atoi(atributo.c_str());
          assignMon(atributoInt, contador, currentMonster);

          if(contador==5){
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
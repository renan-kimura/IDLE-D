#include "../include/character.h"

//Constructors and Destructor
    Character::Character(std::string name,int hp,int str,int dex,int wis,int agi,int exp, int lvl,int next_lvl,int money){
          this->name = name;
          this->hp = hp;
          this->str = str;
          this->dex = dex;
          this->wis = wis;
          this->agi = agi;
          this->exp = exp;
          this->lvl = lvl;
          this->next_lvl = next_lvl;
          this->money = money;
    }

    Character::Character() = default;

    Character::~Character() = default;
  
  //Getters
  std::string const& Character::getName() const{
    return this->name;
  }

  int const& Character::getHp() const{
    return this->hp;
  }

  int const& Character::getStr() const{
    return this->str;
  }

  int const& Character::getDex() const{
    return this->dex;
  }

  int const& Character::getWis() const{
    return this->wis;
  }

  int const& Character::getAgi() const{
    return this->agi;  
  }

  int const& Character::getExp() const{
    return this->exp;  
  }

  int const& Character::getLvl() const{
    return this->lvl;
  }

  int const& Character::getNext_lvl() const{
    return this->next_lvl;    
  }

  int const& Character::getMoney() const{
    return this->money;    
  }
  
  //Setters
  void Character::setHp(int hp){
    this->hp = hp;
  }

  void Character::setStr(int str){
    this->str = str;
  }

  void Character::setDex(int dex){
    this->dex = dex;
  }

  void Character::setWis(int wis){
    this->wis = wis;
  }

  void Character::setAgi(int agi){
    this->agi = agi;
  }

  void Character::setExp(int exp){
    this->exp = exp;
  }

  void Character::setLvl(int lvl){
    this->lvl = lvl;
  }

  void Character::setNext_lvl(int next_lvl){
    this->next_lvl = next_lvl;
  }

  void Character::setMoney(int money){
    this->money = money;
  }

  //Functions
  void lvl_up(){};
  int attack(){};

      //constructors and destructors.
    Warrior::Warrior(std::string nome,int hp,int str,int dex,int wis,int agi,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, agi, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Warrior::Warrior() = default;
    Warrior::~Warrior() = default;

    //Functions
    void Warrior::lvl_up(){

    }

    int Warrior::attack(int monsterDef){
      if (rand()%100>=95){
          return (this->equiped[0].getAtk()+getDex())*2;
      }else{
        if(this->getDex()>monsterDef){
          return this->equiped[0].getAtk()+getStr();
        }else{
          return 0;
        }
      } 
    }
   //constructors and destructors.
    Warlock::Warlock(std::string nome,int hp,int str,int dex,int wis,int agi,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, agi, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Warlock::~Warlock() = default;

    //Functions
    void Warlock::lvl_up(){

    }

    int Warlock::attack(int monsterDef){
        return (this->equiped[0].getAtk()+getWis())/2;
    }

   //constructors and destructors.
    Thief::Thief(std::string nome,int hp,int str,int dex,int wis,int agi,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, agi, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Thief::~Thief() = default;

    //Functions
    void Thief::lvl_up(){

    }
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
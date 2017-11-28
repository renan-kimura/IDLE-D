#ifndef __CHARACTER__
#define __CHARACTER__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"

class Character {
  public:
  
  //Constructors and Destructor
    Character(std::string,int,int,int,int,int,int,int,int,int);
    Character();
    ~Character();
  
  //Getters
  std::string const& getName() const;
  int const& getHp() const;
  int const& getStr() const;
  int const& getDex() const;
  int const& getWis() const;
  int const& getAgi() const;
  int const& getExp() const;
  int const& getLvl() const;
  int const& getNext_lvl() const;
  int const& getMoney() const;
  
  //Setters
  void setHp(int);
  void setMana(int);
  void setStr(int);
  void setDex(int);
  void setWis(int);
  void setAgi(int);
  void setExp(int);
  void setLvl(int);
  void setNext_lvl(int);
  void setMoney(int);

  //Functions
  void lvl_up();
  int attack();
  
  private:
    std::string name;
    int hp,
        str,
        dex,
        wis,
        agi,
        exp,
        lvl,
        next_lvl,
        money;   
};


class Warrior : public Character{
  public:    
    int const label = 0;
    //constructors and destructors.
    Warrior(std::string,int,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    Warrior();
    ~Warrior();

    //Functions
    void lvl_up();
    int attack(int);
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
};
class Warlock : public Character{
  public:
    int const label = 1;
    //constructors and destructors.
    Warlock(std::string,int,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    // Warlock();
    ~Warlock();

    //Functions
    void lvl_up();
    int attack(int);
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
};

class Thief : public Character{
  public:    
    int const label = 2;
    //constructors and destructors.
    Thief(std::string,int,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    // Warlock();
    ~Thief();

    //Functions
    void lvl_up();
    int attack(int);
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
};

/*
class Habilities{
  public:


  private:
};
*/
#endif /* CHARACTER */

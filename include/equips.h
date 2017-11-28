#ifndef __EQUIPS__
#define __EQUIPS__

#include <iostream>
#include <string>

class Equip {
  public:
  
  //Constructors and Destructor
    Equip();
    Equip(std::string,std::string,int,int,std::string);
    ~Equip();
  
  //Getters
  std::string const& getName() const;
  std::string const& getDescription() const;
  std::string const& getType() const;
  int const& getAtk() const;
  int const& getDef() const;
  
  //Setters
  void setName(std::string);
  void setAtk(int);
  void setDef(int);
  
  //functions
  void refine();
  
  private:
    std::string name;
    std::string description;
    std::string type;
    int atk,
        def;
};

#endif /* EQUIPS */
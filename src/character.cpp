#include "../include/character.h"
#include "../include/func.h"

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


/*void Character::battle() {
  Monster oponente;
  oponente.ranMonster(oponente); 
  int HpJogador = getHp();
  int HpOponente = monstroAndar.getMonHP();
  int cabou=0;
  while(){
    cabou=0;
    srand(time(NULL));
    if((rand() % 20 + 1) + getDex() >= monstroAndar.getMonDef()){
      cout << "Voce acertou o oponente, causando " << attack() << "pontos de dano!";
      HpOponente -= attack();
      }else{
      cout << "Voce errou seu ataque.";
      }
    if(HpOponente <= 0){
      cout << "Voce venceu o combate!";
      setExp(getExp()+monstroAndar.getMonExp());
      cabou++;
      }
    cout << monstroAndar.getMonName() << " acertou um ataque em voce, causando " << monstroAndar.getMonAtk() << " de dano.";
    HpJogador -= monstroAndar.getMonAtk();
    if(HpJogador <= 0){
      cout << "Voce foi derrotado!";
      cabou++;
      }
    if(cabou!=0){
      HpJogador = getHp();
      HpOponente = monstroAndar.getMonHP();
      }
    }
  }*/

  int const& Character::getLabel() const{
    
  }

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
  void Character::lvl_up(){}

  int Character::attack(){
    return this->str;
  }

  void Character::battle() {
    srand(time(NULL));
    Monster monstroAndar;
    monstroAndar.ranMonster(monstroAndar); 
    int HpJogador = getHp();
    int HpOponente = monstroAndar.getMonHp();
    int cabou=0;
    while(1){
      cabou=0;
      srand(time(NULL));
      usleep(1000*1000);
      if((rand() % 20 + 1) + getDex() >= monstroAndar.getMonDef()){ 
        cout << "Voce acertou o oponente, causando " << attack() << "pontos de dano!"<<endl;
        HpOponente -= attack();
        }else{
        cout << "Voce errou seu ataque."<<endl;
      }
      if(HpOponente <= 0){
        cout << "Voce venceu o combate!"<<endl;
        setExp(getExp()+monstroAndar.getMonExp());
        cabou++;
      }
      usleep(1000*1000);
      cout << monstroAndar.getMonName() << " acertou um ataque em voce, causando " << monstroAndar.getMonAtk() << " de dano."<<endl;
      HpJogador -= monstroAndar.getMonAtk();
      if(HpJogador <= 0){
        cout << "Voce foi derrotado!"<<endl;
        cabou++;
      }
      if(cabou!=0){
        HpJogador = getHp();
        HpOponente = monstroAndar.getMonHp();
      }
    }
  }
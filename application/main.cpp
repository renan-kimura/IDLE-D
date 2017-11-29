#include "../include/monster.h"
#include "../include/character.h"
#include "../include/equips.h"
#include "../include/warrior.h"
#include "../include/warlock.h"
#include "../include/thief.h"
#include "../include/func.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
	Character player;
	bool voltar = true;
	
	system("clear");
	
	if(voltar){
		player = intro();
		player.battle();
		if(player.getHp() != -999999)
			game(player);
	}
}
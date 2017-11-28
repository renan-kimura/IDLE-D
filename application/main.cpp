#include "../include/monster.h"
#include "../include/character.h"
#include "../include/equips.h"
#include <fstream>
#include <vector>
#include <list>
#include <sstream>

using namespace std;



Character Create(string name, string classe);

void Begin();

int main(){
  
cout <<"▄█ ██▄   █     ▄███▄       ██▄     ▄      ▄     ▄▀  ▄███▄   ████▄    ▄" << endl;
cout <<"██ █  █  █     █▀   ▀      █  █     █      █  ▄▀    █▀   ▀  █   █     █ " << endl;
cout <<"██ █   █ █     ██▄▄        █   █ █   █ ██   █ █ ▀▄  ██▄▄    █   █ ██   █" << endl; 
cout <<"▐█ █  █  ███▄  █▄   ▄▀     █  █  █   █ █ █  █ █   █ █▄   ▄▀ ▀████ █ █  █" << endl; 
cout <<" ▐ ███▀      ▀ ▀███▀       ███▀  █▄ ▄█ █  █ █  ███  ▀███▀         █  █ █" << endl; 
cout <<"                                  ▀▀▀  █   ██                     █   ██" << endl;

  Monster test_boss("Cobra", 5, 10, 16, 20, 100);
  Equip test_sword("Sword of Light", "The sword of the legendary hero", 9999, 0, "Holy"); 
  
  Begin();
}

Character Create(string name, string classej){

	list<Equip> inventory_new;
	vector<Equip> equiped_new;

  	string txt = name + ".txt";
	if(classej == "Warrior"){
		Warrior player(name, 100, 50, 17, 12, 13, 11, 999, 100, 9999, equiped_new, inventory_new);
		ofstream out(txt);
		out<< player.label << ";" << name<< ";"<< player.getHp()<< ";"<< player.getStr()<< ";"<< player.getDex()<< ";"<< player.getWis()<< ";"<< player.getAgi()<< ";"<< player.getExp()<< ";"<< player.getLvl()<< ";"<< player.getNext_lvl()<< ";"<< player.getMoney();
		return player;

	} else if(classej == "Warlock"){
		Warlock player(name, 50, 50, 17, 12, 13, 11, 0, 100, 9999, equiped_new, inventory_new);
		ofstream out(txt);
		return player;

	} else if(classej == "Thief"){
		Thief player(name, 75, 50, 17, 12, 13, 11, 1, 100, 9999, equiped_new, inventory_new);
		ofstream out(txt);
		return player;
	}
}

Character Load(string str){
	list<Equip> inventory_new;
	vector<Equip> equiped_new;
	/*Falta desmembrar cada atributo, convertendo seus tipos e armazenando em um vector*/
	if(str[0] == '0'){
		Warrior player("Sanji", 100, 50, 17, 12, 13, 11, 999, 100, 9999, equiped_new, inventory_new);
		return player;

	} else if(str[0] == '1'){
		Warlock player("aaa", 50, 50, 17, 12, 13, 11, 0, 100, 9999, equiped_new, inventory_new);
		return player;

	} else if(str[0] == '2'){
		Thief player("ll", 75, 50, 17, 12, 13, 11, 1, 100, 9999, equiped_new, inventory_new);
		return player;
	}
}

void Begin(){
	string name, option, aux, classe;
	while(1){

		cout<<"Insira o nome do seu personagem:";
		cin>>name;

		aux = name;
		aux += ".txt";

		ifstream personagem(name);
		
		if(personagem.is_open()){
			string str;
			while(not personagem.eof()){
			str.push_back(personagem.get());
			}
			Load(str);
			personagem.close();
			break;

		} else {

			cout<<"Personagem nao existe! Deseja criar um?(y/n)\n";
			cin>>option;

			if(option == "y"||option == "Y"){
				cout<<"Qual a classe para "<< name <<"?(Warrior/Warlock/Thief)\n";
				cin>>classe;

				Create(name, classe);

				break;

			} else if(option =="n"||option == "N"){
				system("clear");

			} else { 
				system("clear");
				cout << "Essa opcao nao existe!";

			}

		}
	}
}

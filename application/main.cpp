#include "../include/monster.h"
#include "../include/character.h"
#include "../include/equips.h"
#include "../include/warrior.h"
#include "../include/warlock.h"
#include "../include/thief.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//***********************************************Funções*******************************************
void display();
Character carregar(ifstream&);
Character carregar(string, int);
Character intro();
void save_game(Character);
bool game(Character);
//***********************************************Funções*******************************************
//***********************************************main**********************************************
int main(){
	list<Equip> inventory_new;
	vector<Equip> equiped_new;
	Character player;
	bool voltar = true;
	
	system("clear");
	
	if(voltar){
		player = intro();

		if(player.getHp() != -999999)
		game(player);
	}
}
//***********************************************main**********************************************
//***********************************************display*******************************************
void display(){
	cout <<"▄█ ██▄   █     ▄███▄       ██▄     ▄      ▄     ▄▀  ▄███▄   ████▄    ▄" << endl;
	cout <<"██ █  █  █     █▀   ▀      █  █     █      █  ▄▀    █▀   ▀  █   █     █ " << endl;
	cout <<"██ █   █ █     ██▄▄        █   █ █   █ ██   █ █ ▀▄  ██▄▄    █   █ ██   █" << endl; 
	cout <<"▐█ █  █  ███▄  █▄   ▄▀     █  █  █   █ █ █  █ █   █ █▄   ▄▀ ▀████ █ █  █" << endl; 
	cout <<" ▐ ███▀      ▀ ▀███▀       ███▀  █▄ ▄█ █  █ █  ███  ▀███▀         █  █ █" << endl; 
	cout <<"                                  ▀▀▀  █   ██                     █   ██" << endl;
	cout << endl;
}
//***********************************************display*******************************************
//**********************************************Criação de personagem******************************
Character carregar(ifstream& file){
	Character player;
	return player;
}

Character carregar(string name, int num){
	list<Equip> new_list;
	vector<Equip> new_vector;
	//Tratamento de teste já foi feito pela função que chama essa!!!
	if(num == 1){
		Warrior player(name,12,17,12,10,12,0,1,100,0,new_vector,new_list);
		return player;
	} else if(num == 2){
		Warlock player(name,6,10,12,17,12,0,1,100,0,new_vector,new_list);
		return player;
	} else {
		Thief player(name,8,10,17,10,17,0,1,100,0,new_vector,new_list);
		return player;
	}
}
//**********************************************Fim da criação de personagem***********************
//**********************************************Menu principal*************************************
Character intro(){
	string username, aux, option;
	int num;
	bool laco = true;
	Character player;
	
	display();
	cout << "Bem vindo! digite o seu nome de usuario(se nao existir, um novo personagem sera criado): ";
	
	cin >> username;
	
	aux = "../data/save/" + username + ".txt";

	ifstream savefile(aux, ifstream::in);
	
	if(savefile.is_open()){
		return carregar(savefile);
		
	}else{
		while(laco){
		cout << "Esse personagem não existe! deseja cria-lo? (y/n)" << endl;
		cin >> option;
			
			if(option.compare("y") == 0 or option.compare("Y") == 0){
				cout << "Escolha a sua classe:" << endl;
				cout << "[1] Guerreiro" << endl;
				cout << "[2] Mago" << endl;
				cout << "[3] Ladino" << endl;
				
				cin >> num;
				
				if(num > 3 or num < 1){
					cout << "\033[91mOpcao invalida!\033[39m" << endl;
					
				} else {
					return carregar(username,num);
					
				}
				
			} else if(option.compare("n") == 0 or option.compare("N") == 0){
				cout << "Fim de jogo!" << endl;
				laco = false;
				
			} else {
				system("clear");
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				
			}
		}
	}
	if(laco){
		cout << "\033[91mOcorreu um erro inesperado!!!" << endl;
		cout << "Fechando o programa!!!\033[39m" << endl;
	}
		player.setHp(-999999);
		return player;
}
//**********************************************Fim do menu****************************************
//**********************************************Inicio do Save*************************************
void save_game(Character player){
	
	string aux = "data/Save/" + player.getName() + ".txt", save;
	//É só concatenar todas as informações do personagem nesse padrão aí
	//Que já tá escrevendo no arquivo bonitinho! O problema tá no label... acho melhor que durante a criação o personagem tenha
	//Uma string classe para identifica-lá!
	save = ";" +player.getName()+ ";" +to_string(player.getHp())+ ";" +to_string(player.getStr())+ ";" +to_string(player.getDex())+ ";" +to_string(player.getWis())+ ";" +to_string(player.getAgi())+ ";" +to_string(player.getExp())+ ";" +to_string(player.getLvl())+ ";" +to_string(player.getNext_lvl())+ ";" +to_string(player.getMoney());
	
	ofstream outfile;
	outfile.open(aux);
	cout<<save<<endl;
	if(outfile.is_open()){.
		outfile << save;
	}
	
	outfile.close();
}
//**********************************************Fim do Save****************************************
//**********************************************Inicio do jogo*************************************
bool game(Character player){
	int num;
	bool laco = true;
	
	while(laco){
		cout << "Bem vindo a cidade de Crystal Water! Lar da dungeon infinita!" << endl;
		cout << "[1] Enfrentar a dungeon." << endl;
		cout << "[2] Ir ao inventario." << endl;
		cout << "[3] Salvar o jogo." << endl;
		cout << "[4] Voltar ao menu inicial." << endl;
		cout << "[5] Sair do jogo." << endl;
		cout << "O que voce deseja fazer?" << endl;
		cin >> num;
		
		if(num == 1){
			//dungeon(player);
			
		} else if(num == 2){
			//menu(player);
		
		} else if(num == 3){
			save_game(player);
			//system("clear");
			display();
			cout << "O seu jogo foi salvo!" << endl;
			cout << endl;
		
		} else if(num == 4){
			system("clear");
			return true;
		
		} else if(num == 5){
			system("clear");
			cout << "Obrigado por visitar nossa cidade aventureiro!!!" << endl;
			return false;
		
		} else {
			system("clear");
			cout << "\033[91mOpcao invalida!\033[39m" << endl;
			cout << endl;
		
		}
		num = 0;
	}
	cout << "\033[91mOcorreu um erro inesperado!!!" << endl;
	cout << "Fechando o programa!!!\033[39m" << endl;
	return false;
}
//**********************************************Fim do jogo****************************************
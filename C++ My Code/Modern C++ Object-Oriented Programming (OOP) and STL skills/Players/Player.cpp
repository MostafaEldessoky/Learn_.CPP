#include "Player.h"
#include <iostream>
#include <string>

int Player::playerCount = 0;
// constructor 
Player::Player(int* pos, std::string name) : pos{pos}, name{name}{
	playerCount++;
	std::cout << "Player : " << playerCount << " created.\n" << "Name : " << this->name << "\nposition : "<< (*this).pos << std::endl;
}
// dstructor
Player::~Player() {
	std::cout << "Player : "<< playerCount <<" destroyed.\n" << "Name : " << this->name << "\nposition : " << this->pos << std::endl;
	if (this->pos != 0) {
		playerCount--;
	}
	delete (*this).pos;
}
// Deep copy constructor
Player::Player(const Player &source) : name { source.name } {
	(*this).pos = new int;
	*((*this).pos) = *(source.pos);
	std::cout << "Copy constructor called." <<  std::endl;
}
//move constructor
Player::Player(Player&& source) : Player{ source.pos, source.name } {
	source.pos = nullptr; // avoid dangling pointer
	std::cout << "Move constructor called." << std::endl;
}



#pragma once
#include <string>
class Player
{
	static int playerCount; // variable for the class itself
	std::string name;
	int* pos;

public:
	// constractor, copy constractor, move constractor and destructor
	Player(int* pos = {0}, std::string name = "actor"); // definition and insulization and defult constracor
	Player(const Player &source); // make deep copy by copy value to a new pointer
	Player(Player&& source); // pass by r-value copy pointer and free temp pointer 
	~Player(); //dstractor free memory on the heap and do any needed action before deleting obj

};


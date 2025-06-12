#include <iostream>
#include "Player.h"
#include <vector>
int main() {

	int* ptr1 = new int;
	*ptr1 = 5;
	Player player1 = Player(ptr1,"mostafa");

	Player player2 { player1 };

	int* ptr2 = new int;
	*ptr2 = 7;
	std::vector<Player> player_vec;

	player_vec.push_back(Player(ptr2,"mohamed"));

	return 0;
}
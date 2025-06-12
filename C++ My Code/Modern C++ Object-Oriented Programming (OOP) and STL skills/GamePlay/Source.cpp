#include <iostream>
#include <vector>
#include <string>

class Actor 
{
protected:

	std::string heroName;
	int xpostion;
	int attackDamage;
	int defence;

public:

	int health;

	virtual int& move(int& x) = 0;

	virtual Actor& applyAttack(Actor&) = 0;

	virtual Actor& applyDefence() = 0;

	virtual ~Actor() {}
};


class Player : public Actor
{
	std::string playerName;
	int playerRank;

public:

	Player(std::string playerName, int playerRank, std::string heroName, int attackDamage, int defence, int health);

	virtual int& move(int&) override;
	virtual Actor& applyDefence() override;
	virtual Actor& applyAttack(Actor&) override;

	virtual ~Player() {}
};



int& Player::move(int& x) {
	return this->xpostion += x;
}


Actor& Player::applyDefence() {
	this->health += (this->defence / 50);
	return *this;
}

Actor& Player::applyAttack(Actor& enemy) {
	enemy = enemy.applyDefence();
	enemy.health -= this->attackDamage;
	return enemy;
}


Player::Player(std::string playerName, int playerRank,
	std::string heroName, int attackDamage,
	int defence, int health) : playerName{ playerName }, playerRank{ playerRank } {
	Actor::heroName = heroName;
	Actor::xpostion = 0;
	Actor::attackDamage = attackDamage;
	Actor::defence = defence;
	Actor::health = health;
}

class Enemy : public Actor 
{

public:

	Enemy(std::string heroName, int xpostion, int attackDamage, int defence, int health);

	virtual int& move(int&) override;
	virtual Actor& applyDefence() override;
	virtual Actor& applyAttack(Actor&) override;

	virtual ~Enemy() {}
};

int& Enemy::move(int& x) {
	return this->xpostion += x;
}


Actor& Enemy::applyDefence() {
	this->health += (this->defence / 100);
	return *this;
}

Actor& Enemy::applyAttack(Actor& player) {
	player = player.applyDefence();
	player.health -= this->attackDamage;
	return player;
}


Enemy::Enemy(std::string heroName, int xpostion, int attackDamage,
	int defence, int health) {
	Actor::heroName = heroName;
	Actor::xpostion = xpostion;
	Actor::attackDamage = attackDamage;
	Actor::defence = defence;
	Actor::health = health;
}



int main() {

	Actor* ptr1 = new Player{"mostafa",50,"slark",100,80,600};

	int x = 2;

	ptr1->move(x);

	Actor* ptr2 = new Enemy{ "sf",3,80,50,500 };

	ptr2->applyAttack(*ptr1);
	ptr1->applyAttack(*ptr2);

	return 0;
}

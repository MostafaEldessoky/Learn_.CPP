#include "Account.h"
#include <iostream>



int Account::Acounts= 0;


Account::Account(const float* balance) : balance{nullptr} {
	std::cout << "Account Constractor" << std::endl;
	this->balance = new float{*balance};
	Acounts++;
	std::cout << "Account created with balance: " << *this->balance << "\nnumber of accounts : " << Acounts << std::endl;
}

Account::Account(const Account& source) : balance{ nullptr } {
	std::cout << "Account Deep Copy Constractor" << std::endl;
	this->balance = new float{*source.balance};
	Acounts++;
	std::cout << "Account copied with balance: " << *this->balance << "\nnumber of accounts : " << Acounts << std::endl;
}

Account ::Account(Account&& source) : balance{source.balance} {
	std::cout << "Account Move Constractor" << std::endl;
	source.balance = nullptr;
	Acounts++;
	std::cout << "Account moved with balance: " << *this->balance << "\nnumber of accounts : " << Acounts << std::endl;
}

Account::~Account() {
	std::cout << "Account destractor" << std::endl;
	delete this->balance ;
	Acounts--;
	std::cout << "Account destroyed. Remaining accounts: " << Acounts << std::endl;
}

void Account::getBalance() const {
	std::cout << "Current balance: " << *this->balance << std::endl;
}

void Account::deposit(const float& amount) {
	*this->balance += amount;
	std::cout << "Deposited: " << amount << ", new balance: " << *this->balance << std::endl;
}

void Account::withdraw(const float& amount) {
	if (amount < *this->balance) {
		*this->balance -= amount;
		std::cout << "Withdrew: " << amount << ", new balance: " << *this->balance << std::endl;
	}
	else {
		std::cout << "Insufficient funds. Cannot withdraw: " << amount << std::endl;
	}
}
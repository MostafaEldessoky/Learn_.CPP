#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount(const float* balance, const float* interestRate) : Account{ balance }, interestRate{ nullptr } {
	std::cout << "Saving Account Constractor" << std::endl;
	this->interestRate = new float{ *interestRate };
}

SavingAccount::SavingAccount(const SavingAccount& source) : Account{ source }, interestRate{nullptr} {
	std::cout << "Saving Account Deep Copy Constractor" << std::endl;
	this->interestRate = new float{ *source.interestRate };
}

SavingAccount::SavingAccount(SavingAccount&& source) : Account{ std::move(source) }, interestRate{ source.interestRate } {
		std::cout << "Saving Account Move Constractor" << std::endl;
		source.interestRate = nullptr;
}

SavingAccount::~SavingAccount() {
	std::cout << "Saving Account Destructor" << std::endl;
	delete interestRate;
}

void SavingAccount::deposit(const float& amount) {
	*this->balance += (amount * (*this->interestRate / 100));
	Account::deposit(amount);
	std::cout << "Deposited: " << amount << ", new balance: " << *this->balance << std::endl;

}
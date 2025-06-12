#pragma once
#include "Account.h"
class SavingAccount : public Account
{
	float* interestRate;

public:

	SavingAccount(const float* balance,const float* interestRate);
	SavingAccount(const SavingAccount& source);
	SavingAccount(SavingAccount&& source);
	~SavingAccount();

	void deposit(const float& amount);
};


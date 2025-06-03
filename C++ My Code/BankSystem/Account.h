#pragma once
class Account
{
protected:

	int static Acounts;
	float* balance;

public:

	Account(const float* balance);
	Account(const Account& source);
	Account(Account&& source) ;
	~Account();

	void getBalance() const;
	void deposit(const float& amount);
	void withdraw(const float& amount);

};


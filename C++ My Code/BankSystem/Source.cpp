#include "Account.h"
#include <vector>
#include "SavingAccount.h"
int main() {
	float* balance1{nullptr};
	balance1 = new float{0.01f};
	Account acc1{ balance1 };
	Account acc2{ acc1 };
	std::vector<Account> accounts;
	accounts.push_back(Account{balance1});

	acc1.deposit(100.0f);
	acc2.deposit(200.0f);
	acc1.getBalance();
	acc2.getBalance();
	acc1.withdraw(50.0f);
	acc2.withdraw(100.0f);
	acc1.getBalance();
	acc2.getBalance();
	
	float* balance2{ nullptr };
	balance2 = new float{ 100.0f };

	float* interestRate{ nullptr };
	interestRate = new float{ 50.2f };

	SavingAccount sacc1{balance2,interestRate};
	SavingAccount sacc2{ sacc1 };
	std::vector<SavingAccount> saccounts;
	saccounts.push_back(SavingAccount{ balance2, interestRate });
	
	sacc1.deposit(100.0f);
	sacc2.deposit(200.0f);
	sacc1.getBalance();
	sacc2.getBalance();
	sacc1.withdraw(50.0f);
	sacc2.withdraw(100.0f);
	sacc1.getBalance();
	sacc2.getBalance();

	return 0;
}
#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include <iostream>

#include "Account.hpp"

typedef std::vector<Account*> Accounts;

class Bank
{
	friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);

public:
	Bank();
	~Bank();

	int createAccount(int initialBalance);
	void deposit(int id, int value);
	void withdraw(int id, int value);
	void giveLoan(int id, int value);
	void deleteAccount(int id);

private:
	Bank(const Bank&);
	Bank& operator=(const Bank&);

	int liquidity;
	int nextAccountId;
	Accounts clientAccounts;
};

#endif // !BANK_HPP

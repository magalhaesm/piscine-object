#ifndef BANK_HPP
#define BANK_HPP

#include <map>
#include <iostream>

#include "Account.hpp"

typedef std::map<int, Account*> Accounts;

class Bank
{
	friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);

public:
	Bank();
	~Bank();

	int createAccount(int initialBalance);
	void deposit(int account, int value);
	void withdraw(int account, int value);
	void giveLoan(int account, int value);
	void deleteAccount(int account);

private:
	Bank(const Bank&);
	Bank& operator=(const Bank&);

	int liquidity;
	Accounts clientAccounts;
};

#endif // !BANK_HPP

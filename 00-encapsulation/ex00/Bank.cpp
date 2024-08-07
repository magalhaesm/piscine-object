#include "Bank.hpp"

Bank::Bank()
	: liquidity(0)
	, nextAccountId(0)
{
}

Bank::~Bank()
{
}

Bank::Bank(const Bank&)
{
}

Bank& Bank::operator=(const Bank&)
{
	return *this;
}

int Bank::createAccount(int initialBalance)
{
	Account* acc = new Account();
	acc->id = nextAccountId++;
	acc->value = initialBalance;
	clientAccounts[acc->id] = acc;

	return acc->id;
}

void Bank::deposit(int account, int value)
{
	clientAccounts[account]->id += value;
}

void Bank::withdraw(int account, int value)
{
	clientAccounts[account]->id -= value;
}

void Bank::deleteAccount(int account)
{
	delete clientAccounts.at(account);
	clientAccounts.erase(account);
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;

	Accounts::const_iterator it = p_bank.clientAccounts.begin();
	for (; it != p_bank.clientAccounts.end(); it++)
	{
		p_os << *it->second << std::endl;
	}
	return p_os;
}

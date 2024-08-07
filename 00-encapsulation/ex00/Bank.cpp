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
	Account* acc = new Account(nextAccountId, initialBalance);
	clientAccounts.push_back(acc);
	nextAccountId++;

	return acc->getID();
}

void Bank::deposit(int id, int value)
{
	float fee = value * 0.05;
	clientAccounts[id]->deposit(static_cast<int>(value - fee));
}

void Bank::withdraw(int id, int value)
{
	clientAccounts[id]->withdraw(value);
}

void Bank::deleteAccount(int id)
{
	delete clientAccounts[id];
	clientAccounts[id] = NULL;
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;

	Accounts::const_iterator it = p_bank.clientAccounts.begin();
	for (; it != p_bank.clientAccounts.end(); it++)
	{
		p_os << **it << std::endl;
	}
	return p_os;
}

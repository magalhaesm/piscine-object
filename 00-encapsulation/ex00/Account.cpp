#include "Account.hpp"

Account::Account(int id, int value)
	: id(id)
	, value(value)
{
}

Account::~Account()
{
}

Account::Account(const Account&)
{
}

Account& Account::operator=(const Account&)
{
	return *this;
}

const int& Account::getID() const
{
	return id;
}

void Account::deposit(int value)
{
	this->value += value;
}

void Account::withdraw(int value)
{
	this->value -= value;
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return p_os;
}

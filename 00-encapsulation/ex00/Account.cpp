#include "Account.hpp"

Account::Account()
	: id(-1)
	, value(0)
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

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return p_os;
}

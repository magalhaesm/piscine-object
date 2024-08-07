#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Bank;

class Account
{
	friend class Bank;
	friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);

public:
	Account();
	~Account();

private:
	int id;
	int value;

	Account(const Account&);
	Account& operator=(const Account&);
};

#endif // !ACCOUNT_HPP

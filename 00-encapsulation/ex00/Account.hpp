#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account
{
	friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);

public:
	Account(int id, int value);
	~Account();

	const int& getID() const;
	void deposit(int value);
	void withdraw(int value);

private:
	int id;
	int value;

	Account(const Account&);
	Account& operator=(const Account&);
};

#endif // !ACCOUNT_HPP

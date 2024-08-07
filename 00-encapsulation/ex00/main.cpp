#include <iostream>

#include "Bank.hpp"
#include "Account.hpp"

int main()
{
	Bank bank;
	bank.createAccount(10);
	bank.createAccount(13);

	std::cout << bank << std::endl;
}

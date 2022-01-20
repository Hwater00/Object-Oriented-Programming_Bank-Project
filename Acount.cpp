#include "Acount.h"
#include <cstring>
#include <iostream>
#include"BalanceOutOfBoundsException.h"
#include"MalformedAccount.h"

using std::cout;
using std::endl;
using std::cin;

Account::Account(int accountNo, char* name, int balance) : accountNo(accountNo),balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Account::Account(const Account& account)
{

	this->accountNo = account.accountNo;
	this->balance = account.balance;

	this->name = new char[strlen(account.name) + 1];
	strcpy(this->name, account.name);
}
Account::~Account(void)
{
	delete[] name;
}

void Account::Deposit(int amount)
{
	balance += amount;
}
int Account::Withdraw(int amount) throw (BalanceOutOfBoundsException&)
{
	if (amount <= balance) {
		balance -= amount;
		return amount;
	}
	else {
		throw BalanceOutOfBoundsException();
		return 0;
	}
}

void Account::Check(void) const 
{
	cout << endl;
	cout << "****** °èÁÂ Á¤º¸ ******" << endl;
	cout << " °èÁÂ¹øÈ£:\t" << accountNo << endl;
	cout << " ¿¹±ÝÁÖ:\t" << name << endl;
	cout << " ÀÜ¾×:\t\t" << balance << endl;
}

Account& Account::operator=(const Account& account)
{
	if (this->name != NULL) delete[] this->name;

	this->accountNo = account.accountNo;
	this->balance = account.balance;


	this->name = new char[strlen(account.name) + 1];
	strcpy(this->name, account.name);

	return *this;
}


bool Account::operator==(int accountNo) const {
	if (this->accountNo == accountNo)
		return true;
	else
		return false;
}



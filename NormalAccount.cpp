#include "NormalAccount.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

NormalAccount::NormalAccount(int accountNo, char* name, int balance, int interRate) :Account(accountNo, name, balance), interRate(interRate) {
	
}
void NormalAccount::interest(void) {
	Account::Deposit((int)(balance* interRate/100.0));
}
void NormalAccount::Deposit(int amount)
{
	NormalAccount::interest();
	Account::Deposit(amount);

	
}

void NormalAccount::Check(void) const
{
	Account::Check();
	cout << " 기본이율:\t" << interRate << "%" << endl;

}

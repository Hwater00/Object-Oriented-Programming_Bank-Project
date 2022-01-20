#include "HighCreditAccount.h"
#include <iostream>

using std::cout;
using std::endl;

void HighCreditAccount::interest(void) {
	if (special == 'A') {
		Account::Deposit((int)(balance * (interRate+7) / 100.0));
	}
	else if (special == 'B') {
		Account::Deposit((int)(balance * (interRate + 4) / 100.0));
	}
	else if (special == 'C') {
		Account::Deposit((int)(balance * (interRate + 2) / 100.0));
		
	}
	else
		cout<< "신용도가 잘 못 입력되었습니다." << endl;
}
void HighCreditAccount::Deposit(int amount)
{
	HighCreditAccount::interest();
	Account::Deposit(amount);
}
void HighCreditAccount::Check(void) const
{
	Account::Check();
	cout << " 기본이율:\t" << interRate << endl;
	cout << " 특별이율:\t";
	if (special == 'A') {
		cout << "7" << "%" << endl;
	}
	else if (special == 'B') {
		cout << "4" << "%" << endl;
	}
	else {
		cout << "2" << "%" << endl;
	}

}
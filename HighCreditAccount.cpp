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
		cout<< "�ſ뵵�� �� �� �ԷµǾ����ϴ�." << endl;
}
void HighCreditAccount::Deposit(int amount)
{
	HighCreditAccount::interest();
	Account::Deposit(amount);
}
void HighCreditAccount::Check(void) const
{
	Account::Check();
	cout << " �⺻����:\t" << interRate << endl;
	cout << " Ư������:\t";
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
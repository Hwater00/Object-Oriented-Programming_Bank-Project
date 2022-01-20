#ifndef _HighCreditAccount_h
#define _HighCreditAccount_h

#include "Acount.h"
class HighCreditAccount :public Account
{
	int interRate; // �⺻ ����
	char special;
public:
	HighCreditAccount(int accountNo, char* name, int balance, int interRate,char special) :Account(accountNo, name, balance), interRate(interRate) ,special(special) {};
	void interest(void);
	void Deposit(int amount);

	void Check(void) const;  //�ܾ���ȸ
};
#endif // !_HighCreditAccount_h

#ifndef _HighCreditAccount_h
#define _HighCreditAccount_h

#include "Acount.h"
class HighCreditAccount :public Account
{
	int interRate; // 기본 이율
	char special;
public:
	HighCreditAccount(int accountNo, char* name, int balance, int interRate,char special) :Account(accountNo, name, balance), interRate(interRate) ,special(special) {};
	void interest(void);
	void Deposit(int amount);

	void Check(void) const;  //잔액조회
};
#endif // !_HighCreditAccount_h

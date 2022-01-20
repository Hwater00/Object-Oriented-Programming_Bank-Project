#ifndef _NormalAccount_h
#define _NormalAccount_h


#include "Acount.h"
class NormalAccount :public Account
{
	int interRate; // 기본 이율
public:
	NormalAccount(int accountNo, char* name, int balance, int interRate);
	void interest(void);
	void Deposit(int amount);

	void Check(void) const;  //잔액조회
};

#endif // !_NormalAccount_h
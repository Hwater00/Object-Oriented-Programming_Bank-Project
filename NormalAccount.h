#ifndef _NormalAccount_h
#define _NormalAccount_h


#include "Acount.h"
class NormalAccount :public Account
{
	int interRate; // �⺻ ����
public:
	NormalAccount(int accountNo, char* name, int balance, int interRate);
	void interest(void);
	void Deposit(int amount);

	void Check(void) const;  //�ܾ���ȸ
};

#endif // !_NormalAccount_h
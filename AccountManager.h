#ifndef _AccountManager_h
#define _AccountManager_h

#include"Acount.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"MalformedAccount.h"
#include"BalanceOutOfBoundsException.h"

class AccountManager
{
	static const int MAX_ACCOUNTS = 100;
	Account* accounts[MAX_ACCOUNTS];
	int size;
public:
	
	AccountManager();
	~AccountManager(void);
	
	void CreateAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void DisplayAll(void) const;
	void DisplayOne(void) const;
	void CloseAccount(void);

	int GetSize(void) const;
	
};
#endif // !_AccountManager_


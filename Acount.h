#ifndef _Account_h
#define _Account_h
#define _CRT_SECURE_NO_WARNINGS
#include<string>
using std::string;
class Account
{
protected:
	int accountNo; //계좌번호
	char* name;   // 소유자 이름
	int balance;   // 현 잔액

public:
	
	Account(int accountNo, char* name, int balance); //생성시 고유한 이름/계좌번호
	Account(const Account&);
	~Account(void);//객체 소멸 시 동적 메모리 해제
	
	int GetAccountNO(void) const { return accountNo; };
	int GetBalance(void) const { return balance; }
	char* GetName(void) const { return name; }

	virtual void Deposit(int amount); //입금
	virtual int Withdraw(int amount); //출금
	virtual void Check(void) const;  //잔액조회
	
	
	bool operator==(int accountNo) const;
	Account& operator=(const Account&);
	
	virtual void interest() = 0;

};

#endif // !_Account_h_

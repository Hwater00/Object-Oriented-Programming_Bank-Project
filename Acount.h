#ifndef _Account_h
#define _Account_h
#define _CRT_SECURE_NO_WARNINGS
#include<string>
using std::string;
class Account
{
protected:
	int accountNo; //���¹�ȣ
	char* name;   // ������ �̸�
	int balance;   // �� �ܾ�

public:
	
	Account(int accountNo, char* name, int balance); //������ ������ �̸�/���¹�ȣ
	Account(const Account&);
	~Account(void);//��ü �Ҹ� �� ���� �޸� ����
	
	int GetAccountNO(void) const { return accountNo; };
	int GetBalance(void) const { return balance; }
	char* GetName(void) const { return name; }

	virtual void Deposit(int amount); //�Ա�
	virtual int Withdraw(int amount); //���
	virtual void Check(void) const;  //�ܾ���ȸ
	
	
	bool operator==(int accountNo) const;
	Account& operator=(const Account&);
	
	virtual void interest() = 0;

};

#endif // !_Account_h_

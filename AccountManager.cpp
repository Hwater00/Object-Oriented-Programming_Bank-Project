#include "AccountManager.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

AccountManager::AccountManager():size(0) {}

AccountManager::~AccountManager()
{
	for(int i=0; i<size;i++)
		delete[] accounts[i];
}

void AccountManager::CreateAccount(void) {
	
	int choiceNum;
	int length = 0;
	cout<<"\n[���°���]" << endl;
	cout<<"1. ���뿹�� ����" << endl;
	cout<<"2. �ſ�ŷ� ����" << endl;
	cout<< ">�����ϰ��� �ϴ� ���� ������?";
	cin >> choiceNum;

	int accountNo;
	char account_name[20];
	int balabce;
	int interRate;
	char special;
	if (choiceNum == 1) {
		cout << "\n���¹�ȣ:"; cin >> accountNo;
		cout << "�̸�:"; cin >> account_name;
		cout << "�Աݾ�:"; cin >> balabce;
		cout << "�⺻����:"; cin >> interRate;
		accounts[size++] = new NormalAccount(accountNo, account_name, balabce, interRate);
	}
	else
	{
		cout << "\n���¹�ȣ:"; cin >> accountNo;
		cout << "�̸�:"; cin >> account_name;
		cout << "�Աݾ�:"; cin >> balabce;
		cout << "�⺻����:"; cin >> interRate;
		cout << "�ſ���:"; cin >> special;
		accounts[size++] = new HighCreditAccount(accountNo, account_name, balabce, interRate,special);

	}
	cout<<"\n" << "[���°��� �Ϸ�]" <<"\n" << endl;
	
}
void AccountManager::Deposit(void) {
	int money;
	int accountNo;
	cout << "\n" << "[�Ա�]" << endl;
	cout << "���¹�ȣ:"; cin >> accountNo;

	for (int i = 0; i < size; i++) {
		if (accounts[i]->GetAccountNO() == accountNo) {
			cout << "�Աݾ�:"; cin >> money;

			if (dynamic_cast<NormalAccount*>(accounts[i])) {
				((NormalAccount*)accounts[i])->Deposit(money);
			}else
				((HighCreditAccount*)accounts[i])->Deposit(money);

			cout << "\n" << "[�ԱݿϷ�]" << "\n" << endl;
			return;
		}
		
	}
	
}
void AccountManager::Withdraw(void) {
	
	cout << "\n" << "[���]" << endl;
	int money;
	int accountNo;
	cout << "���¹�ȣ:"; cin >> accountNo;
	
	for (int i = 0; i < size; i++) {
		if (accounts[i]->GetAccountNO() == accountNo) {
			cout << "��ݾ�:"; cin >> money;
			try {
				(accounts[i]->Withdraw(money) == 0);
				
			}
			catch (BalanceOutOfBoundsException& e) {
				cout << e.getMessage() << endl;
			}
			cout << "\n" << "[��ݿϷ�]" << "\n" << endl;
	
		}
		else if (accounts[i]->GetAccountNO() != accountNo) {
			cout << "��ġ�ϴ� ���°� �������� �ʽ��ϴ�!" << endl;
		}
	}

}

/*����ó��_ ��ݺκ��� ���¹�ȣ ���� ���ܷ� �����߽��ϴ�.
void AccountManager::Withdraw(void) {
	
	cout << "\n" << "[���]" << endl;
	int money;
	int accountNo;
	cout << "���¹�ȣ:"; cin >> accountNo;
	
		for (int i = 0; i < size; i++) {
			try{
				if (accounts[i]->GetAccountNO() == accountNo) {
					throw accountNo;
					cout << "�Աݾ�:"; cin >> money;
					if (dynamic_cast<NormalAccount*>(accounts[i])) {
						((NormalAccount*)accounts[i])->Deposit(money);
					}
					else
						((HighCreditAccount*)accounts[i])->Deposit(money);

					cout << "\n" << "[�ԱݿϷ�]" << "\n" << endl;
					return;
				}
			}
			catch (MalformedAccount& e) {
				cout << e.getMessage() << endl;
			}
		}
	}
		*/
void AccountManager::DisplayAll(void) const
{
	cout << "\n" << "[��ȸ]" << endl;
	for (int i = 0; i < size; i++) {
		accounts[i]->Check();
		cout << endl;
	}
	cout << "\n" << "[��ȸ �Ϸ�]" << "\n" << endl;
}
void AccountManager::DisplayOne(void) const
{
	cout << "\n" << "[��ȸ]" << endl;
	int accountNo;
	cout << "���¹�ȣ:"; cin >> accountNo;
	for (int i = 0; i < size; i++) {
		if (accounts[i]->GetAccountNO() == accountNo) {
			if (dynamic_cast<NormalAccount*>(accounts[i])) {
				((NormalAccount*)accounts[i])->Check();
			}else
				((HighCreditAccount*)accounts[i])->Check();

			return;
		}
	}
}
void AccountManager::CloseAccount(void) {
	cout << "\n" << "[��������]" << endl;
	int accountNo;
	char account_name[20];
	cout << "���¹�ȣ �Է� : ";
	cin >> accountNo;
	cout << "�̸�:"; cin >> account_name;
	
		for (int i = 0; i < size; i++) {
			//if (accounts[i]->GetAccountNO() == accountNo && accounts[i]->GetName() == account_name) ������������ �־� ����Ȯ���� ���ؼ� �ʿ��Ѱ� �����ؼ� �ۼ��غ��ҽ��ϴ�.
			if (accounts[i]->GetAccountNO() == accountNo) {
				for (int i = 0; i < size; i++) {
				delete accounts[i];
				for (int j = i + 1; j < size; j++) {
					accounts[j - 1] = accounts[j];
				}
				cout << "\n" << "[�������� �Ϸ�]" << "\n" << endl;
				size--;
				return;
				}
			}
			else if(accounts[i]->GetAccountNO() != accountNo)
				cout << "��ġ�ϴ� ���°� �������� �ʽ��ϴ�!" << endl;
		}	
}

int AccountManager::GetSize(void) const {
	return size;
}
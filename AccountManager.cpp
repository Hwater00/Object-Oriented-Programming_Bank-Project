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
	cout<<"\n[계좌개설]" << endl;
	cout<<"1. 보통예금 계좌" << endl;
	cout<<"2. 신용신뢰 계좌" << endl;
	cout<< ">개설하고자 하는 계좌 종류는?";
	cin >> choiceNum;

	int accountNo;
	char account_name[20];
	int balabce;
	int interRate;
	char special;
	if (choiceNum == 1) {
		cout << "\n계좌번호:"; cin >> accountNo;
		cout << "이름:"; cin >> account_name;
		cout << "입금액:"; cin >> balabce;
		cout << "기본이율:"; cin >> interRate;
		accounts[size++] = new NormalAccount(accountNo, account_name, balabce, interRate);
	}
	else
	{
		cout << "\n계좌번호:"; cin >> accountNo;
		cout << "이름:"; cin >> account_name;
		cout << "입금액:"; cin >> balabce;
		cout << "기본이율:"; cin >> interRate;
		cout << "신용등급:"; cin >> special;
		accounts[size++] = new HighCreditAccount(accountNo, account_name, balabce, interRate,special);

	}
	cout<<"\n" << "[계좌개설 완료]" <<"\n" << endl;
	
}
void AccountManager::Deposit(void) {
	int money;
	int accountNo;
	cout << "\n" << "[입금]" << endl;
	cout << "계좌번호:"; cin >> accountNo;

	for (int i = 0; i < size; i++) {
		if (accounts[i]->GetAccountNO() == accountNo) {
			cout << "입금액:"; cin >> money;

			if (dynamic_cast<NormalAccount*>(accounts[i])) {
				((NormalAccount*)accounts[i])->Deposit(money);
			}else
				((HighCreditAccount*)accounts[i])->Deposit(money);

			cout << "\n" << "[입금완료]" << "\n" << endl;
			return;
		}
		
	}
	
}
void AccountManager::Withdraw(void) {
	
	cout << "\n" << "[출금]" << endl;
	int money;
	int accountNo;
	cout << "계좌번호:"; cin >> accountNo;
	
	for (int i = 0; i < size; i++) {
		if (accounts[i]->GetAccountNO() == accountNo) {
			cout << "출금액:"; cin >> money;
			try {
				(accounts[i]->Withdraw(money) == 0);
				
			}
			catch (BalanceOutOfBoundsException& e) {
				cout << e.getMessage() << endl;
			}
			cout << "\n" << "[출금완료]" << "\n" << endl;
	
		}
		else if (accounts[i]->GetAccountNO() != accountNo) {
			cout << "일치하는 계좌가 존재하지 않습니다!" << endl;
		}
	}

}

/*예외처리_ 출금부분을 계좌번호 오류 예외로 구현했습니다.
void AccountManager::Withdraw(void) {
	
	cout << "\n" << "[출금]" << endl;
	int money;
	int accountNo;
	cout << "계좌번호:"; cin >> accountNo;
	
		for (int i = 0; i < size; i++) {
			try{
				if (accounts[i]->GetAccountNO() == accountNo) {
					throw accountNo;
					cout << "입금액:"; cin >> money;
					if (dynamic_cast<NormalAccount*>(accounts[i])) {
						((NormalAccount*)accounts[i])->Deposit(money);
					}
					else
						((HighCreditAccount*)accounts[i])->Deposit(money);

					cout << "\n" << "[입금완료]" << "\n" << endl;
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
	cout << "\n" << "[조회]" << endl;
	for (int i = 0; i < size; i++) {
		accounts[i]->Check();
		cout << endl;
	}
	cout << "\n" << "[조회 완료]" << "\n" << endl;
}
void AccountManager::DisplayOne(void) const
{
	cout << "\n" << "[조회]" << endl;
	int accountNo;
	cout << "계좌번호:"; cin >> accountNo;
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
	cout << "\n" << "[계좌해지]" << endl;
	int accountNo;
	char account_name[20];
	cout << "계좌번호 입력 : ";
	cin >> accountNo;
	cout << "이름:"; cin >> account_name;
	
		for (int i = 0; i < size; i++) {
			//if (accounts[i]->GetAccountNO() == accountNo && accounts[i]->GetName() == account_name) 동명이이인이 있어 계좌확인을 위해서 필요한가 생각해서 작성해보았습니다.
			if (accounts[i]->GetAccountNO() == accountNo) {
				for (int i = 0; i < size; i++) {
				delete accounts[i];
				for (int j = i + 1; j < size; j++) {
					accounts[j - 1] = accounts[j];
				}
				cout << "\n" << "[계좌해지 완료]" << "\n" << endl;
				size--;
				return;
				}
			}
			else if(accounts[i]->GetAccountNO() != accountNo)
				cout << "일치하는 계좌가 존재하지 않습니다!" << endl;
		}	
}

int AccountManager::GetSize(void) const {
	return size;
}
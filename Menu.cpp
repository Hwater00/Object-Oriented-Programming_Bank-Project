#include "Menu.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Menu::ShowMenu(void)
{
	cout << "\n" << "계좌 관리 시스템<1단계>" << endl;
	cout <<"========================== "<< endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체 계좌정보 출력" << endl;
	cout << "5. 특정 계좌 조회" << endl;
	cout << "6. 계좌 해지" << endl;
	cout << "7. 종료" << endl;
	cout << "========================== " << endl;
	cout << "선택:";
}
int Menu::InputMenu(void)
{
	int choiceNum;
	cin >> choiceNum;
	return choiceNum;
}
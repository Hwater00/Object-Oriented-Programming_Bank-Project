#include "Menu.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Menu::ShowMenu(void)
{
	cout << "\n" << "���� ���� �ý���<1�ܰ�>" << endl;
	cout <<"========================== "<< endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ��ü �������� ���" << endl;
	cout << "5. Ư�� ���� ��ȸ" << endl;
	cout << "6. ���� ����" << endl;
	cout << "7. ����" << endl;
	cout << "========================== " << endl;
	cout << "����:";
}
int Menu::InputMenu(void)
{
	int choiceNum;
	cin >> choiceNum;
	return choiceNum;
}
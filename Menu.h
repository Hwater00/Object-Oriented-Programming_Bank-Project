#ifndef  _Menu_h
#define  _Menu_h

class Menu
{
public:
	
	static const int MENUITEM_EXIT=7;
	static const int MENUITEM_DEPOSIT=2; //�Ա�
	static const int MENUITEM_DISPLAY_ALL=4; //��ü �������� ���
	static const int MENUITEM_DISPLAY=5; //Ư�� ���� ��ȸ
	static const int MENUITEM_WITHDRAW=3;//���
	static const int MENUITEM_CLOSE=6; // ���� ����
	static const int MENUITEM_CREATE=1; //���°���

	static void ShowMenu(void);
	static int InputMenu(void);
};
#endif // ! _Menu_h


#ifndef  _Menu_h
#define  _Menu_h

class Menu
{
public:
	
	static const int MENUITEM_EXIT=7;
	static const int MENUITEM_DEPOSIT=2; //입금
	static const int MENUITEM_DISPLAY_ALL=4; //전체 계좌정보 출력
	static const int MENUITEM_DISPLAY=5; //특정 계좌 조회
	static const int MENUITEM_WITHDRAW=3;//출금
	static const int MENUITEM_CLOSE=6; // 계좌 해지
	static const int MENUITEM_CREATE=1; //계좌개설

	static void ShowMenu(void);
	static int InputMenu(void);
};
#endif // ! _Menu_h


#ifndef _BalanceOutOfBoundsException_h
#define _BalanceOutOfBoundsException_h

#include "Exception.h"
class BalanceOutOfBoundsException : public Exception
{
public:
	BalanceOutOfBoundsException() : Exception("�ܾ��� �����մϴ�!") {}
	string getMessage();
};

#endif // !_BalanceOutOfBoundsException_h

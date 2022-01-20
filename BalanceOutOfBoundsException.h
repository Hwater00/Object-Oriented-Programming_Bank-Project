#ifndef _BalanceOutOfBoundsException_h
#define _BalanceOutOfBoundsException_h

#include "Exception.h"
class BalanceOutOfBoundsException : public Exception
{
public:
	BalanceOutOfBoundsException() : Exception("잔액이 부족합니다!") {}
	string getMessage();
};

#endif // !_BalanceOutOfBoundsException_h

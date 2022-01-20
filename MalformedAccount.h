#ifndef _MalformedAccoun_h
#define _MalformedAccoun_h
#include "Exception.h"
class MalformedAccount :public Exception
{
	
public:
	MalformedAccount() : Exception("일치하는 계좌가 존재하지 않습니다!"){}
	string getMessage();
};

#endif 
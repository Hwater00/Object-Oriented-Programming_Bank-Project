#ifndef _MalformedAccoun_h
#define _MalformedAccoun_h
#include "Exception.h"
class MalformedAccount :public Exception
{
	
public:
	MalformedAccount() : Exception("��ġ�ϴ� ���°� �������� �ʽ��ϴ�!"){}
	string getMessage();
};

#endif 
#ifndef _Exception_h
#define _Exception_h
#include <iostream>
#include <string>

using std::cout;
using std::string;

class Exception
{
	string message;
public:
	Exception() : message("¿À·ù") {};
	Exception(string message) : message(message) {};
	virtual string getMessage() { return message; };
};

#endif 
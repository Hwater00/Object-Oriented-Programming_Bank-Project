#include "BalanceOutOfBoundsException.h"
#include <iostream>
#include <string>

using std::to_string;

string BalanceOutOfBoundsException::getMessage()
{
	return Exception::getMessage();
}
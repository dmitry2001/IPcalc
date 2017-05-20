#include <exception>
#include <string>
using namespace std;

#pragma once
class WrongInputFormatException :
	public exception
{
public:
	WrongInputFormatException();
	WrongInputFormatException(const string& messange);
	~WrongInputFormatException();
};


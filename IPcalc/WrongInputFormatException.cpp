#include "WrongInputFormatException.h"


WrongInputFormatException::WrongInputFormatException() : exception("Wrong format exception")
{
	
}
WrongInputFormatException::WrongInputFormatException(const string& str) : exception(("Wrong format exception: " + str).data())
{
}
WrongInputFormatException::~WrongInputFormatException()
{

}

#include "Assertions.h"

int Assertions::code = 0;
std::string Assertions::errors = "";

std::string Assertions::getErrors()
{
	return errors;
}

int Assertions::getCode()
{
	return code;
}

Assertions::Assertions()
{
}

void Assertions::assert_true(bool condition, string error)
{
	if (!condition)
	{
		Assertions::errors += error + "\n";
		Assertions::code -= 1;
	}
}
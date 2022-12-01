#include "IError.h"


string IError::Print()
{
	return "";
}

string IncorrectInput::Print()
{
	return errorText + "Incorrect Input\n";
}

string DivisionByZero::Print()
{
	return errorText + "Division by zero\n";
}

string EmptyInput::Print()
{
	return errorText + "You didn't enter anything\n";
}

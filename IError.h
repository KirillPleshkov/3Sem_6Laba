#pragma once
#include <iostream>
#include <string>

using namespace std;

class IError
{
public:	
	virtual string Print();
protected:
	string errorText = "Error: ";
};

class IncorrectInput : public IError
{
	virtual string Print() override;
};

class DivisionByZero : public IError
{
	virtual string Print() override;
};

class EmptyInput : public IError
{
	virtual string Print() override;
};


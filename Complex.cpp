#include "Complex.h"

Complex::Complex()
{
	realPart = 0;
	imaginaryPart = 0;
}

Complex::Complex(double realPart, double imaginaryPart)
{
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

Complex Complex::operator+(Complex secondObject)
{
	log.AddLog("operator+");
	Complex rezult;

	rezult.realPart = this->realPart + secondObject.realPart;
	rezult.imaginaryPart = this->imaginaryPart + secondObject.imaginaryPart;

	return rezult;
}

Complex Complex::operator-(Complex secondObject)
{
	log.AddLog("operator-");
	Complex rezult;

	rezult.realPart = this->realPart - secondObject.realPart;
	rezult.imaginaryPart = this->imaginaryPart - secondObject.imaginaryPart;

	return rezult;
}

Complex Complex::operator*(Complex secondObject)
{
	log.AddLog("operator*");
	Complex rezult;

	rezult.realPart = this->realPart * secondObject.realPart - 
					  this->imaginaryPart * secondObject.imaginaryPart;

	rezult.imaginaryPart = this->realPart * secondObject.imaginaryPart +
						   secondObject.realPart * this->imaginaryPart;

	return rezult;
}

Complex Complex::operator/(Complex secondObject)
{
	log.AddLog("operator/");
	Complex rezult;
	double numerator;
	double denominator;

	rezult = this->operator*(Complex(secondObject.realPart, -secondObject.imaginaryPart));

	denominator = pow(secondObject.realPart, 2) + pow(secondObject.imaginaryPart, 2);

	if (denominator == 0)
	{
		throw DivisionByZero();
	}

	rezult.realPart /= denominator;
	rezult.imaginaryPart /= denominator;


	return rezult;
}

bool Complex::operator==(const Complex& object)
{
	log.AddLog("operator==");
	if (this->realPart == object.realPart && this->imaginaryPart == object.imaginaryPart)
		return true;

	return false;
}

bool Complex::operator!=(const Complex& object)
{
	log.AddLog("operator!=");
	return !this->operator==(object);
}

ostream& operator<<(ostream& os, Complex object)
{
	object.log.AddLog("operator<<");
	char sign = (object.imaginaryPart > 0) ? '+' : '-';
	
	os << setprecision(6) << object.realPart << sign << abs(object.imaginaryPart) << 'i';

	return os;
}

istream& operator>>(istream& in, Complex& object)
{
	object.log.AddLog("operator>>");
	char sign;
	bool isSymbolFound = false, isLetterFound = false;
	int i = 0;
	string lineReaded, promString;
	string firstNumString, secondNumString;
	double firstNum, secondNum;
	in >> lineReaded;

	if (lineReaded.empty() == true)
	{
		throw EmptyInput();
	}

	for (auto symbol : lineReaded)
	{
		if ((symbol == '-' || symbol == '+') && isLetterFound == false && i != 0)
		{
			if (isSymbolFound == true)
			{
				throw IncorrectInput();
			}

			sign = symbol;
			isSymbolFound = true;
			firstNumString = promString;
			promString.clear();
		}
		else if (symbol == 'i' && isSymbolFound == true && isLetterFound == false)
		{
			if (isLetterFound == true)
			{
				throw IncorrectInput();
			}

			isLetterFound = true;
			secondNumString = promString;
			promString.clear();
		}
		else
		{
			promString.push_back(symbol);
		}
		i++;
	}

	if (isSymbolFound == false || isLetterFound == false || promString.empty() == false || firstNumString.empty() == true || secondNumString.empty() == true)
	{
		throw IncorrectInput();
	}
	
	try
	{
		firstNum = stod(firstNumString);
		secondNum = stod(secondNumString);
	}
	catch (exception)
	{
		throw IncorrectInput();
	}

	if (sign == '-')
	{
		secondNum *= -1;
	}

	object.realPart = firstNum;
	object.imaginaryPart = secondNum;

	return in;
}

void Complex::CreateTrigonometricShape()
{
	polarRadius = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
	polarAngle = atan2(imaginaryPart, realPart);
}

void Complex::TrigonometricShapeToNorm()
{
	realPart = polarRadius * cos(polarAngle);
	imaginaryPart = polarRadius * sin(polarAngle);
}

void Complex::Pow(double degree)
{
	log.AddLog("Pow");
	CreateTrigonometricShape();

	polarRadius = pow(polarRadius, degree);
	polarAngle = degree * polarAngle;

	TrigonometricShapeToNorm();
}

vector<Complex> Complex::Sqrt(double degree)
{
	log.AddLog("Sqrt");
	vector<Complex> complexes;

	this->CreateTrigonometricShape();

	this->polarRadius = pow(this->polarRadius, 1.0 / degree);
	this->polarAngle = this->polarAngle / degree;

	for (int i = 0; i < degree; i++)
	{
		Complex object;

		object.polarRadius = this->polarRadius;
		object.polarAngle = this->polarAngle + 2 * M_PI * i / degree;

		object.TrigonometricShapeToNorm();

		complexes.push_back(object);
	}

	return complexes;
}

void Complex::PrintTrigonometricForm()
{
	CreateTrigonometricShape();
	cout << "Z = " << polarRadius << ", Phi = " << polarAngle << endl;
}

void Complex::PrintIndicativeForm()
{
	CreateTrigonometricShape();
	cout << "Z = " << polarRadius << ", Phi = " << polarAngle << endl;
}

void Complex::PrintLog()
{
	log.Print();
}

pair<Complex, Complex> Equation(double A, double B, double C)
{	
	Complex object1, object2;
	double discriminant, discriminantRoot;

	discriminant = pow(B, 2) - 4 * A * C;

	discriminantRoot = sqrt(abs(discriminant));

	if (discriminant == 0)
	{
		object1.realPart = (-1 * B) / (2 * A);
		object1.imaginaryPart = 0;

		object2 = object1;
	}
	else if (discriminant > 0)
	{
		object1.realPart = (-1 * B + discriminantRoot) / (2 * A);
		object2.realPart = (-1 * B - discriminantRoot) / (2 * A);
		object1.imaginaryPart = 0;
		object2.imaginaryPart = 0;
	}
	else
	{
		object1.realPart = (-1 * B) / (2 * A);
		object2.realPart = (-1 * B) / (2 * A);
		object1.imaginaryPart = discriminantRoot / (2 * A);
		object2.imaginaryPart = (-1 * discriminantRoot) / (2 * A);
	}


	return make_pair(object1, object2);
}

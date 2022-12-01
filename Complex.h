#pragma once

#define _USE_MATH_DEFINES
#include "IError.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "Logger.h"

using namespace std;


class Complex
{
public:

	Complex();
	Complex(double, double);


	Complex operator+ (Complex);
	Complex operator- (Complex);
	Complex operator* (Complex);
	Complex operator/ (Complex);

	bool operator==(const Complex&);
	bool operator!=(const Complex&);

	friend ostream& operator<< (ostream&, Complex);
	friend istream& operator>> (istream&, Complex&);
	

	void Pow(double);
	vector<Complex> Sqrt(double);
	friend pair<Complex, Complex> Equation(double, double, double);

	void PrintTrigonometricForm();
	void PrintIndicativeForm();

	void PrintLog(); 

private:

	double realPart;
	double imaginaryPart;

	double polarRadius;
	double polarAngle;


	void CreateTrigonometricShape();
	void TrigonometricShapeToNorm();
	
	Logger log;
};

pair<Complex, Complex> Equation(double, double, double);


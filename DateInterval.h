#pragma once
#include <iostream>
#include <string>
#include "Ñalendar.h"

using namespace std;

class DateInterval
{
public:
	friend class Date;

	int64_t GetYears();
	int64_t GetMounth();
	int64_t GetDays();
	int64_t GetHours();
	int64_t GetMinutes();
	int64_t GetSeconds();

	string toString();

private:
	int64_t years;
	int64_t mounth;
	int64_t days;
	int64_t hours;
	int64_t minutes;
	int64_t seconds;

	
};


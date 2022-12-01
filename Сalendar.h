#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
#include "Mounth.h"
#include "DateInterval.h"
#include <regex>

using namespace std;


class Date
{
public:
	friend class DateInterval;

	Date();
	Date(uint64_t years, MOUNTH mounth, uint64_t days, uint64_t hours, uint64_t minutes, uint64_t seconds);
	Date(uint64_t years, MOUNTH mounth, uint64_t days);
	Date(uint64_t hours, uint64_t minutes, uint64_t seconds);

	string toString();

	Date addYears(int num);
	Date addMounth(int num);
	Date addDays(int num);
	Date addHours(int num);
	Date addMinutes(int num);
	Date addSeconds(int num);

	uint64_t GetYears();
	uint64_t GetMounth();
	uint64_t GetDays();
	uint64_t GetHours();
	uint64_t GetMinutes();
	uint64_t GetSeconds();

	DateInterval getInterval(Date& secondDate);
	Date addInterval(DateInterval& dateInterval);
	string FormatDate(string format);

private:
	uint64_t years;
	uint64_t mounth;
	uint64_t days;
	uint64_t hours;
	uint64_t minutes;
	uint64_t seconds;

	void ToNormView();
	uint64_t MounthToDays(MOUNTH mounth);

	
};


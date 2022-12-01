#include "DateInterval.h"

int64_t DateInterval::GetYears()
{
	return years;
}

int64_t DateInterval::GetMounth()
{
	return mounth;
}

int64_t DateInterval::GetDays()
{
	return days;
}

int64_t DateInterval::GetHours()
{
	return hours;
}

int64_t DateInterval::GetMinutes()
{
	return minutes;
}

int64_t DateInterval::GetSeconds()
{
	return seconds;
}

string DateInterval::toString()
{
	string str;
	str = to_string(years) + "-" + to_string(mounth) + "-" + to_string(days) + " " +
		to_string(hours) + "::" + to_string(minutes) + "::" + to_string(seconds);
	return str;
}


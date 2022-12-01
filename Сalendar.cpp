#include "Ñalendar.h"

Date::Date()
{
	time_t t = std::time(nullptr);
	tm* now = std::localtime(&t);

	this->years = (uint64_t)now->tm_year + 1900;
	this->mounth = (uint64_t)now->tm_mon + 1;
	this->days = now->tm_mday;
	this->hours = now->tm_hour;
	this->minutes = now->tm_min;
	this->seconds = now->tm_sec;
}

Date::Date(uint64_t years, MOUNTH mounth, uint64_t days, uint64_t hours, uint64_t minutes, uint64_t seconds)
{
	this->years = years;
	this->mounth = (int)mounth;
	this->days = days;
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;

	ToNormView();
}

Date::Date(uint64_t years, MOUNTH mounth, uint64_t days)
{
	time_t t = std::time(nullptr);
	tm* now = std::localtime(&t);

	this->years = years;
	this->mounth = (int)mounth;
	this->days = days;

	this->hours = now->tm_hour;
	this->minutes = now->tm_min;
	this->seconds = now->tm_sec;


	ToNormView();
}

Date::Date(uint64_t hours, uint64_t minutes, uint64_t seconds)
{
	time_t t = std::time(nullptr);
	tm* now = std::localtime(&t);

	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;

	this->years = (uint64_t)now->tm_year + 1900;
	this->mounth = (uint64_t)now->tm_mon + 1;
	this->days = now->tm_mday;

	ToNormView();
}

string Date::toString()
{
	string str;
	str = to_string(years) + "-" + to_string(mounth) + "-" + to_string(days) + " " + 
		  to_string(hours) + "::" + to_string(minutes) + "::" + to_string(seconds);
	return str;
}

Date Date::addYears(int num)
{
	Date object(*this);
	object.years += num; 

	object.ToNormView();
	return object;
}

Date Date::addMounth(int num)
{
	Date object(*this);
	object.mounth += num;

	object.ToNormView();

	return object;
}

Date Date::addDays(int num)
{
	Date object(*this);
	object.days += num;

	object.ToNormView();

	return object;
}

Date Date::addHours(int num)
{
	Date object(*this);
	object.hours += num;

	object.ToNormView();

	return object;
}

Date Date::addMinutes(int num)
{
	Date object(*this);
	object.minutes += num;

	object.ToNormView();

	return object;
}

Date Date::addSeconds(int num)
{
	Date object(*this);
	object.seconds += num;

	object.ToNormView();

	return object;
}

uint64_t Date::GetYears()
{
	return years;
}

uint64_t Date::GetMounth()
{
	return mounth;
}

uint64_t Date::GetDays()
{
	return days;
}

uint64_t Date::GetHours()
{
	return hours;
}

uint64_t Date::GetMinutes()
{
	return minutes;
}

uint64_t Date::GetSeconds()
{
	return seconds;
}

DateInterval Date::getInterval(Date& date)
{
	DateInterval dateInterval;
	Date firstDate, secondDate;

	if (this->years > date.years)
	{
		firstDate = *this;
		secondDate = date;
	}
	else
	{
		firstDate = date;
		secondDate = *this;
	}

	dateInterval.years = firstDate.years - secondDate.years;
	dateInterval.mounth = firstDate.mounth - secondDate.mounth;
	dateInterval.days = firstDate.days - secondDate.days;
	dateInterval.hours = firstDate.hours - secondDate.hours;
	dateInterval.minutes = firstDate.minutes - secondDate.minutes;
	dateInterval.seconds = firstDate.seconds - secondDate.seconds;

	if (dateInterval.seconds < 0)
	{
		dateInterval.minutes--;
		dateInterval.seconds += 60;
	}
	if (dateInterval.minutes < 0)
	{
		dateInterval.hours--;
		dateInterval.minutes += 60;
	}
	if (dateInterval.hours < 0)
	{
		dateInterval.mounth--;
		dateInterval.hours += 24;
	}
	if (dateInterval.mounth < 0)
	{
		dateInterval.mounth += 12;
		dateInterval.years--;
	}
	if (dateInterval.days < 0)
	{

		dateInterval.days += MounthToDays((MOUNTH)dateInterval.mounth);
		dateInterval.mounth--;
	}

	return dateInterval;
}

Date Date::addInterval(DateInterval& dateInterval)
{
	Date rezult;
	rezult.years = this->years + dateInterval.years;
	rezult.mounth = this->mounth + dateInterval.mounth;
	rezult.days = this->days + dateInterval.days;
	rezult.hours = this->hours + dateInterval.hours;
	rezult.minutes = this->minutes + dateInterval.minutes;
	rezult.seconds = this->seconds + dateInterval.seconds;

	rezult.ToNormView();

	return rezult;
}

string Date::FormatDate(string format)
{
	format = regex_replace(format, regex("YYYY"), to_string(this->years));
	format = regex_replace(format, regex("MM"), to_string(this->mounth));
	format = regex_replace(format, regex("DD"), to_string(this->days));
	format = regex_replace(format, regex("hh"), to_string(this->hours));
	format = regex_replace(format, regex("mm"), to_string(this->minutes));
	format = regex_replace(format, regex("ss"), to_string(this->seconds));
	return format;
}

void Date::ToNormView()
{
	minutes += seconds / 60;
	seconds %= 60;

	hours += minutes / 60;
	minutes %= 60;

	days += hours / 24;
	hours %= 24;


	while (true)
	{
		uint64_t deltaDays = MounthToDays((MOUNTH)mounth);

		if (days < (uint64_t)deltaDays)
			break;

		days -= deltaDays;
		mounth++;
		
		if (mounth == 13)
		{
			years++;
			mounth = 1;
		} 

	}

	if (years > 9999)
	{
		years = 9999;
		mounth = 12;
		days = 31;
		hours = 23;
		minutes = 59;
		seconds = 59;
	}

}

uint64_t Date::MounthToDays(MOUNTH mounth)
{
	if (mounth == Feb && years % 4 == 0 && (years % 100 != 0 || years % 400 == 0))
		return 29;
	else if (mounth == Feb)
		return 28;
	else if (mounth == Jan || mounth == Mar || mounth == May || mounth == Jul || mounth == Aug || mounth == Oct || mounth == Dec)
		return 31;
	else
		return 30;
}



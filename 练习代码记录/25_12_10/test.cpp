#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day > d._day;
		}
	}
	return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}



bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

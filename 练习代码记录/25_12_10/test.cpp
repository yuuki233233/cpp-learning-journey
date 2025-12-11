#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}



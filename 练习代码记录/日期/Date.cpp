#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while(_day < GetMonthDay(_year, _month))
	{
		_day += GetMonthDay(_year, _month);
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
	}
	
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;

	return tmp;
}
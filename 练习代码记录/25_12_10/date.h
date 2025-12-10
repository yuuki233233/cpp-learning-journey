#pragma once
#include<iostream>
using namespace std;

namespace yuuki
{
	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{ }

		void Print()
		{
			cout << _year << "/" << _month << "/" << _day << endl;
		}



	private:
		int _year;
		int _month;
		int _day;
	};

	void test_date01();

}
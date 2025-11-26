//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////重载未全局的面临对象访问私有成员变量的问题
////有几种方法可以解决：
////1. 成员公开
////2. Date提供get函数
////3. 友元函数
////4. 重载未成员函数
//bool operator==(const Date& d1,const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//
//int main()
//{
//	Date d1(2025, 11, 26);
//	Date d2(2025, 11, 27);
//
//	//运算符重载函数可以显示调用
//	operator==(d1, d2);
//
//	//编译器会转变为operator==(d1, d2);
//	d1 == d2;
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	Date& operator++()
//	{
//		cout << "前置++" << endl;
//
//		return *this;
//	}
//
//	Date operator++(int)
//	{
//		Date tmp;
//		cout << "后置++" << endl;
//
//		return tmp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//
//int main()
//{
//	Date d1(2025, 11, 26);
//	Date d2(2025, 11, 27);
//
//	// 运算符重载函数可以显示调用
//	d1.operator==(d2);
//
//	//编译器会转变为d1.operator==(d2);
//	d1 == d2;
//
//	//编译器会转换为d1.operator++();
//	++d1;
//
//	//编译器会转换为d1.operator++(0);
//	d1++;
//
//	return 0;
//}

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Func1(Date& d)
{
	cout << &d << endl;
	d.Print();
}

int main()
{
	Date d1(2025, 11, 16);
	d1.Print();

	Func1(d1);

	Date d2(d1);
	d2.Print();

	return 0;
}
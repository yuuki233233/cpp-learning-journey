//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,arr((int*)malloc(sizeof(int) * 4))
//	{
//		if (arr == nullptr)
//		{
//			perror("malloc fail!");
//			exit(1);
//		}
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* arr;
//};
//
//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& a)
//	{
//		cout << "A(const A& (int))" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "_a = " << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//A Func()
//{
//	A aa;
//
//	return aa;
//}
//
//int main()
//{
//	A a;
//	A aa = Func();
//
//	return 0;
//}

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	//Date const this;
	Date* operator&()
	{
		//可以是自己定义的值，但是要修改成定义类型

		return this;
		//return nullptr;
		//return (Date*)2256FF00X30
	}

	//const Date const this;
	const Date* operator&() const
	{
		//可以是自己定义的值，但是要修改成定义类型

		return this;
		//return nullptr;
		//return (Date*)2256FF00X46   
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	return 0;
}
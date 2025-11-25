//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
////C++升级struct升级成了类
////1、类里面可以定义函数
////2、struct名称就可以代表类型
//
////C++兼容C中struct的用法
//typedef struct ListNodeC
//{
//	struct ListNOdeC* next;
//	int val;
//}LTNode;
//
////C++中不再需要typedef，ListNodeCPP就可以代表类型
//struct ListNodeCPP
//{
//	//C++中，struct可以定义函数
//	void Init(int x)
//	{
//		next = nullptr;
//		val = x;
//	}
//
//	//不需要用struct ListNodeCPP
//	ListNodeCPP* next;
//	int val;
//};
//
//int main()
//{
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Stack
//{
//public:
//	//成员函数
//	void Init(int n = 4);
//
//private:
//	//成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//};
//
////声明和定义分离，需要指定类域
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	capacity = n;
//	top = 0;
//}
//
//int main()
//{
//	Stack st;
//	st.Init();
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
//	void Init(int year, int month, int day)
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
//private:
//	//这里只是声明，没有开辟空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//
//	d1.Init(2025, 5, 20);
//	d1.Print();
//
//	d2.Init(2026, 5, 20);
//	d2.Print();
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//
//private:
//	char _ch;
//	int _i;
//};
//
//class B
//{
//	void Print() {};
//};
//
//class C
//{ };
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//
//	cout << sizeof(a) << endl; //8
//	cout << sizeof(b) << endl; //1
// 	cout << sizeof(c) << endl; //1
//
//	return 0;
//}



class Date
{
public:
	// void Init(Date* const this, int year, int month, int day)
	void Init(int year, int month, int day)
	{
		//类里的函数里面加指针this解引用，两种都可行
		this->_year = year;
		this->_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	//这里只是声明，没有开辟空间
	int _year;
	int _month;
	int _day;
};

int main()
{
	// Date类实例化出对象d1和d2
	Date d1;
	Date d2;

	// d1.Init(&d1, 2024, 3, 31);
	d1.Init(2025, 5, 20);
	d1.Print();

	d2.Init(2026, 5, 20);
	d2.Print();

	return 0;
}
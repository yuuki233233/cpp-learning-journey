#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>原始写法
//// 学生
//class student
//{
//public:
//	// 进入校园/图书馆/刷二维码等身份验证
//	void identity()
//	{
//		// ...
//	}
//
//	// 学习
//	void study()
//	{
//		// ..
//	}
//
//protected:
//	string _name = "yuuki";	// 姓名
//	string _address;// 地址
//	string _tel;	// 电话
//	int _age = 18;	// 年龄
//
//	int _stuid;		// 学号
//};
//
//// 老师
//class Teacher
//{
//public:
//	// 进入校园/图书馆/刷二维码等身份验证
//	void identity()
//	{
//		// ...
//	}
//
//	// 授课
//	void teaching()
//	{
//		// ...
//	}
//protected:
//	string _name = "bit";	// 姓名
//	string _address;// 地址
//	string _tel;	// 电话
//	int _age = 33;	// 年龄
//
//	string _title;	// 职称
//};


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 继承写法

// 学生老师共有部分
class Person
{
public:
	// 进入校园/图书馆/刷二维码等身份验证 (共有部分)
	void identity()
	{
		cout << "voie identity()" << _name << endl;
	}
protected:
	string _name = "yuuki";
	string _address;
	string _tel;
	int _age = 18;
};

// 学生不同部分
class Student : public Person
{
public:
	// 学习
	void study()
	{
		// ..
	}
protected:
	int _stuid;
};

// 老师不同部分
class Teacher : public Person
{
public:
	// 授课
	void teaching()
	{
		// ...
	}
protected:
	string title;
};

int main()
{
	Student s;
	Teacher t;

	s.identity();
	t.identity();

	return 0;
}
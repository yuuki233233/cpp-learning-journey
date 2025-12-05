#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void Test01()
{
	//直接构造字符串
	string s1("hello world");
	cout << s1 << endl << endl;

	//修改指定的单个字符
	s1[0] = 'x';
	cout << s1 << endl << endl;

	//修改整个字符
	for (int i = 0; i < s1.size(); i++)
		cin >> s1[i];
	cout << s1 << endl << endl;
}

void Test02()
{
	string s1("hello world");

	// 使用迭代器遍历字符串
	for (auto it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Test03()
{
	string s1("hello world");

	// 使用反向迭代器遍历字符串
	for (auto it = s1.rbegin(); it != s1.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Test04()
{
	//头插（insert接口）
	string s1("hello world");
	//s1.insert(s1.begin(), 'n');
	s1.insert(0, "x");
	cout << s1 << endl << endl;

	//头插 （insert接口）
	char ch = 'y';
	s1.insert(0, 2, ch);
	cout << s1 << endl << endl;

	//尾插（push_back接口）
	s1.push_back('l');
	cout << s1 << endl << endl;

	//尾插（insert接口）
	s1.insert(s1.end(), 'm');
	cout << s1 << endl << endl;

	//尾插（运算符重载）
	s1 += '3';
	s1 += "oooooooooooo";
	cout << s1 << endl << endl;

}

void Test05()
{
	//erase固定位置删除
	string s1("hello world");
	//头删
	s1.erase(0, 1);
	cout << s1 << endl << endl;

	s1.erase(s1.begin());
	cout << s1 << endl << endl;

	//尾删
	s1.erase(s1.size() - 1, 1);
	cout << s1 << endl << endl;

	s1.erase(--s1.end());
	cout << s1 << endl << endl;

	//默认删除第六位后面全部字符
	string s2("hello world");
	s2.erase(6);
	cout << s2 << endl << endl;

	
}

void Test06()
{
	string s1("hello world");

	int pos = s1.find(' ');
	
	cout << s1 << endl;
}

void Test07()
{
	string s2("hello worldxxxxxxxxxxxxx");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(28);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(40);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	cout << typeid(string::iterator).name() << endl;
	cout << typeid(string::reverse_iterator).name() << endl;

}

int main()
{
	//Test01();
	//Test02();
	//Test03();
	//Test04();
	Test05();
	//Test07();

	return 0;
}
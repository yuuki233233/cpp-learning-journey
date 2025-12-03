//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//
//	//正向迭代器
//	//string::iterator it = s1.begin();
//	auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	
//	//反向迭代器
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	const string s2("hello world");
//	//const正向迭代器
//	//string::const_iterator cit = s2.begin();
//	auto cit = s2.begin();
//	while (cit != s2.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	//const反向迭代器
//	//string::const_reverse_iterator rcit = s2.rbegin();
//	auto rcit = s2.rbegin();
//	while (rcit != s2.rend())
//	{
//		cout << *rcit << " ";
//		++rcit;
//	}
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int func1()
//{
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = func1();
//
//
//	//auto必须初始化
//	//auto e;
//
//
//	//识别auto类型
//	cout << typeid(b).name() << endl; //int
//	cout << typeid(c).name() << endl; //char
//	cout << typeid(d).name() << endl; //int
//	
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;

int main()
{
	//C++98遍历
	int array1[] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
	{
		array1[i] *= 2;
	}
	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
	{
		cout << array1[i] << " ";
	}
	cout << endl;


	//C++11遍历
	int array2[] = { 1,2,3,4,5 };
	for (auto& e : array2)
		e *= 2;

	for (auto& e : array2)
		cout << e << " ";
	cout << endl;

	string str("hello world");
	for (auto ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}
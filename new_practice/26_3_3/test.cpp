#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//// 引出智能指针
//double Divide(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Divide by zero condition!";
//	}
//	else
//	{
//		return (double)a / (double)b;
//	}
//}
//
//void Func()
//{
//	// 如果发生除0错误抛出异常，另外下面的 array1 和 array2 没有得到释放
//	// 捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去
//	// 但如果 array2 抛异常，就还需要写异常捕获释放逻辑，这里更好的办法是智能指针
//	int* array1 = new int[10];
//	int* array2 = new int[10];
//
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Divide(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array1 << endl;
//		cout << "delete []" << array2 << endl;
//
//
//		delete[] array1;
//		delete[] array2;
//
//		throw;
//	}
//
//	cout << "delete []" << array1 << endl;
//	delete[] array1;
//
//	cout << "delete []" << array2 << endl;
//	delete[] array2;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown" << endl;
//	}
//
//	return 0;
//}

// 智能指针
template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}

	~SmartPtr()
	{
		cout << "delete[] " << _ptr << endl;
		delete[] _ptr;
	}

	// 重载运算符，模拟指针的⾏为，⽅便访问资源
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator[](size_t i)
	{
		return _ptr[i];
	}

private:
	T* _ptr;
};

double Divide(int a, int b)
{
	if (b == 0)
	{
		throw "Divide by zero condition!";
	}
	else
	{
		return (double)a / (double)b;
	}
}

void Func()
{
	// 智能指针：自动初始化、自动析构，不需重复捕获异常
	SmartPtr<int> sp1 = new int[10];
	SmartPtr<int> sp2 = new int[10];
	SmartPtr<int> sp3 = new int[10];
	SmartPtr<int> sp4 = new int[10];

	SmartPtr<pair<int, int>> sp5 = new pair<int, int>[10];

	sp1[5] = 50;		// operator[]
	sp5->first = 1;		// operator->()
	sp5->second = 2;	// operator->()

	// unique_ptr 不支持拷贝构造，支持移动构造
	unique_ptr<int> up1(new int);
	// unique_ptr<int> up2(up1);
	unique_ptr<int> up2(move(up1));

	// shared_ptr 支持拷贝构造和移动构造
	shared_ptr<int> _sp1(new int);
	shared_ptr<int> _sp2(_sp1);
	shared_ptr<int> _sp3(_sp2);

	int len, time;
	cin >> len >> time;
	cout << Divide(len, time) << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown" << endl;
	}

	return 0;
}
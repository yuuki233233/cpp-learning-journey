#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<memory>

class Date
{
public:
	Date(int year = 2026, int month = 3, int day = 4)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

	//private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

template<class T>
void DeleteArrayFunc(T* ptr)
{
	delete[] ptr;
}

template<class T>
class DeleteArray
{
public:
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		if (ptr != nullptr)
		{
			cout << "fclose" << ptr << endl;
			fclose(ptr);
		}
	}
};

int main()
{
	// 因为数组使用频繁，特化了[]版本
	unique_ptr<Date[]> up1(new Date[5]);
	shared_ptr<Date[]> sp1(new Date[5]);

	// 仿函数
	unique_ptr<Date, DeleteArray<Date>> up2(new Date[5]);
	shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());

	// 函数指针
	unique_ptr<Date, void(*)(Date*)> up3(new Date[5], DeleteArrayFunc<Date>);
	shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>);

	// lambda
	auto Func = [](Date* ptr) {delete[] ptr; };
	unique_ptr<Date, decltype(Func)> up4(new Date[5], Func);
	shared_ptr<Date> sp4(new Date[5], [](Date* ptr) {delete[] ptr; });

	// 其他资源
	unique_ptr<FILE, Fclose> up5(fopen("test2.cpp", "r"));

	auto FUNC = [](FILE* ptr) {fclose(ptr); };
	unique_ptr<FILE, decltype(FUNC)> up6(fopen("test2.cpp", "r"), FUNC);

	shared_ptr<FILE> sp5(fopen("test2.cpp", "r"), Fclose());

	shared_ptr<FILE> sp6(fopen("test.cpp", "r"), [](FILE* ptr) {
		delete[] ptr;
		fclose(ptr);
		});

	return 0;
}
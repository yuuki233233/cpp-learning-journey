#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<memory>

namespace yuuki
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{ }

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete[]:" << _ptr << endl;
				delete _ptr;
			}
		}

		// unique_ptr 不支持拷贝和赋值
		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

		// unique_ptr 支持移动
		unique_ptr(unique_ptr<T>&& sp)
			:_ptr(sp._ptr)
		{
			sp._ptr = nullptr;
		}

		unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		{
			delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}

		// pair
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

namespace yuuki
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_count(new int(1))
		{ }

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_count(sp._count)
		{
			(*_count)++;
		}

		// sp2 = sp1  sp1 = sp1  sp3 = sp1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				if (--(*_count) == 0) // 计数减到0才释放
				{
					delete _ptr;
					delete _count;
				}
				_ptr = sp._ptr;
				_count = sp._count;
				++(*_count); // 新增引用计数
			}

			return *this;
		}

		// 每次析构 sp2 _pcount 计数需--
		~shared_ptr()
		{
			if (--(*_count) == 0)
			{
				delete _ptr;
				delete _count;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_count;
		}

	private:
		T* _ptr;
		int* _count;
	};
}

struct Date
{
public:
	Date(int year = 2026, int month = 3, int day = 9)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }

	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

int main()
{
	/*yuuki::unique_ptr<Date> up1(new Date);
	yuuki::unique_ptr<Date> up2(move(up1));*/

	yuuki::shared_ptr<Date> sp1(new Date);
	yuuki::shared_ptr<Date> sp2(sp1);
	yuuki::shared_ptr<Date> sp3 = sp1;
	cout << "sp1.use_count(): " << sp1.use_count() << endl; // 3

	yuuki::shared_ptr<Date> sp4(new Date);
	sp1 = sp4;
	cout << "sp1.use_count(): " << sp1.use_count() << endl; // 2

	// 自己给自己赋值
	sp1 = sp1;
	cout << "sp1.use_count(): " << sp1.use_count() << endl; // 2

	return 0;
}
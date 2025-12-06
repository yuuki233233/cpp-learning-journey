#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new  char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		//别忘了加'\0'
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//需要多少扩多少
			//reserve(_size + len);

			//二倍扩容（避免频繁扩容）
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		strcpy(_str + _size, str);
		_size += len;
	}

	//单字符
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	//字符串（不能按二倍扩容）
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		//挪动数据
		size_t end = _size;
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}

	//void string::insert(size_t pos, const char* str);
	//void string::erase(size_t pos, size_t);

	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); ++i)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		//char* it = s2.begin();
		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		s1 += "hello yuuki";
		cout << s1.c_str() << endl;

		s1.insert(5, '$');
		cout << s1.c_str() << endl;
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki233233
{
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
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
		_str[_size] = '\0';
	}
	
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
		}

		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	size_t string::size() const
	{
		return _size;
	}

	size_t string::capacity() const
	{
		return _capacity;
	}

	char& string::operator[](size_t pos)
	{
		assert(pos < _size);

		return _str[pos];
	}

	const char& string::operator[](size_t pos) const
	{
		assert(pos < _size);

		return _str[pos];
	}


}
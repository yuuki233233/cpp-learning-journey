#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));

				delete[] _start;
				_start = tmp;
				//-----------------------------------
				//_finish = _start + size();	//size为新的，需要旧的size
				_finish = tmp + old_size;
				_end_of_storage = _start + n;
			}
		}

		void push_back(char ch)
		{
			if (_start == _finish)
			{
				reserve(capacity() == 0 ? 4 : capacity()* 2);
			}

			*_finish = ch;
			++_finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{

			return _end_of_storage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto E : v)
		{
			cout << E << " ";
		}
		cout << endl;
	}
}
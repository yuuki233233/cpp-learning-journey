#pragma once

namespace yuuki
{
	// 类似于完全二叉树
	template<class T, class Container = vector<T>>
	class priorityqueue
	{
	public:
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				// 大堆
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push_back(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(size_t parent)
		{
			size_t child = (parent * 2) + 1;
			while (child > _con.size())
			{
				if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				{
					++child;
				}

				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					parent = (child * 2) + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		T& top()
		{
			return _con.front();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}


	private:
		Container _con;
	};
}
#pragma once
#include<iostream>
using namespace std;

namespace yuuki
{
	// 节点
	template<class T>
	class list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};


	// 结构
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		// 构造
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		// 尾插
		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->next = newnode;
			newnode->_prev = tail;
			newnode->next = _head;
			_head->_prev = newnode;

			++_size;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			//return _head->next == _head;
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};
}
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki
{
	template<class T>
	struct list_node // 要经常访问节点，这里用struct(公开：类似于public)
	{
		T _data;				// 节点大小
		list_node<T>* _next;	// 指向下一个节点的指针
		list_node<T>* _prev;	// 指向上一个节点的指针

		// 拷贝构造
		list_node(const T& data = T()) // 匿名对象(一次性) 
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	// T(类型)  Ref(迭代器(包含cons迭代器))  Ptr(结构体(两变量以上))
	template<class T, class Ref, class Ptr>
	struct list_iterator // 要经常访问迭代器，这里用struct
	{
		typedef list_node<T> Node; // 节点
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node) // 构造节点
			:_node(node)
		{ }

		// 前置++
		Ref& operator++()
		{
			_node = _node->_next;	// 下一个节点的迭代器
			return *this;			// 返回自身
		}

		// 后置++
		Ref operator++(int)
		{
			Self tmp(*this);	// 拷贝构造旧迭代器位置
			_node = _node->_next;
			return tmp;
		}

		// 前置--
		Ref& operator--()
		{
			_node = _node->_prev;	// 上一个节点的迭代器
			return *this;			// 返回自身
		}

		// 后置--
		Ref operator--(int)
		{
			Self tmp(*this);	// 拷贝构造旧迭代器位置
			_node = _node->_prev;
			return tmp;
		}

		// 两个迭代器比较
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)
		{
			return _node == s._node;
		}

		// 解迭代器的引用 (*it)
		Ref operator*()
		{
			return _node->_data;
		}

		// 结构体箭头的重载 (it->_a1)
		Ptr operator->()
		{
			return &_node->_data;
		}
	};

	template<class T>
	class list // 链表
	{
		typedef list_node<T> Node; // 链表由节点构成，需要调用节点
	public:
		typedef list_iterator<T, T&, T*> iterator; // 可读可写迭代器
		typedef list_iterator<T, const T&, const T*> const_iterator; // 只读不写迭代器

		iterator begin()
		{
			/*iterator it(_head->_next); // 有名对象
			return it;*/

			//return iterator(_head->_next); // 匿名对象

			return _head->_next; // 隐式类型转换
		}

		const_iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator end()
		{
			return _head;
		}

		// 构造
		list()
		{
			_head = new Node; // 给哨兵位提供个节点
			_head->_next = _head;
			_head->_prev = _head; // 节点指向自己
			_size = 0;
		}

		// 链表拷贝时需要一个哨兵位(常见错误点)
		void empty_init()
		{
			_head = new Node; // 给哨兵位提供个节点
			_head->_next = _head;
			_head->_prev = _head; // 节点指向自己
			_size = 0;
		}

		// 拷贝构造 lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init(); // 提供哨兵位头节点

			for (auto& e : lt) // 尾插出个一样的链表
			{
				push_back(lt);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// 赋值运算符(现代写法)(lt2 = lt1)
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		// 删除指定迭代器的位置
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;

			return next; // 隐式类型转换(返回删除的位置)
		}

		// 清理链表
		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		// 析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		// 固定位置插入
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;		// 指向节点pos的指针
			Node* prev = cur->_prev;	// 指向pos节点前一个节点

			Node* newnode = new Node(x); // 创建节点

			// prev newnode cur
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			++_size;
		}

		// 尾插(直接调用插入函数)
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		// 头插(直接调用插入函数)
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		// 头删
		void pop_front()
		{
			erase(begin());
		}

		// 尾删
		void pop_back()
		{
			erase(end());
		}

		size_t size() const
		{
			return _size;
		}

		// 判空
		bool empty() const
		{
			// return _head->next == _head;
			return _size == 0;
		}
	private:
		Node* _head;	// 头节点(哨兵位)
		size_t _size;	// 计节点个数数
	};

	// 支持所有容器
	// 按需实例化
	template<class Container>
	void print_container(const Container& v)
	{
		// const iterator -> 迭代器本身不能修改
		// const_iterator -> 指向内容不能修改

		//list<int>::const_iterator it = v.const_begin();
		auto it = v.begin();
		while (it != v.begin())
		{
			// const迭代器只读不写
			//*it += 10; 
			cout << *it << " ";
			++it;
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
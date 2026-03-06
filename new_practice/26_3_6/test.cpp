#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
struct ListNode
{
	T _data;

	/*shared_ptr<ListNode> _next;
	shared_ptr<ListNode> _prev;*/

	// 这里改成 weak_ptr，当 n1->_next = n2，绑定 shared_ptr 时
	// 不增加 n2 的引用计数，不参与资源释放的管理，就不会形成循环引用
	weak_ptr<ListNode> _next;
	weak_ptr<ListNode> _prve;


	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

//int main()
//{
//	shared_ptr<ListNode<int>> n1(new ListNode<int>);
//	shared_ptr<ListNode<int>> n2(new ListNode<int>);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	n1->_next = n2;
//	n2->_prve = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	return 0;
//}

#include<string>
int main()
{
	shared_ptr<string> p1(new string("1"));
	shared_ptr<string> p2(p1);
	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;

	weak_ptr<string> wp = p1;
	// expired 判断是否释放资源，false 表示没释放， true 表示已释放
	cout << wp.expired() << endl;		// 0：没释放
	cout << wp.use_count() << endl;		// 2

	p1 = make_shared<string>("2");
	cout << "*p1 = " << *p1 << endl;
	cout << wp.expired() << endl;		// 0：没释放
	cout << wp.use_count() << endl;		// 1

	p2 = make_shared<string>("3");
	cout << "*p2 = " << *p2 << endl;

	cout << wp.expired() << endl;		// 1：释放
	cout << wp.use_count() << endl;		// 0

	// p2已被改动，所以计数为1
	wp = p1;
	cout << wp.expired() << endl;		// 0：没释放
	cout << wp.use_count() << endl;		// 1

	shared_ptr<string> p3 = wp.lock();
	cout << wp.expired() << endl;		// 0
	cout << wp.use_count() << endl;		// 2
	// lock 返回一个 shared_ptr，自己生成一个 shared_ptr，保证这份不被制空
	// 可以用 shared_ptr 或 auto 接受类型
	// lock：在资源没释放之前，里面再产生一个 shared_ptr 管理这份资源
	*p3 += "$$$";
	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;
	cout << "*p3 = " << *p3 << endl;


	return 0;
}
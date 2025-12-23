#define _CRT_SECURE_NO_WARNIN
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

#include"模拟实现Queue.h"
#include"模拟实现Stack.h"

//int main()
//{
//	//yuuki::stack<int, vector<int>> st;
//	//yuuki::stack<int, list<int>> st;
//	yuuki::stack<int, vector<int>> st;
//
//	// 类模板实例化时，按需实例化，使用哪些成员函数就实列化哪些，不会全实列化
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl; // 4
//	st.pop(); 
//
//	//yuuki::queue<int, list<int>> q;
//	yuuki::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	cout << q.front() << endl; // 1
//	q.pop();
//
//	return 0;
//}

void test_op2()
{
	srand(time(0));
	const int N = 1000000;

	deque<int> dq1;
	deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(dq1.begin(), dq1.end());
	int end1 = clock();

	int begin2 = clock();
	// 拷贝到vector
	vector<int> v(dq2.begin(), dq2.end());
	sort(v.begin(), v.end());
	dq2.assign(v.begin(), v.end());
	int end2 = clock();

	printf("deque sort:%d\n", end1 - begin1);
	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
}

int main()
{
	test_op2();

	return 0;
}
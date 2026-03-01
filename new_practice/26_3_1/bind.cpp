#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<functional> // bind 在 functional 头文件中

// bind 中参数所对应的位置
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

/* 普通函数 */
int Sub(int a, int b)
{
	return (a - b) * 10;
}

int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}

/* 外部类 */
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main()
{
	// 语法：auto newCallable = bind(callable, arg_list);
	// newCallable 是可调用对象，arg_list 是参数列表，对应 callable 的参数

	/* 
	* bind 本质返回一个仿函数对象 
	* _1 代表第一个实参，_2 代表第二个实参
	* 
	* 1. 可修改参数位置（不常用）
	* 2. 可修改参数数量（常用）
	*/

	/* 有两个参数的函数 */
	// 修改参数位置
	auto sub1 = bind(Sub, _1, _2);
	auto sub2 = bind(Sub, _2, _1);
	cout << sub1(10, 5) << endl;	// 50
	cout << sub2(10, 5) << endl;	// -50

	// 修改参数数量和位置
	auto sub3 = bind(Sub, 100, _1);
	auto sub4 = bind(Sub, _1, 100);
	cout << sub3(5) << endl;	// 950
	cout << sub4(5) << endl;	// -950

	/* 有三个参数的函数 */
	// 情况与上面一样，我们看看修改参数数量和位置
	auto sub5 = bind(SubX, 100, _1, _2);
	auto sub6 = bind(SubX, _1, 100, _2);
	auto sub7 = bind(SubX, _1, _2, 100);
	cout << sub5(5, 1) << endl;	// 940
	cout << sub6(5, 1) << endl; // -960
	cout << sub7(5, 1) << endl; // -960

	//💡 bind 可以绑死固定的参数，在新对象中就不用写出来
	// 在包装器与到外部类时，每次都需要传 this 指针，是不是也可以简化掉
	/* 原始写法 */
	function<double(Plus&&, double, double)> f1 = &Plus::plusd;
	Plus pd;
	cout << f1(move(pd), 1.1, 1.1) << endl;	// 2.2
	cout << f1(Plus(), 1.1, 1.1) << endl;	// 2.2

	/* 用 bind 绑死固定的参数 */
	function<double(double, double)> f2 = bind(&Plus::plusd, Plus(), _1, _2);
	cout << f2(1.1, 1.1) << endl; // 2.2

	/* bind 与 lambda 混合使用：银行复利计算 */
	// 计算复利的 lambda
	auto func1 = [](double rate, double money, int year)
		{
			double ret = money;
			for (int i = 0; i < year; i++)
			{
				ret += ret * rate;	// 年利润 = 本金 * 利息
			}

			return ret - money;
		};

	// 绑死一些参数，实现不同年利润，不同金额和不同年份的复利
	function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
	function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
	function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);
	function<double(double)> func20_3_5 = bind(func1, 0.035, _1, 20);

	cout << func3_1_5(1000000) << endl;		// 45678.4
	cout << func5_1_5(1000000) << endl;		// 77284
	cout << func10_2_5(1000000) << endl;	// 280085
	cout << func20_3_5(1000000) << endl;	// 989789

	return 0;
}
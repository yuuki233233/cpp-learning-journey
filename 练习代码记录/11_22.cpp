//C++兼容C
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}

//C语言命名冲突
//#include<stdio.h>
//#include<stdlib.h>
//int rand = 9;
//
//int main()
//{
//	printf("%d", rand);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////域
//namespace yuuki
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;	//常量
//
//	//函数
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	//结构体
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//}//注意：没有分号
//
//int main()
//{
//	// 这里默认是访问的是全局的rand函数指针
//	printf("rand = %p\n", rand);
//	// 这里指定bit命名空间中的rand
//	printf("yuuki::rand = %d\n", yuuki::rand);
//
//	printf("yuuki::Add = %p\n", yuuki::Add);
//	printf("yuuki::Add(1, 2) = %d\n", yuuki::Add(1, 2));
//
//	struct yuuki::Node node;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
////域
//namespace yuuki
//{
//	int rand = 10;
//}
//
//int a = 0;
//
//int main()
//{
//	int a = 1;
//	cout << "a = " << a << endl; //1
//
//	// ::域作用限定符
//	cout << "::a = " << ::a << endl; //0
//	cout << "yuuki::rand = " << yuuki::rand << endl; //10
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//namespace yuuki
//{
//	namespace A
//	{
//		int rand = 10;
//		int Add(int x, int y)
//		{
//			return x + y;
//		}
//	}
//
//	namespace B
//	{
//		int rand = 20;
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}
//
//int main()
//{
//	printf("yuuki->A->rand = %d\n", yuuki::A::rand);
//	printf("yuuki->B->rand = %d\n", yuuki::B::rand);
//
//	printf("yuuki->A->Add = %d\n", yuuki::A::Add(1, 1));
//	printf("yuuki->B->Sub = %d\n", yuuki::B::Sub(1, 1));
//
//	return 0;
//}

//#include<stdio.h>
//namespace yuuki
//{
//	int a = 0;
//	int b = 1;
//}
//int main()
//{
//	// 编译报错：error C2065: “a”: 未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}

//// 指定命名空间访问
//#include<stdio.h>
//namespace N
//{
//	int a = 10;
//	int b = 20;
//}
////int main()
////{
////	printf("%d\n", N::a);
////	return 0;
////}
//
//// using将命名空间中某个成员展开
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//// 展开命名空间中全部成员
//using namespce N;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}
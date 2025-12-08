#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki
{
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
		//ÔËËã·ûÖØÔØµ¥×Ö·û
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		//ÔËËã·ûÖØÔØ×Ö·û´®
		s1 += "hello yuuki";
		cout << s1.c_str() << endl;

		//²åÈëµ¥×Ö·û
		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		//²åÈë×Ö·û´®
		s1.insert(6, "######");
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

		string s3("hello world");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;

		string s4("hello world");
		s4.erase(2, 1);
		cout << s4.c_str() << endl;
	}

	
}

int main()
{
	// yuuki::test_string1(); 
	//yuuki::test_string2();
	// yuuki::test_string3();
	yuuki::test_string4();
	return 0;
}
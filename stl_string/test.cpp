#include"string.h"


//void test1()
//{
//	myString::string s1("hello world");
//	cout << s1 << endl;
//	for (auto e : s1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//}
//void test2()
//{
//	myString::string s1("hello world");
//	//s1.~string();
//	cout << s1.size() << endl;
//}
void test1()
{
	myString::string s1;
	myString::string s2("hello world");
	myString::string s3(s2);
	const string s4("hello world");
	cout << s2.size() << endl;
	cout << s1.capacity() << endl;
	cout << s3.capacity() << endl;
	s2.reserve(100);
	s3.resize(100, 'a');
	cout << s2.c_str() << endl;
	s2[6] = 'x';
	cout << s2.c_str() << endl;
}
void test2()
{
	myString::string s1("hello world!!!");
	cout << s1.c_str() << endl;
	s1.push_back('a');
	s1.push_back('b');
	s1.push_back('c');
	s1.append("append");
	myString::string s2("bit");
	s1.append(s2);
	cout << s1.c_str() << endl;
	s1 += '1';
	s1 += "22";
	myString::string s3("333");
	s1 += s3;
	cout << s1.c_str() << endl;
}
void test3()
{
	myString::string s1("hello world");
	cout << s1.find('o') << endl;
	cout << s1.find('o', 4) << endl;
	cout << s1.find('o', 5) << endl;
	cout << s1.find('a') << endl;

	s1.insert(5, "123");
	s1.insert(0, "x");
	cout << s1.c_str() << endl;
	s1.insert(s1.size(), "size");
	cout << s1.c_str() << endl;
	cout << "------" << endl;
	myString::string s2("hello world");
	myString::string s3 = s2;
	myString::string s4 = s2;
	myString::string s5 = s2;
	myString::string s6 = s2;
	s2.erase(5, 3);
	s3.erase(0, 3);
	s4.erase(3, 20);
	s5.erase(0, 20);
	s6.erase();
	cout << "========" << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	cout << s4.c_str() << "4" << endl;
	cout << s5.c_str() << "5" << endl;
	cout << s6.c_str() << "6" << endl;

	cout << "===========" << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << "4" << endl;
	cout << s5 << "5" << endl;
	cout << s6 << "6" << endl;
}
void test4()
{
	string s1;
	//cin >> s1.c_str();
}
void test5()
{
	myString::string s1("aaahelloaaa world");
	cout << s1.find('o') << endl;
	cout << s1.find('o', 8) << endl;
	cout << s1.find("aaa") << endl;
	cout << s1.find("aaa", 3) << endl;
	cout << s1.find("aaaa") << endl;
	myString::string s2 = s1.substr(2, 5);
	myString::string s3 = s1.substr(2);
	myString::string s4 = s1.substr();
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}
int main()
{
	//test1();
	/*int a = 10;
	double b = 20;
	string s1 = to_string(a);
	string s2 = to_string(b);
	cout << s1 << endl << s2 << endl;
	const char* p = "12";
	int chh = atoi(p);
	cout << chh +1<< endl;*/
	//test1();
	//test3();

	test5();

	return 0;
}
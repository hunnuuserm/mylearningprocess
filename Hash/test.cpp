#include<iostream>
#include<unordered_map>
#include"hash.h"

using namespace std;

void test1()
{
	class B
	{
	public:
		B()
		{
			cout << "B()" << endl;
		}
	};
	class A
	{
	public:
		A()
		{
			cout << "A()" << endl;
		}
		~A()
		{
			cout << "~A()" << endl;
		}
	private:
		B _b;
	};

	/*int a = 1;
	if (a)
	{
		A aa;
	}
	cout << "---" << endl;*/
	A a;
}

void test2()
{
	openAddress::hashTable<int, int> t;
	t.insert(make_pair(1, 1));
	t.insert(make_pair(2, 2));
	t.insert(make_pair(3, 3));
	t.insert(make_pair(4, 4));
	t.insert(make_pair(5, 5));
}

void test3()
{
	class B
	{
	public:
		B()
		{	cout << "B()" << endl;}
		~B()
		{	cout << "~B()" << endl;}
	};
	class A
	{
	public:
		A()
		{	cout << "A()" << endl;}
		~A()
		{cout << "~A()" << endl;}
	private:
		B _b;
	};

	A a;
}
void test4()
{
	hashBucket::hashTable<int, int> t;
	t.insert(make_pair(1, 1));
	t.insert(make_pair(2, 2));
	t.insert(make_pair(3, 3));
	t.insert(make_pair(13, 13));
	t.insert(make_pair(33, 33));
	t.insert(make_pair(4, 4));
	t.insert(make_pair(5, 5));

	t.erase(3);
}

void test5()
{
	hashBucket::hashTable<int, string> t;
	t.insert(make_pair(1, "11"));
	t.insert(make_pair(2, "22"));
	t.insert(make_pair(3, "33"));
	t.insert(make_pair(4, "44"));
	t.insert(make_pair(5, "55"));

}

void test6()
{
	hashBucket::hashTable<double, int> t;
	t.insert(make_pair(1.3, 1));
	t.insert(make_pair(2.3, 2));
	t.insert(make_pair(3.3, 3));
}

void test7()
{
	hashBucket::hashTable<string, int> t;
	t.insert(make_pair("1", 1));
	t.insert(make_pair("2", 2));
	t.insert(make_pair("3", 3));
}

int main()
{
	test7();
	/*vector<int> v;
	v.resize(10);*/
	unordered_map<string, string> m;
	unordered_map<int,string> m1;
	return 0;
}
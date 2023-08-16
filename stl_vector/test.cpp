#include"vector.h"

void test1()
{
	myVector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	myVector::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	myVector::vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	myVector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);

	v1.resize(20,99);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	myVector::vector<int> v11;
	v11.push_back(1);
	v11.push_back(2);
	v11.push_back(3);
	v11.push_back(4);
	v11.push_back(5);
	v11.push_back(6);
	v11.push_back(7);
	v11.push_back(8);

	v11.resize(4);
	for (auto& e : v11)
	{
		cout << e << " ";
	}
	cout << endl;

	myVector::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.resize(7);
	for (auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	myVector::vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);
	v3.resize(7,11);
	for (auto& e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	myVector::vector<int> v4;
	v4.push_back(1);
	v4.push_back(2);
	v4.resize(7);
	for (auto& e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	myVector::vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.resize(7, 5);
	for (auto& e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	//myVector::vector<int> v1;
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(4);
	//myVector::vector<int> ::iterator ret = find(v1.begin(), v1.end(), 3);
	//if (ret != v1.end())
	//{
	//	v1.insert(ret, 33);
	//}
	//for (auto& e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	myVector::vector<int> v2;
	v2.push_back(1);
	/*v2.push_back(2);
	v2.push_back(3);*/
	v2.push_back(4);
	v2.push_back(5);
	auto ret2 = find(v2.begin(), v2.end(), 4);
	if (ret2 != v2.end())
	{
		auto ret3=v2.insert(ret2, 41);
		auto ret4=v2.insert(ret3, 42);
		/* v2.insert(ret2, 41);
		 v2.insert(ret2, 42);*/
		v2.insert(ret4, 43);
	}
	for (auto& e1 : v2)
	{
		cout << e1 << " ";
	}
	cout << endl;
}

void test4()
{
	//vector<int> v1;
	myVector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);

	auto p = v1.begin();
	while (p != v1.end())
	{
		if ((*p) % 2 == 0)
		{
			p=v1.erase(p);
		}
		else
		{
			p++;
		}
	}

	for (auto& e1 : v1)
	{
		cout << e1 << " ";
	}
	cout << endl;
}
void test5()
{
	myVector::vector<int> v;
	//v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.push_back(5);
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(8);

	// 在所有的偶数前面插入一个偶数2倍
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it=v.insert(it, *it * 2);
			it++;
			it++;
		}
		else
		{
			it++;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test6()
{
	myVector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);

	v1.push_back(4);
	v1.push_back(5);

	myVector::vector<int> v2 = v1;
	for (auto &e : v2)
	{
		cout << e << ' ';
	}
	cout << endl;

	myVector::vector<myVector::vector<int>> v3;
	v3.push_back(v1);
	v3.push_back(v1);
	v3.push_back(v1);
	v3.push_back(v1);
	v3.push_back(v1);
}

void test7()
{
	string s = "abcdefg";
	myVector::vector<int> v(s.begin(), s.end());
	for (auto& e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void test8()
{
	myVector::vector<int> v1(10, 5);
	myVector::vector<int> v2;
	v2 = v1;
	for (auto& e : v2)
	{
		cout << e << ' ';
	}
	cout << endl;
}
int main()
{
	test8();
	return 0;
}
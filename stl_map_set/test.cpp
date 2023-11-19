#include<iostream>
#include"map.h"
#include"set.h"
using namespace std;

void test1()
{
	m::map<int, int> m;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto& e : arr)
	{
		m.insert(make_pair(e, e));
	}
	
}
void test2()
{
	m::set<int> s;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int arr[] = { 16,7};
	for (auto& e : arr)
	{
		s.insert(e);
	}
	
	m::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << (*it) << " ";
		++it;
	}
	cout << endl;

}

void test3()
{
	m::map<int, int> m;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto& e : arr)
	{
		m.insert(make_pair(e, e));
	}
	m::map<int, int> ::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << " ";
		++it;
	}
	cout << endl;

	m[11] = 11111;
	it = m.begin();
	m[100] = 100;
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << " ";
		++it;
	}
	cout << endl;

}

int main()
{
	test3();
	return 0;
}
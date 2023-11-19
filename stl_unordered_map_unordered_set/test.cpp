#include<iostream>
#include"unordered_map.h"
#include"unordered_set.h"
//#include<unordered_map>

using namespace std;


void test_set1()
{
	m::unordered_set<int> s;
	s.insert(5);
	s.insert(7);
	s.insert(3);
	s.insert(2);
	s.insert(9);
	s.insert(33);
	s.insert(13);
	s.insert(12);

	s.erase(3);

}

void test_map1()
{
	m::unordered_map<int, int> m;
	m.insert(make_pair(1, 1));
	/*m.insert(make_pair(7, 7));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(9, 9));*/
	m.insert(make_pair(3, 3));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(12, 12));
	m.insert(make_pair(13, 13));
	m.insert(make_pair(33, 33));
	m.insert(make_pair(63, 63));
	m.insert(make_pair(11, 11));

	m.erase(63);
}

class Date
{
	friend struct hashDateFunc;
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	bool operator!=(const Date& d)const
	{
		return _year != d._year || _month != d._month || _day != d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

struct hashDateFunc
{
	size_t operator()(const Date& d)
	{
		size_t hashi = 0;
		hashi += d._year;
		hashi *= 31;

		hashi += d._month;
		hashi *= 31;

		hashi += d._day;
		hashi *= 31;

		return hashi;
	}
};
void test_set3()
{
	m::unordered_set<Date, hashDateFunc> s;
	s.insert(Date(2023, 11, 19));
	s.insert(Date(2023, 11, 18));
	s.insert(Date(2023, 11, 20));
	s.insert(Date(2023, 11, 15));
	s.insert(Date(2022, 11, 19));
	s.insert(Date(2023, 11, 10));
}

void test_set4()
{
	m::unordered_set<int> s;
	s.insert(5);
	s.insert(7);
	s.insert(3);
	s.insert(2);
	s.insert(9);
	s.insert(33);
	s.insert(13);
	s.insert(12);
	m::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void func(int*& a)
{
	cout << "void func(int*& a)" << endl;
}

void test_map2()
{
	m::unordered_map<int, int> m;
	m.insert(make_pair(5, 5));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(9, 9));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(12, 12));
	m.insert(make_pair(13, 13));
	m.insert(make_pair(33, 33));
	m.insert(make_pair(15, 15));

	m::unordered_map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
void test_map3()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };
	m::unordered_map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_set5()
{
	m::unordered_set<int> s;
	s.insert(5);
	s.insert(7);
	s.insert(3);
	s.insert(2);
	s.insert(9);
	s.insert(33);
	s.insert(13);
	s.insert(12);
	m::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_map5()
{
	m::unordered_map<int, int> m;
	m.insert(make_pair(5, 5));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(9, 9));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(12, 12));
	m.insert(make_pair(13, 13));
	m.insert(make_pair(33, 33));
	m.insert(make_pair(15, 15));

	m::unordered_map<int, int>::iterator it = m.begin();
	int i = 0;
	while (it != m.end())
	{
		//it->first = 1;
		it->second = 1;
		cout << i++ << ":" << "(" << it->first << "," << it->second << ")" << endl;
		++it;
	}
	cout << endl;
}

void print_set(const m::unordered_set<int>& s)
{
	m::unordered_set<int>::const_iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test_set6()
{
	m::unordered_set<int> s;
	s.insert(5);
	s.insert(7);
	s.insert(3);
	s.insert(2);
	s.insert(9);
	s.insert(33);
	s.insert(13);
	s.insert(12);
	print_set(s);
}

void print_map(const m::unordered_map<int, int>& m)
{
	m::unordered_map<int, int>::const_iterator it = m.begin();
	int i = 0;
	while (it != m.end())
	{
		//it->first = 1;
		//it->second = 1;
		cout << i++ << ":" << "(" << it->first << "," << it->second << ")" << endl;
		++it;
	}
	cout << endl;
}

void test_map6()
{
	m::unordered_map<int, int> m;
	m.insert(make_pair(5, 5));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(9, 9));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(12, 12));
	m.insert(make_pair(13, 13));
	m.insert(make_pair(33, 33));
	m.insert(make_pair(15, 15));
	m::unordered_map<int, int>::iterator it = m.begin();
	int i = 0;
	while (it != m.end())
	{
		//it->first = 1;
		//it->second = 1;
		cout << i++ << ":" << "(" << it->first << "," << it->second << ")" << endl;
		++it;
	}
	cout << "-----------------" << endl;
	print_map(m);
}

int main()
{
	
	test_map6();
	/*test_set3();
	test_map5();*/
	/*test_map2();
	test_set4();*/
	/*int a = 1;
	int* pa = nullptr;
	func(pa);*/
	//test_map1();
	/*vector<int> v;
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i);
	}
	v.resize(20);
	int a = 1;*/
	return 0;
}
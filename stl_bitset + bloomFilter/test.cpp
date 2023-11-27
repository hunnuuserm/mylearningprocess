#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include"bitset.h"
using namespace std;


void test1()
{
	m::bitset<100> bit;
	bit.set(9);
	bit.set(10);
	bit.set(11);
	bit.set(12);
	bit.set(13);

	bit.set(16);
	bit.set(17);


	bit.reset(10);
	bit.reset(11);

	cout << "bit.test(9):" << bit.test(9) << endl;
	cout << "bit.test(12):" << bit.test(12) << endl;
	cout << "bit.test(10):" << bit.test(10) << endl;
	cout << "bit.test(11):" << bit.test(11) << endl;
	cout << "bit.test(16):" << bit.test(16) << endl;
	cout << "bit.test(17):" << bit.test(17) << endl;
	cout << "bit.test(13):" << bit.test(13) << endl;
}
void test2()
{
	srand(time(nullptr));
	const size_t N = 10000;
	string url = "https://space.bilibili.com/505199718?spm_id_from=333.1007.0.0";
	m::bloomFilter<N> bf;
	for (size_t i = 0; i < N; ++i)
	{
		bf.set(url + to_string(i));
	}


	size_t errorN = 0;
	for (size_t i = 0; i < N; ++i)
	{
		if (bf.test(url + to_string(N + i)))
		{
			++errorN;
		}
	}

	cout << "ÏàËÆ×Ö·û´®ÎóÅÐÂÊ:" << (double)errorN / N << endl;



	string url2 = "https://leetcode.cn/problems/two-sum/description/";
	errorN = 0;
	for (size_t i = 0; i < N; ++i)
	{
		if (bf.test(url2 + to_string(i + rand())))
		{
			++errorN;
		}
	}

	cout << "·ÇÏàËÆ×Ö·û´®ÎóÅÐÂÊ:" << (double)errorN / N << endl;

}
void test3()
{
	srand(time(0));
	const size_t N = 10000;
	m::bloomFilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2¸úv1ÊÇÏàËÆ×Ö·û´®¼¯£¬µ«ÊÇ²»Ò»Ñù
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "ÏàËÆ×Ö·û´®ÎóÅÐÂÊ:" << (double)n2 / (double)N << endl;

	// ²»ÏàËÆ×Ö·û´®¼¯
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		//string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "²»ÏàËÆ×Ö·û´®ÎóÅÐÂÊ:" << (double)n3 / (double)N << endl;
}
void test4()
{
	m::bloomFilter<100> bs;
	bs.set("sort");
	bs.set("bloom");
	bs.set("hello world hello bit");
	bs.set("test");
	bs.set("etst");
	bs.set("estt");

	cout << bs.test("sort") << endl;
	cout << bs.test("bloom") << endl;
	cout << bs.test("hello world hello bit") << endl;
	cout << bs.test("etst") << endl;
	cout << bs.test("test") << endl;
	cout << bs.test("estt") << endl;

	cout << bs.test("ssort") << endl;
	cout << bs.test("tors") << endl;
	cout << bs.test("ttes") << endl;
}
int main()
{
	test4();
	//test3();
	//test2();
	/*string s = "aa";
	s + "ww";
	cout << s << endl;*/
	const static int a = 1;
	static const int b = 2;
	//test1();
	/*vector<int> v1;
	vector<char> v2;

	v1.resize(10);
	v2.resize(10);
	int a = 1;
	cout << (int)char() << endl;*/
	return 0;
}
#include<iostream>
using namespace std;
#include"AVLTree.h"

void test1()
{
	m::AVLTree<int, int> t;
	t.insert(make_pair(6, 6));
	t.insert(make_pair(1, 1));
	t.insert(make_pair(3, 3));
	t.insert(make_pair(7, 7));
	t.insert(make_pair(8, 8));
	t.insert(make_pair(0, 0));
	t.inOrder();
}

void test2()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	m::AVLTree<int, int> t;
	//t.insert(make_pair(a[0], a[0]));
	//t.insert(make_pair(a[1], a[1]));
	//t.insert(make_pair(a[2], a[2]));
	//t.insert(make_pair(a[3], a[3]));
	//t.insert(make_pair(a[4], a[4]));
	//t.insert(make_pair(a[5], a[5]));
	//t.insert(make_pair(a[6], a[6]));
	//t.insert(make_pair(a[7], a[7]));
	//t.insert(make_pair(a[8], a[8]));
	for (auto& e : a)
	{
		t.insert(make_pair(e, e));
	}
	t.inOrder();

	cout << t.isBalanceTree() << endl;

}
void test3()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	m::AVLTree<int, int> t;
	for (auto& e : a)
	{
		t.insert(make_pair(e, e));
	}
	t.inOrder();

	cout << t.isBalanceTree() << endl;
}

void test4()
{
	srand(time(0));
	const size_t N = 5000000;
	m::AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.insert(make_pair(x, x));
	}

	cout << t.isBalanceTree() << endl;
	cout << t.getHigh() << endl;
}

void test5()
{
	//time_t t = 0;
	//time_t ret = time(&t);
	//cout << "t:" << t << endl;
	//cout << "ret:" << ret << endl;

	srand(time(0));
	int k = 10;
	while (k--)
	{
		cout << rand() << endl;
	}
}
int main()
{
	/*test2();

	cout << endl << endl;

	test3();

	cout << endl << endl;
	test4();*/

	/*test1();
	cout << endl << endl;*/
	test2();
	cout << endl << endl;
	test3();
	cout << endl << endl;
	test4();

	return 0;
}
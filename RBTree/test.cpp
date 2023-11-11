#include<iostream>
#include"RBTree.h"

using namespace std;

void test1()
{
	RBTree<int, int> t;
	t.insert(make_pair(1, 1));
	t.insert(make_pair(3, 3));
	t.insert(make_pair(6, 6));
	t.insert(make_pair(7, 7));
	t.insert(make_pair(2, 2));
	t.insert(make_pair(0, 0));
	t.inOrder();
}

void test2()
{
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int arr[] = { 4,2,6,1,3,5,15,7,16,14 };
	RBTree<int, int> t;
	/*t.insert(make_pair(16, 16));
	t.insert(make_pair(3, 3));
	t.insert(make_pair(7, 7));
	t.insert(make_pair(11,11));
	t.insert(make_pair(9, 9));
	t.insert(make_pair(26, 26));
	t.insert(make_pair(18, 18));
	t.insert(make_pair(14, 14));*/


	for (auto& e : arr)
	{
		t.insert(make_pair(e, e));
	}
	t.inOrder();
	cout << t.isBalance() << endl;
}

void test3()
{
	srand(time(nullptr));
	const int N = 100000;
	RBTree<int, int> t;
	for (int i = 0; i < N; i++)
	{
		int toInsert = rand() + i;
		t.insert(make_pair(toInsert, toInsert));
	}
	//t.inOrder();
	cout << t.isBalance() << endl;
}

int main()
{

	test3();
	return 0;
}
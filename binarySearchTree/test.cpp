#include<iostream>
using namespace std;

#include"BinarySearchTree.h"

void test1()
{
	m::BSTree<int> t;
	t.insert(8);
	t.insert(3);
	t.insert(1);
	t.insert(10);
	t.insert(6);
	t.insert(4);
	t.insert(7);
	t.insert(14);
	t.insert(13);

	t.inOrder();
	//cout << t.find(6) << endl;
	//cout << t.find(11) << endl;

	/*t.erase(13);
	t.inOrder();*/

	/*t.erase(14);
	t.inOrder();*/

	/*t.erase(3);
	t.inOrder();*/

	/*t.erase(8);
	t.inOrder();*/

	//cout << t.findRecursion(8) << endl;
	//cout << t.findRecursion(3) << endl;
	//cout << t.findRecursion(14) << endl;
	//cout << t.findRecursion(13) << endl;
	//cout << t.findRecursion(16) << endl;


	//t.insertRecursion(0);
	//t.inOrder();

	//t.insertRecursion(16);
	//t.inOrder();

	//t.insertRecursion(9);
	//t.inOrder();

	/*t.eraseRecursion(13);
	t.inOrder();*/

	/*t.eraseRecursion(14);
	t.inOrder();*/

	/*t.eraseRecursion(3);
	t.inOrder();*/

	/*t.eraseRecursion(8);
	t.inOrder();*/

	m::BSTree<int> copy = t;
	copy.inOrder();
}
int main()
{
	test1();
	return 0;
}
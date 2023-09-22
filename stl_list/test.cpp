#include"list.h"
void test2()
{
	list<int> lt(10, 1);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int> lt2;
}
void test1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::iterator it = lt.begin();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << lt.front() << endl;
	cout << lt.back() << endl;
	lt.push_front(10);
	lt.push_front(20);
	lt.push_front(30);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(6);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(6);
	lt.push_back(8);
	lt.push_back(6);
	lt.push_back(9);
	//lt.remove(2);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.sort();
	lt.unique();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.reverse();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_tmp()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test4()
{
	myList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	myList::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	for (auto& e : lt)
	{
		e *= 2;
		cout << e << " ";
	}
	cout << endl;
	//myList::list<int>::
}

void test5()
{
	myList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	myList::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		(*it) *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	const myList::list<int> lt2 = lt;
	myList::list<int>::const_iterator it2 = lt2.begin();
	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test6()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	auto pos2=lt.insert(pos, 30);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.erase(pos2);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_front(10);
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test7()
{
	myList::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);

	const myList::list<int> lt2 = lt1;
	lt1.push_back(6);
	myList::list<int>::const_iterator it = lt2.begin();
	while (it != lt2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	////lt2.func1();
	//for (auto& e : lt2)
	//{
	//	cout << e << " ";
	//}
	cout <<"d";
}
void test8()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	const list<int> lt2 = lt;
	list<int>::const_iterator it = lt2.begin();
	while (it != lt2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test9()
{
	myList::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);

	myList::list<int>::iterator it = lt1.begin();
	while (it != lt1.end())
	{
		(*it) *= 2;
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	const myList::list<int> lt2 = lt1;
	myList::list<int>::const_iterator it2 = lt2.begin();
	while (it2 != lt2.end())
	{
		//(*it2) *= 2;
		cout << (*it2) << " ";
		it2++;
	}
	//list<int>::const_reverse_iterator
	cout << endl;
}
void test10()
{
	myList::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);
	lt.push_back(8);
	lt.push_back(9);
	lt.push_back(10);

	myList::list<int>::reverse_iterator it = lt.rbegin();
	while (it != lt.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	const myList::list<int> lt2 = lt;
	myList::list<int>::const_reverse_iterator it2 = lt2.rbegin();
	while (it2 != lt2.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
#include"vector.h"
void test11()
{
	myVector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back('v');
	myVector::vector<int>::reverse_iterator it = v.rbegin();
	while (it != v.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	const myVector::vector<int> v2 = v;
	myVector::vector<int>::const_reverse_iterator it2 = v2.rbegin();
	while (it2 != v2.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
int main()
{
	test11();
	//int* p = new int(10);
	//delete p;

	/*int a = 2;
	int b = (a++) * 2;
	cout << a;*/
	//test4();
	//test_tmp();
	///*test3();*/
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(8);
	//v.push_back(9);
	//auto it = v.begin();
	//auto it2 = it;
	//cout << *it << endl;
	//cout << *it2 << endl;

	//cout << endl;
	//auto it3 = it++;
	//auto it4 = ++it2;
	////cout << *it << endl;
	////cout << *it2 << endl;
	//cout << *it3 << endl;
	//cout << *it4 << endl;

	//cout << endl;
	//cout << *it << endl;
	//cout << *it2 << endl;

	return 0;
}
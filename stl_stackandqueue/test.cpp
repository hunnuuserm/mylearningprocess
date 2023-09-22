#include"Stack.h"
#include"Queue.h"
#include"PriorityQueue.h"
void test1()
{
	myStack::stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	myStack::stack<int,list<int>> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;

	myStack::stack<int> st2;
	st2.push(1);
	st2.push(2);
	st2.push(3);
	st2.push(4);
	st2.push(5);
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl;

}
void test2()
{
	//myStack::stack<int, vector<int>> st1;
	stack<int, vector<int>> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	/*while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;*/

	//myStack::stack<int,vector<int>> st2;
	stack<int, vector<int>> st2;
	st2.push(11);
	st2.push(22);
	st2.push(33);
	st2.push(44);
	st2.push(55);
	//while (!st2.empty())
	//{
	//	cout << st2.top() << " ";
	//	st2.pop();
	//}
	//cout << endl;


	st1.swap(st2);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl;
}
void test3()
{
	myQueue::queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	/*while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;*/

	myQueue::queue<int> q1;
	q1.push(11);
	q1.push(22);
	q1.push(33);
	q1.push(44);
	q1.push(55);
	/*while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;*/
	myQueue::queue<int, list<int>> q2;
	q2.push(11);
	q2.push(22);
	q2.push(33);
	q2.push(44);
	q2.push(55);

	q.swap(q2);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	while (!q2.empty())
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
}
void test4()
{
	int a[] = { 4,6,1,3,9,9,6,7,1,5,100 };
	priority_queue<int,vector<int>,std::greater<int>> pq1(a, a + sizeof(a) / sizeof(a[0]));
	while (!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	myPriorityQueue::priority_queue<int,vector<int>,std::greater<int>> pq;
	pq.push(4);
	pq.push(6);
	pq.push(1);
	pq.push(3);
	pq.push(9);
	pq.push(9);
	pq.push(6);
	pq.push(7);
	pq.push(1);
	pq.push(5);
	pq.push(100);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}
int main()
{
	test4();
	/*vector<int> v;
	cout << sizeof(v) << endl;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
	cout << sizeof(vector<int>) << endl;
	cout << sizeof(vector<char>) << endl;*/
	//test3();
	//test2();
	//stack<int> st;
	//st.push(1);
	//st.push(2);
	//st.push(3);
	//st.push(4);
	//st.push(5);
	//while (!st.empty())
	//{
	//	cout << st.top() << " ";
	//	st.pop();
	//}
	//cout << endl;

	//queue<int> q;
	//q.push(1);
	//q.push(2);
	//q.push(3);
	//q.push(4);
	//q.push(5);
	//while (!q.empty())
	//{
	//	cout << q.front() << " ";
	//	q.pop();
	//}
	//cout << endl;
	return 0;
}
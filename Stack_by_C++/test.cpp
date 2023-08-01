#include"Stack.h"


int main()
{
	Stack<int> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	while (!st1.isEmpty())
	{
		cout << st1.Top() << " ";
		st1.Pop();
	}

	cout << endl;
	Stack<char> st2;
	st2.Push('a');
	st2.Push('b');
	st2.Push('c');
	st2.Push('d');
	st2.Push('e');
	while (!st2.isEmpty())
	{
		cout << st2.Top() << " ";
		st2.Pop();
	}
	return 0;
}
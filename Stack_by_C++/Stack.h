#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack(size_t capacity=4)
		:_a(nullptr)
		, _size(0)
		,_capacity(0)
	{
		if (capacity > 0)
		{
			_capacity = capacity;
			_a = new T[_capacity];
		}
	}
	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_size = 0;
		_capacity = 0;
	}
	void Push(const T& x)
	{
		if (_size == _capacity)
		{
			int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			T* tmp = new T[newCapacity];
			if (_a)
			{
				memcpy(tmp, _a, sizeof(T) * _capacity);
				delete[] _a;
			}
			_a = tmp;
			_capacity = newCapacity;
		}
		_a[_size++] = x;
	}
	void Pop()
	{
		assert(!isEmpty());
		_size--;
	}
	const T& Top()
	{
		assert(_size>0);
		return _a[_size-1];
	}
	bool isEmpty()
	{
		 return _size == 0;
	}
private:
	T* _a;
	size_t _size;
	size_t _capacity;
};
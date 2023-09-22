#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
using namespace std;

namespace myStack
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		const T& top()const
		{
			return _con.back();
		}
		bool empty()const
		{
			return _con.empty();
		}
		size_t size()const
		{
			return _con.size();
		}
		void swap(stack& x)
		{
			Container tmp(x._con);
			x._con = _con;
			_con = tmp;
		}
	private:
		Container _con;
	};
}

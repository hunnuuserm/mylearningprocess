#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

namespace myQueue
{
	template<class T,class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		const T& front()const
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back()const
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
		void swap(queue& x)
		{
			Container tmp(x._con);
			x._con = _con;
			_con = tmp;
		}
	private:
		Container _con;
	};
}
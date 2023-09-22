#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace myPriorityQueue
{
	template<class T,class Container=vector<int>,class Compare=std::less<int>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child>0&&com(_con[parent], _con[child]))//也可以把com(_con[parent], _con[child])放在while循环里面，用if else语句来判断
			{
				std::swap(_con[parent], _con[child]);
				child = parent;
				parent= (child - 1) / 2;
			}
		}
		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))//判断是否有右孩子&&判断左孩子的优先级是否小于右孩子
				{
					child++;
				}//这一个if语句找出优先级最高的孩子

				if (com(_con[parent], _con[child]))//优先级最高的孩子与父（母）结点比较优先级
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		const T& top()const
		{
			return _con[0];
		}
		bool empty()const
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}
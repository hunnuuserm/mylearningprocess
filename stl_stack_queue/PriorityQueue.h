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
			while (child>0&&com(_con[parent], _con[child]))//Ҳ���԰�com(_con[parent], _con[child])����whileѭ�����棬��if else������ж�
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
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))//�ж��Ƿ����Һ���&&�ж����ӵ����ȼ��Ƿ�С���Һ���
				{
					child++;
				}//��һ��if����ҳ����ȼ���ߵĺ���

				if (com(_con[parent], _con[child]))//���ȼ���ߵĺ����븸��ĸ�����Ƚ����ȼ�
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
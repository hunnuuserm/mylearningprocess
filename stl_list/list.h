#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<assert.h>
#include<algorithm>
#include"reverse_iterator.h"
using namespace std;

namespace myList
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& val = T())
			:_data(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> iterator;
		typedef list_node<T> Node;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		bool operator!=(const iterator& x)const
		{
			return _node != x._node;
		}
		bool operator==(const iterator& x)const
		{
			return _node == x._node;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			this->operator++();
			return tmp;
		}
		iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			this->operator--();
			return tmp;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		typedef __reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef __reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}


		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		void swap(list<T>& x)
		{
			std::swap(_head, x._head);
		}
		void emptyInit()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list()
		{
			/*_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;*/
			emptyInit();
		}
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			emptyInit();
			InputIterator cur = first;
			while (cur != last)
			{
				push_back(*cur);
				cur++;
			}
		}
		list(const list<T>& x)
		{
			emptyInit();
			list<T> tmp(x.begin(), x.end());
			swap(tmp);//this->swap(x);
		}
		list<T>& operator=(list<T> x)
		{
			swap(x);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		/*void func1()const
		{}
		void func2()
		{}*/
		void clear()
		{
			iterator cur = begin();
			while (cur != end())
			{
				cur=erase(cur);
			}
		}
		void push_back(const T& val)
		{
			Node* newnode = new Node(val);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator insert(iterator& pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator& pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			return iterator(next);
		}
	private:
		Node* _head;
	};

}
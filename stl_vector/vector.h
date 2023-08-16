#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;

namespace myVector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const iterator begin()const
		{
			return _start;
		}
		const iterator end()const
		{
			return _finish;
		}
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}
		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			reserve(v.capacity());
			const_iterator it = v.begin();
			iterator pos = begin();
			while (it != v.end())
			{
				*pos = *it;
				pos++;
				it++;
			}
			_finish = pos;
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			InputIterator it = first;
			iterator pos = _start;
			while (it != last)
			{
				*pos++ = *it++;
			}
			_finish = pos;
		}
		vector(size_t n, const T& val = T())
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage,v._end_of_storage);
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		bool empty()const
		{
			return _finish == nullptr;
		}
		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				//扩容
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = val;
			_finish++;
		}
		void pop_back()
		{
			assert(_finish > _start);
			_finish--;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				iterator tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];//如果是自定义类型，回去调用operator=
					}
				}
				delete[] _start;
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				for (size_t i = size(); i < n; i++)
				{
					_start[i] = val;
				}
				_finish = _start + n;
			}
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}
		T& front()
		{
			assert(!empty());
			return _start[0];
		}
		const T& front()const
		{
			assert(!empty());
			return _start[0];
		}
		T& back()
		{
			assert(!empty());
			return _start[size() - 1];
		}
		const T& back()const
		{
			assert(!empty());
			return _start[size() - 1];
		}
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			size_t p_count = pos - _start;
			if (size() == capacity())
			{
				//空间不足扩容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			pos = _start + p_count;
			iterator end = _finish-1;
			while (end != pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*(pos + 1) = *pos;
			*pos = val;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(!empty());
			assert(pos >= _start);
			assert(pos < _finish);
			iterator p = pos;
			while (p != _finish - 1)
			{
				*p = *(p + 1);
				p++;
			}
			_finish--;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
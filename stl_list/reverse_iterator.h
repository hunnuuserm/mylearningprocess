#pragma once
namespace myList
{
	template<class Iterator,class Ref,class Ptr>
	class __reverse_iterator
	{
	public:
		typedef __reverse_iterator<Iterator, Ref, Ptr> RIterator;
		__reverse_iterator(const Iterator& x)
			:_cur(x)
		{}
		Ref operator*()
		{
			auto tmp = _cur;
			--tmp;
			return *tmp;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		RIterator operator++()
		{
			--_cur;
			return *this;
		}
		RIterator operator--()
		{
			++_cur;
			return *this;
		}
		RIterator operator++(int)
		{
			auto tmp = *this;
			--_cur;
			return tmp;
		}
		RIterator operator--(int)
		{
			auto tmp = *this;
			++_cur;
			return tmp;
		}
		bool operator!=(const RIterator& it)
		{
			return _cur != it._cur;
		}
	private:
		Iterator _cur;
	};
}
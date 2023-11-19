#pragma once
#include"RBTree.h"

namespace m
{
	template<class K>
	class set
	{
		typedef K key_type;
		typedef K value_type;
		struct keyOfValue
		{
			key_type operator()(const value_type& v)
			{
				return v;
			}
		};

	public:
		typedef typename RBTree<key_type, value_type, keyOfValue>::const_iterator iterator;
		typedef typename RBTree<key_type, value_type, keyOfValue>::const_iterator const_iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		const_iterator begin()const
		{
			return _t.begin();
		}
		const_iterator end()const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const value_type& v)
		{
			return _t.insert(v);
		}
	private:
		RBTree<key_type, value_type, keyOfValue> _t;
	};
}
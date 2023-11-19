#pragma once
#include<utility>
#include"RBTree.h"

namespace m
{
	template<class K,class V>
	class map
	{
		typedef K key_type;
		typedef pair<const K, V> value_type;

		struct keyOfValue
		{
			key_type operator()(const value_type& v)
			{
				return v.first;
			}
		};

	public:
		typedef typename RBTree<key_type, value_type, keyOfValue>::iterator iterator;
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

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.insert(make_pair(key,V()));
			return ret.first->second;
		}
		
	private:
		RBTree<key_type, value_type, keyOfValue> _t;
	};
}
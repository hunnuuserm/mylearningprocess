#pragma once
#include"hashTable(hashBucket).h"

namespace m
{
	template<class key,class hash = hashFunc<key>>
	class unordered_set
	{
		typedef key key_type;
		typedef key value_type;

		struct keyOfValue
		{
			key_type operator()(const value_type& value)
			{
				return value;
			}
		};

	public:

		typedef typename hashTable<key_type, value_type, keyOfValue, hash>::const_iterator iterator;
		typedef typename hashTable<key_type, value_type, keyOfValue, hash>::const_iterator const_iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		const_iterator begin()const
		{
			return _ht.begin();
		}
		const_iterator end()const
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const value_type& value)
		{
			return _ht.insert(value);
		}

		bool erase(const key_type& key)
		{
			return _ht.erase(key);
		}
	private:
		hashTable<key_type, value_type, keyOfValue, hash> _ht;
	};
}
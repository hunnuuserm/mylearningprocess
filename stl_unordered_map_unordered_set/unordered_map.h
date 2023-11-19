#pragma once
#include"hashTable(hashBucket).h"


namespace m
{
	template<class key, class value, class hash = hashFunc<key>>
	class unordered_map
	{
		typedef key key_type;
		typedef pair<const key, value> value_type;//注意:这里的key前面加const是因为unordered_map的key是不允许修改的;
		struct keyOfValue
		{
			const key_type operator()(const value_type& value)
			{
				return value.first;
			}
		};
	public:
		typedef typename hashTable<key_type, value_type, keyOfValue, hash>::iterator iterator;
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
		value& operator[](const key_type& key)
		{
			auto ret = insert(make_pair(key, value()));
			return ret.first->second;
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
#pragma once

#include<string>
#include<vector>
#include<utility>
using namespace std;


//namespace hashBucket
//{
	template<class value>
	struct hashNode
	{
		value _value;
		hashNode<value>* _next;

		hashNode(const value& v)
			:_value(v)
			, _next(nullptr)
		{}
	};

	template<class K>
	struct hashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	template<>
	struct hashFunc<string>
	{
		// BKDR
		size_t operator()(const string& s)
		{
			size_t sum = 0;
			for (auto& e : s)
			{
				sum += e;
				sum *= 31;
			}
			return sum;
		}
	};

	//为struct __hashTableIterator前置声明class hashTable
	template<class key, class value, class keyOfValue, class hash>
	class hashTable;

	template<class key, class value, class ref, class ptr, class keyOfValue, class hash>
	struct __hashTableIterator
	{
		typedef hashTable<key, value, keyOfValue, hash> hashTable;
		typedef hashNode<value> node;
		typedef __hashTableIterator<key, value, ref, ptr, keyOfValue, hash> self;
		typedef __hashTableIterator<key, value, value&, value*, keyOfValue, hash> iterator;

		node* _node;
		const hashTable* _ht;

		 __hashTableIterator(node* node, const hashTable* ht)
			:_node(node)
			, _ht(ht)
		{}
		__hashTableIterator(const iterator& it)
			:_node(it._node)
			, _ht(it._ht)
		{}

		self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				keyOfValue kov;
				hash Hash;
				size_t hashi = Hash(kov(_node->_value)) % _ht->_table.size();
				++hashi;
				while (hashi < _ht->_table.size() && _ht->_table[hashi] == nullptr)
				{
					hashi++;
				}
				if (hashi == _ht->_table.size())
				{
					_node = nullptr;
				}
				else
				{
					_node = _ht->_table[hashi];
				}
			}
			return *this;
		}
		ref operator*()
		{
			return _node->_value;
		}
		ptr operator->()
		{
			return &_node->_value;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

	};

	template<class key, class value, class keyOfValue, class hash>
	class hashTable
	{
		template<class key, class value, class ref, class ptr, class keyOfValue, class hash>
		friend struct __hashTableIterator;


	public:
		typedef __hashTableIterator<key, value, value&, value*, keyOfValue, hash> iterator;
		typedef __hashTableIterator<key, value, const value&, const value*, keyOfValue, hash> const_iterator;

		iterator begin()
		{
			size_t hashi = 0;
			while (hashi < _table.size() && _table[hashi] == nullptr)
			{
				hashi++;
			}
			if (hashi == _table.size())
			{
				return iterator(nullptr, this);
			}
			else
			{
				return iterator(_table[hashi], this);
			}
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}
		const_iterator begin()const
		{
			size_t hashi = 0;
			while (hashi < _table.size() && _table[hashi] == nullptr)
			{
				hashi++;
			}
			if (hashi == _table.size())
			{
				return const_iterator(nullptr, this);
			}
			else
			{
				return const_iterator(_table[hashi], this);
			}
		}
		const_iterator end()const
		{
			return const_iterator(nullptr, this);
		}

		~hashTable()
		{
			for (auto& e : _table)
			{
				while (e)
				{
					hashNode<value>* next = e->_next;
					delete e;
					e = next;
				}
			}
			//_table.~vector();
			_n = 0;
		}
		pair<iterator,bool> insert(const value& v)
		{
			keyOfValue kov;
			hash Hash;
			//先复用find查看待插入的元素是否存在
			iterator ret = find(kov(v));
			if (ret._node)
			{
				return make_pair(ret, false);
			}
			//判断是否扩容
			if (_table.size() == 0 || _n / _table.size() == 1)
			{
				//扩容
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<hashNode<value>*> newTable;
				newTable.resize(newsize, nullptr);
				//方法一：直接把_table的节点挂到newTable._table（方法一比方法二高效）
				for (auto& cur : _table)
				{
					while (cur)
					{
						hashNode<value>* next = cur->_next;
						size_t hashi = Hash(kov(cur->_value)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
				}
				_table.swap(newTable);
				//方法二：根据_table的节点创建新节点挂到newTable._table
				/*newTable._table.resize(newsize, nullptr);
				for (auto& e : _table)
				{
					while (e)
					{
						newTable.insert(e->_kv);
						e = e->_next;
					}
				}
				_table.swap(newTable._table);*/
				//_n = newTable._n;//这行代码写不写都可以;
			}

			//插入新的数据，这里采用尾插，即向哈系桶的尾部插入节点;
			size_t hashi = Hash(kov(v)) % _table.size();
			hashNode<value>* cur = _table[hashi];
			hashNode<value>* parent = nullptr;
			while (cur)
			{
				parent = cur;
				cur = cur->_next;
			}
			cur = new hashNode<value>(v);
			if (parent)
			{
				parent->_next = cur;
			}
			else
			{
				_table[hashi] = cur;
			}
			_n++;
			return make_pair(iterator(cur, this), true);
		}
		iterator find(const key& key)
		{
			keyOfValue kov;
			hash Hash;
			if (_table.size() == 0)
			{
				return iterator(nullptr, this);
			}

			size_t hashi = Hash(key) % _table.size();
			hashNode<value>* cur = _table[hashi];
			while (cur && kov(cur->_value) != key)
			{
				cur = cur->_next;
			}

			if (cur)
			{
				return iterator(cur, this);
			}
			else
			{
				return iterator(nullptr, this);
			}
		}
		bool erase(const key& k)
		{
			keyOfValue kov;
			hash Hash;
			if (_table.size() == 0)
			{
				return false;
			}

			size_t hashi = Hash(k) % _table.size();
			hashNode<value>* cur = _table[hashi];
			hashNode<value>* parent = nullptr;
			while (cur && kov(cur->_value) != k)
			{
				parent = cur;
				cur = cur->_next;
			}

			hashNode<value>* next = cur->_next;
			if (parent)
			{
				parent->_next = next;
			}
			else
			{
				_table[hashi] = next;
			}
			delete cur;
			cur = nullptr;
			_n--;
			return true;
		}
	private:
		vector<hashNode<value>*> _table;
		size_t _n = 0;//记录存储的数据个数
	};
//}
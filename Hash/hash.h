#pragma once
#include<vector>
using namespace std;


namespace openAddress
{
	enum state
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct hashDate
	{
		pair<K, V> _kv;
		state _state = EMPTY;
		hashDate()
			:_state(EMPTY)
		{}
		hashDate(const pair<K, V>& kv)
			:_kv(kv)
			, _state(EXIST)
		{}

	};

	template<class K, class V>
	class hashTable
	{
	public:
		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}
			//先判断是否扩容
			if (_table.size() == 0 || _n * 10 / _table.size() >= 7)
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				hashTable<K, V> newTable;
				newTable._table.resize(newsize);
				for (auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newTable.insert(e._kv);
					}
				}
				_table.swap(newTable._table);
				_n = newTable._n;//这样也可以不加,因为到这一行代码_n与newTable._n肯定是相等的;
			}
			//进行插入(这里解决哈希冲突用线性探测)
			size_t hashi = kv.first % _table.size();
			size_t index = hashi;
			size_t i = 0;
			while (_table[index]._state == EXIST)
			{
				i++;
				index = (hashi + i) % _table.size();
			}
			_table[index] = kv;
			_n++;
			return true;//这个return true容易忘;
		}

		bool erase(const K& key)
		{
			//写法一:可以复用find
		/*	hashDate<K, V>* ret = find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_n--;
				return true;
			}
			else
			{
				return nullptr;
			}*/
			//写法二:还可以一步步写出来
			size_t hashi = key % _table.size();
			size_t index = hashi;
			while (_table[hashi] != EMPTY)
			{
				if (_table[hashi]._state != DELETE && _table[hashi]._kv.first == key)
				{
					_table[hashi]._state = DELETE;
					_n--;
					return true;
				}
				hashi++;
				hashi %= _table.size();
				if (hashi == index)//查找一圈没找到，直接break返回nullptr;
				{
					break;
				}
			}
			return false;
		}

		hashDate<K, V>* find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}
			size_t hashi = key % _table.size();
			size_t index = hashi;
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state != DELETE && _table[hashi]._kv.first == key)
				{
					return &_table[hashi];
				}
				hashi++;
				hashi %= _table.size();

				if (hashi == index)//查找一圈没找到，直接break返回nullptr;
				{
					break;
				}
			}
			return nullptr;
		}
	private:
		vector<hashDate<K, V>> _table;
		size_t _n = 0;//存储的数据个数
	};
}

namespace hashBucket
{
	template<class K, class V>
	struct hashNode
	{
		pair<K, V> _kv;
		hashNode<K,V>* _next;

		hashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
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

	template<class K, class V, class Hash = hashFunc<K>>
	class hashTable
	{
	public:
		~hashTable()
		{
			for (auto& e : _table)
			{
				while (e)
				{
					hashNode<K, V>* next = e->_next;
					delete e;
					e = next;
				}
			}
			//_table.~vector();
			_n = 0;
		}
		bool insert(const pair<K, V>& kv)
		{
			Hash hash;
			//先复用find查看待插入的元素是否存在
			if (find(kv.first))
			{
				return false;
			}
			//判断是否扩容
			if (_table.size() == 0 || _n / _table.size() == 1)
			{
				//扩容
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<hashNode<K,V>*> newTable;
				newTable.resize(newsize, nullptr);
				//方法一：直接把_table的节点挂到newTable._table（方法一比方法二高效）
				for (auto& cur : _table)
				{
					while (cur)
					{
						hashNode<K, V>* next = cur->_next;
						size_t hashi = hash(cur->_kv.first) % newTable.size();
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
			size_t hashi = hash(kv.first) % _table.size();
			hashNode<K, V>* cur = _table[hashi];
			hashNode<K, V>* parent = nullptr;
			while (cur)
			{
				parent = cur;
				cur = cur->_next;
			}
			cur = new hashNode<K,V>(kv);
			if (parent)
			{
				parent->_next = cur;
			}
			else
			{
				_table[hashi] = cur;
			}
			_n++;
			return true;
		}
		hashNode<K, V>* find(const K& key)
		{
			Hash hash;
			if (_table.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = hash(key) % _table.size();
			hashNode<K, V>* cur = _table[hashi];
			while (cur && cur->_kv.first != key)
			{
				cur = cur->_next;
			}

			if (cur)
			{
				return cur;
			}
			else
			{
				return nullptr;
			}
		}
		bool erase(const K& key)
		{
			Hash hash;
			if (_table.size() == 0)
			{
				return false;
			}

			size_t hashi = hash(key) % _table.size();
			hashNode<K, V>* cur = _table[hashi];
			hashNode<K, V>* parent = nullptr;
			while (cur && cur->_kv.first != key)
			{
				parent = cur;
				cur = cur->_next;
			}

			hashNode<K, V>* next = cur->_next;
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
		vector<hashNode<K, V>*> _table;
		size_t _n = 0;//记录存储的数据个数
	};
}
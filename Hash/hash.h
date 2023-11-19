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
			//���ж��Ƿ�����
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
				_n = newTable._n;//����Ҳ���Բ���,��Ϊ����һ�д���_n��newTable._n�϶�����ȵ�;
			}
			//���в���(��������ϣ��ͻ������̽��)
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
			return true;//���return true������;
		}

		bool erase(const K& key)
		{
			//д��һ:���Ը���find
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
			//д����:������һ����д����
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
				if (hashi == index)//����һȦû�ҵ���ֱ��break����nullptr;
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

				if (hashi == index)//����һȦû�ҵ���ֱ��break����nullptr;
				{
					break;
				}
			}
			return nullptr;
		}
	private:
		vector<hashDate<K, V>> _table;
		size_t _n = 0;//�洢�����ݸ���
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
			//�ȸ���find�鿴�������Ԫ���Ƿ����
			if (find(kv.first))
			{
				return false;
			}
			//�ж��Ƿ�����
			if (_table.size() == 0 || _n / _table.size() == 1)
			{
				//����
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<hashNode<K,V>*> newTable;
				newTable.resize(newsize, nullptr);
				//����һ��ֱ�Ӱ�_table�Ľڵ�ҵ�newTable._table������һ�ȷ�������Ч��
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
				//������������_table�Ľڵ㴴���½ڵ�ҵ�newTable._table
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
				//_n = newTable._n;//���д���д��д������;
			}

			//�����µ����ݣ��������β�壬�����ϵͰ��β������ڵ�;
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
		size_t _n = 0;//��¼�洢�����ݸ���
	};
}
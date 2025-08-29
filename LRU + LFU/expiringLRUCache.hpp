//注意点：
//1.第一次写的时候，把第27行忘了，注意Get的时候，在把节点移到_list最前面时，也要把之前的节点在_list中删掉；
//2.第131,133行，windows上的Sleep函数参数是毫秒。

#include <iostream>
#include <list>
#include <unordered_map>
#include <ctime>
#include <windows.h>

template<class K, class V>
class ExpiringLRUCache
{
public:
	ExpiringLRUCache(int capacity = 3, time_t ttl = 5)
		:_capacity(capacity),
		_ttl(ttl)
	{}
    //这里可以使用std::optional<V>，但VS2022暂时不支持C++17，所以用-1代替找不到的情况
	V Get(const K& key)
	{
		time_t now = std::time(nullptr);
		auto it = _table.find(key);
		if (it == _table.end())
			return -1;

		if (it->second->second._endTime < now)
		{
			remove(key);
			return -1;
		}

		Node node = it->second->second;
		_list.erase(it->second);
		_list.push_front({key,node});
		_table[key] = _list.begin();
		return node._val;
	}
	void Put(const K& key, const V& value)
	{	
		time_t now = std::time(nullptr);
		if (_table.find(key) != _table.end())
		{
			remove(key);
		}
		else if (_table.size() == _capacity)
		{
			removeExpiring();
			if (_table.size() == _capacity)
			{
				remove(_list.back().first);
			}
		}

		_list.push_front({ key,{value, now + _ttl} });
		_table[key] = _list.begin();
	}
private:
	void remove(const K& key)
	{
		auto it = _table.find(key);
		_list.erase(it->second);
		_table.erase(it);
	}
	void removeExpiring()
	{
		auto now = std::time(nullptr);
		auto it = _list.rbegin();
		while (it != _list.rend())
		{
			if (it->second._endTime < now)
			{
				K key = it->first;
				/*_list.erase(it);
				_table.erase(key);*/
				remove(key);
				return;
			}
			++it;
		}
	}
private:
	struct Node
	{
		Node(V val, time_t endTime)
			:_val(val),
			_endTime(endTime)
		{}
		V _val;
		time_t _endTime;
	};
private:
	int _capacity;
	time_t _ttl;
	list<pair<K, Node>> _list;
	unordered_map<K, typename list<pair<K, Node>>::iterator> _table;
};

int main()
{
	ExpiringLRUCache<int, int> elru;
	elru.Put(1, 1);
	elru.Put(2, 3);
	elru.Put(3, 3);
	elru.Put(4, 4);
	elru.Put(5, 5);

	if (elru.Get(1) == -1)
	{
		cout << "1 expiring" << endl;
	}

	if (elru.Get(2) == -1)
	{
		cout << "2 expiring" << endl;
	}

	if (elru.Get(3) != -1)
	{
		cout << "get 3 succeed" << endl;
	}
	if (elru.Get(4) != -1)
	{
		cout << "get 4 succeed" << endl;
	}
	if (elru.Get(5) != -1)
	{
		cout << "get 5 succeed" << endl;
	}

	Sleep(2000);
	elru.Put(6,6);
	Sleep(4000);
	if (elru.Get(5) == -1)
	{
		cout << "5 expiring" << endl;
	}
	if (elru.Get(6) != -1)
	{
		cout << "get 6 succeed" << endl;
	}
    return 0;
}
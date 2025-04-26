#include <list>
#include <unordered_map>

using namespace std;

// LRU注意点:
// 1.put的时候，要检查是否存在，存在就把_list和_hash中已存在的删掉(_list一定要删，_hash可以不删，后面直接_hash[key]更新迭代器也行)
//   如果不删除_list中已存在的数据，_list中就会存在两份{key, vlaue1}、{key, value2}了，当然value1和value2可能相等可能不相等;
// 2.put的时候记的检查个数是否达到上线了，即_list.size()是否等于_capacity;
// 3.不论是put还是get，_list和_hash都要一起更新，不要只更新其中一个。
class LRUCache
{
public:
	LRUCache(int capacity)
		: _capacity(capacity)
	{
	}

	int get(int key)
	{
		auto it = _hash.find(key);
		if (it == _hash.end())
			return -1;

		int value = it->second->second;
		_list.erase(it->second);
		_list.push_front({key, value});
		_hash[key] = _list.begin();
		return value;
	}

	void put(int key, int value)
	{
		auto it = _hash.find(key);
		if (it != _hash.end())
		{
			_list.erase(it->second);
			_hash.erase(it);
		}
		else if (_list.size() == _capacity)
		{
			int k = _list.back().first;
			_list.pop_back();
			_hash.erase(k);
		}

		_list.push_front({key, value});
		_hash[key] = _list.begin();
	}

private:
	list<pair<int, int>> _list;
	unordered_map<int, list<pair<int, int>>::iterator> _hash;
	int _capacity;
};

class LFUCache
{
private:
	int capacity;
	int minFreq;
	unordered_map<int, int> cache;			// 存储键值对
	unordered_map<int, int> freq;			// 存储键的访问频率
	unordered_map<int, list<int>> freqList; // 存储频率和访问该频率的键的双向链表

public:
	LFUCache(int capacity)
	{
		this->capacity = capacity;
		this->minFreq = 0;
	}

	int get(int key)
	{
		if (cache.find(key) == cache.end())
		{
			return -1; // 缓存中没有该键
		}

		// 增加访问频率
		int currentFreq = freq[key];
		freq[key] = currentFreq + 1;

		// 将键从当前频率链表移除
		freqList[currentFreq].remove(key);
		if (freqList[currentFreq].empty() && currentFreq == minFreq)
		{
			minFreq++;
		}

		// 将键插入到新的频率链表
		freqList[currentFreq + 1].push_back(key);

		return cache[key];
	}

	void put(int key, int value)
	{
		if (capacity == 0)
			return;

		if (cache.find(key) != cache.end())
		{
			cache[key] = value;
			get(key); // 更新频率
			return;
		}

		if (cache.size() >= capacity)
		{
			// 淘汰最不常用的项
			int leastFreqKey = freqList[minFreq].front();
			freqList[minFreq].pop_front();
			cache.erase(leastFreqKey);
			freq.erase(leastFreqKey);
		}

		// 插入新的键值对
		cache[key] = value;
		freq[key] = 1;
		freqList[1].push_back(key);
		minFreq = 1; // 频率最小从1开始
	}
};
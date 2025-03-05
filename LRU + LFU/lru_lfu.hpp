#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}
	int get(int key) {
			auto hashit = _hashmap.find(key);
		if (hashit != _hashmap.end())
		{
			auto listit = hashit->second;
			pair<int, int> kv = *listit;

			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
			return kv.second;
		}
		else
		{
			return -1;
		}
	}
	void put(int key, int value) {
		// 1.如果没有数据则进行插入数据
		// 2.如果有数据则进行数据更新
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			//比特就业课
				// 插入数据时，如果数据已经达到上限，则删除链表头的数据和hashmap中的数据，两个
				//删除操作都是O(1)
				if (_list.size() >= _capacity)
				{
					_hashmap.erase(_list.back().first);
					_list.pop_back();
				}

			_list.push_front(make_pair(key, value));
			_hashmap[key] = _list.begin();
		}
		else
		{
			// 再次put，将数据挪动list前面
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			kv.second = value;

			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
	}
private:
	list<pair<int, int>> _list;
	size_t _capacity;
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
};

class LFUCache {
private:
	int capacity;
	int minFreq;
	unordered_map<int, int> cache; // 存储键值对
	unordered_map<int, int> freq;  // 存储键的访问频率
	unordered_map<int, list<int>> freqList; // 存储频率和访问该频率的键的双向链表

public:
	LFUCache(int capacity) {
		this->capacity = capacity;
		this->minFreq = 0;
	}

	int get(int key) {
		if (cache.find(key) == cache.end()) {
			return -1; // 缓存中没有该键
		}

		// 增加访问频率
		int currentFreq = freq[key];
		freq[key] = currentFreq + 1;

		// 将键从当前频率链表移除
		freqList[currentFreq].remove(key);
		if (freqList[currentFreq].empty() && currentFreq == minFreq) {
			minFreq++;
		}

		// 将键插入到新的频率链表
		freqList[currentFreq + 1].push_back(key);

		return cache[key];
	}

	void put(int key, int value) {
		if (capacity == 0) return;

		if (cache.find(key) != cache.end()) {
			cache[key] = value;
			get(key);  // 更新频率
			return;
		}

		if (cache.size() >= capacity) {
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
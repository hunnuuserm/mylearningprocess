#include <unordered_map>
#include <list>
#include <ctime>
#include <iostream>
#include <optional>

template<typename K, typename V>
class ExpiringLRUCache {
public:
    ExpiringLRUCache(size_t capacity, time_t ttl) : capacity_(capacity), ttl_(ttl) {}

    void put(const K& key, const V& value) {
        auto now = std::time(nullptr);

        // 如果键已经存在，更新值和时间戳并将其移动到头部
        if (map_.find(key) != map_.end()) {
            lruList_.erase(map_[key].lruIt); // 修正：使用 lruIt
        } else if (map_.size() >= capacity_) {
            // 缓存已满，检查是否有过期的KV
            removeExpiredKV();
            // 如果依然满了，按照LRU策略删除最久未使用的KV
            if (map_.size() >= capacity_) {
                auto last = lruList_.back();
                map_.erase(last);
                lruList_.pop_back();
            }
        }

        lruList_.push_front(key);
        map_[key] = {value, lruList_.begin(), now + ttl_};
    }

    std::optional<V> get(const K& key) {
        auto now = std::time(nullptr);

        // 查找键是否存在
        auto it = map_.find(key);
        if (it == map_.end()) return std::nullopt;

        // 检查键是否过期
        if (now > it->second.expiry) {
            remove(key);
            return std::nullopt;
        }

        // 更新LRU
        lruList_.erase(it->second.lruIt); // 修正：使用 lruIt
        lruList_.push_front(key);
        it->second.lruIt = lruList_.begin();

        return it->second.value;
    }

    void remove(const K& key) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            lruList_.erase(it->second.lruIt); // 修正：使用 lruIt
            map_.erase(it);
        }
    }

private:
    struct CacheNode {
        V value;
        typename std::list<K>::iterator lruIt;
        time_t expiry;
    };

    void removeExpiredKV() {
        auto now = std::time(nullptr);
        for (auto it = lruList_.rbegin(); it != lruList_.rend(); ++it) {
            auto mapIt = map_.find(*it);
            if (mapIt != map_.end() && now > mapIt->second.expiry) {
                remove(*it);
                return;
            }
        }
    }

    size_t capacity_;
    time_t ttl_;
    std::unordered_map<K, CacheNode> map_;
    std::list<K> lruList_;
};

int main() {
    ExpiringLRUCache<int, std::string> cache(3, 5);  // 容量为3, 过期时间为5秒

    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");

    std::this_thread::sleep_for(std::chrono::seconds(6));  // 等待6秒，确保第一个元素过期

    cache.put(4, "four");  // 插入新元素，检查过期机制

    if (auto result = cache.get(1)) {
        std::cout << "Key 1: " << *result << std::endl;
    } else {
        std::cout << "Key 1 expired or not found" << std::endl;
    }

    if (auto result = cache.get(2)) {
        std::cout << "Key 2: " << *result << std::endl;
    } else {
        std::cout << "Key 2 expired or not found" << std::endl;
    }

    return 0;
}

class LRUCache {
//通过MAP存储链表的迭代器实现快速查找
//查找、删除都是O1操作
private:
    int capacity;
    list<pair<int, int>> cache_list;  // 存储 (key, value) 对
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;  // key -> 迭代器
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            // 找到了，O(1) 获取 list 迭代器
            auto list_it = it->second;
            int value = list_it->second;
            
            // O(1) 移动到链表头部（最近使用）
            cache_list.erase(list_it);           // O(1) 删除
            cache_list.push_front({key, value}); // O(1) 插入到头部
            cache_map[key] = cache_list.begin(); // 更新迭代器
            
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            // 键已存在，更新值并移到头部
            auto list_it = it->second;
            cache_list.erase(list_it);           // O(1) 删除
            cache_list.push_front({key, value}); // O(1) 插入到头部
            cache_map[key] = cache_list.begin(); // 更新迭代器
        } else {
            // 新键
            if (cache_list.size() >= capacity) {
                // 移除最久未使用的元素（链表尾部）
                auto last = cache_list.back();
                cache_map.erase(last.first);     // O(1) 从 map 中删除
                cache_list.pop_back();           // O(1) 从 list 中删除
            }
            
            cache_list.push_front({key, value}); // O(1) 插入到头部
            cache_map[key] = cache_list.begin(); // O(1) 更新 map
        }
    }
};
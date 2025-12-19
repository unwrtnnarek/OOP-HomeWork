#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>

template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
    };

    std::vector<std::list<Entry>> buckets;
    size_t numElements;
    double maxLoadFactor;

    // ------------------  1: хеширование ------------------
    size_t getBucketIndex(const K& key) const {
        size_t hash = std::hash<K>{}(key);
        return hash % buckets.size();
    }

    // ------------------  5: rehash ------------------
    void rehash() {
        std::vector<std::list<Entry>> oldBuckets = buckets;
        buckets.resize(buckets.size() * 2); 
        for (auto &bucket : buckets) bucket.clear();
        numElements = 0;

        for (auto &bucket : oldBuckets) {
            for (auto &entry : bucket) {
                insert(entry.key, entry.value);
            }
        }
    }

public:
    // ------------------  0: конструктор ------------------
    HashTable(size_t initialCapacity = 8) {
        if (initialCapacity < 1) initialCapacity = 8;
        buckets.resize(initialCapacity);
        numElements = 0;
        maxLoadFactor = 0.75;
    }

    // ------------------  2: insert ------------------
    void insert(const K& key, const V& value) {
        size_t idx = getBucketIndex(key);
        for (auto &entry : buckets[idx]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
        ++numElements;

        if (getLoadFactor() > maxLoadFactor)
            rehash();
    }

    // ------------------  3: find ------------------
    V* find(const K& key) {
        size_t idx = getBucketIndex(key);
        for (auto &entry : buckets[idx]) {
            if (entry.key == key) return &entry.value;
        }
        return nullptr;
    }

    // ------------------  4: remove ------------------
    bool remove(const K& key) {
        size_t idx = getBucketIndex(key);
        auto &bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --numElements;
                return true;
            }
        }
        return false;
    }

    // ------------------  5: getLoadFactor ------------------
    double getLoadFactor() const {
        return static_cast<double>(numElements) / buckets.size();
    }

    // ------------------  6: вспомогательные методы ------------------
    size_t size() const { return numElements; }
    bool empty() const { return numElements == 0; }
    void clear() {
        for (auto &bucket : buckets) bucket.clear();
        numElements = 0;
    }

    // ------------------  7: статистика коллизий ------------------
    size_t getMaxBucketSize() const {
        size_t maxSize = 0;
        for (const auto &bucket : buckets)
            maxSize = std::max(maxSize, bucket.size());
        return maxSize;
    }

    void printTable() const {
        for (size_t i = 0; i < buckets.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto &entry : buckets[i]) {
                std::cout << "{" << entry.key << ":" << entry.value << "} ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    HashTable<std::string, int> table;

    std::cout << "Insert elements:\n";
    table.insert("apple", 5);
    table.insert("banana", 10);
    table.insert("orange", 7);
    table.insert("grape", 12);
    table.insert("lemon", 3);
    table.insert("apple", 8);

    table.printTable();

    std::cout << "\nFind elements:\n";
    int* val = table.find("banana");
    if (val) std::cout << "banana = " << *val << "\n";

    val = table.find("apple");
    if (val) std::cout << "apple = " << *val << "\n";

    val = table.find("kiwi");
    std::cout << "kiwi found? " << (val ? "Yes" : "No") << "\n";

    std::cout << "\nRemove elements:\n";
    std::cout << "Remove apple: " << (table.remove("apple") ? "Yes" : "No") << "\n";
    std::cout << "Remove kiwi: " << (table.remove("kiwi") ? "Yes" : "No") << "\n";

    table.printTable();

    std::cout << "\nTable stats:\n";
    std::cout << "Size: " << table.size() << "\n";
    std::cout << "Empty? " << (table.empty() ? "Yes" : "No") << "\n";
    std::cout << "Load factor: " << table.getLoadFactor() << "\n";
    std::cout << "Max bucket size: " << table.getMaxBucketSize() << "\n";

    std::cout << "\nClearing table...\n";
    table.clear();
    std::cout << "Empty? " << (table.empty() ? "Yes" : "No") << "\n";

    return 0;
}

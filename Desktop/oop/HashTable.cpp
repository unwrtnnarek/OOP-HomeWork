#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <string>
#include <iostream>

template <typename Key, typename Value>
class HashTable
{
private:
    using Entry = std::pair<Key, Value>;
    std::vector<std::list<Entry>> table;

    size_t elementCount;
    double loadFactorLimit;

    size_t bucketIndex(const Key& key) const
    {
        std::hash<Key> hashFunc;
        return hashFunc(key) % table.size();
    }

    double loadFactor() const
    {
        return static_cast<double>(elementCount) / table.size();
    }

    void rehashTable()
    {
        auto oldTable = table;
        table.clear();
        table.resize(oldTable.size() * 2);

        elementCount = 0;

        for (auto& bucket : oldTable)
        {
            for (auto& entry : bucket)
            {
                insert(entry.first, entry.second);
            }
        }
    }

public:
    HashTable(size_t initialSize = 8)
        : elementCount(0), loadFactorLimit(0.75)
    {
        if (initialSize < 1)
        {
            initialSize = 8;
        }
        table.resize(initialSize);
    }

    void insert(const Key& key, const Value& value)
    {
        size_t index = bucketIndex(key);

        for (auto& entry : table[index])
        {
            if (entry.first == key)
            {
                entry.second = value;
                return;
            }
        }

        table[index].push_back({ key, value });
        ++elementCount;

        if (loadFactor() > loadFactorLimit)
        {
            rehashTable();
        }
    }

    Value* find(const Key& key)
    {
        size_t index = bucketIndex(key);

        for (auto& entry : table[index])
        {
            if (entry.first == key)
            {
                return &entry.second;
            }
        }
        return nullptr;
    }

    bool remove(const Key& key)
    {
        size_t index = bucketIndex(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                --elementCount;
                return true;
            }
        }
        return false;
    }

    size_t size() const
    {
        return elementCount;
    }

    bool empty() const
    {
        return elementCount == 0;
    }

    void clear()
    {
        for (auto& bucket : table)
        {
            bucket.clear();
        }
        elementCount = 0;
    }

    size_t maxBucketSize() const
    {
        size_t maxSize = 0;

        for (const auto& bucket : table)
        {
            if (bucket.size() > maxSize)
            {
                maxSize = bucket.size();
            }
        }
        return maxSize;
    }
};

int main()
{
    return 0;
}

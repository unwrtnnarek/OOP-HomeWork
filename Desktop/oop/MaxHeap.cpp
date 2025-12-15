#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class MaxHeap
{
private:
    std::vector<T> data;

    size_t parentIndex(size_t idx) const
    {
        return (idx - 1) / 2;
    }

    size_t leftIndex(size_t idx) const
    {
        return 2 * idx + 1;
    }

    size_t rightIndex(size_t idx) const
    {
        return 2 * idx + 2;
    }

    void heapifyUp(size_t idx)
    {
        while (idx > 0 && data[parentIndex(idx)] < data[idx])
        {
            std::swap(data[idx], data[parentIndex(idx)]);
            idx = parentIndex(idx);
        }
    }

    void heapifyDown(size_t idx)
    {
        size_t count = data.size();

        while (true)
        {
            size_t left = leftIndex(idx);
            size_t right = rightIndex(idx);
            size_t maxIdx = idx;

            if (left < count && data[maxIdx] < data[left])
                maxIdx = left;

            if (right < count && data[maxIdx] < data[right])
                maxIdx = right;

            if (maxIdx == idx)
                break;

            std::swap(data[idx], data[maxIdx]);
            idx = maxIdx;
        }
    }

public:
    MaxHeap() = default;

    MaxHeap(const std::vector<T>& values)
    {
        data = values;
        if (data.empty()) return;

        for (int i = static_cast<int>(data.size() / 2) - 1; i >= 0; --i)
            heapifyDown(i);
    }

    void push(const T& value)
    {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    void pop()
    {
        if (data.empty())
            throw std::out_of_range("Heap is empty");

        data[0] = data.back();
        data.pop_back();

        if (!data.empty())
            heapifyDown(0);
    }

    const T& top() const
    {
        if (data.empty())
            throw std::out_of_range("Heap is empty");

        return data[0];
    }

    size_t size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }

    void clear()
    {
        data.clear();
    }

    static bool isHeap(const std::vector<T>& values)
    {
        size_t n = values.size();

        for (size_t i = 0; i < n; ++i)
        {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < n && values[i] < values[left]) return false;
            if (right < n && values[i] < values[right]) return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}

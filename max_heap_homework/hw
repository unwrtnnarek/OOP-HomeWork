#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

public:
    // ------------------ 1: вспомогательные методы ------------------
    size_t parent(size_t i) const {
        if (i == 0) return 0;
        return (i - 1) / 2;
    }

    size_t leftChild(size_t i) const {
        return 2 * i + 1;
    }

    size_t rightChild(size_t i) const {
        return 2 * i + 2;
    }

    // ------------------ 2: siftUp ------------------
    void siftUp(size_t i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            size_t p = parent(i);
            std::swap(heap[i], heap[p]);
            i = p;
        }
    }

    // ------------------ 3: siftDown ------------------
    void siftDown(size_t i) {
        size_t n = heap.size();
        while (true) {
            size_t left = leftChild(i);
            size_t right = rightChild(i);
            size_t largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                std::swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // ------------------ 4: push ------------------
    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // ------------------ 5: pop ------------------
    void pop() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
    }

    // ------------------ 6: вспомогательные методы ------------------
    const T& top() const {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        return heap[0];
    }

    size_t size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    void clear() {
        heap.clear();
    }

    void printHeap() const {
        for (const auto& val : heap)
            std::cout << val << " ";
        std::cout << std::endl;
    }

    // ------------------ 7: конструктор с heapify ------------------
    MaxHeap() = default;

    MaxHeap(const std::vector<T>& data) {
        heap = data;
        if (!heap.empty()) {
            for (int i = heap.size() / 2 - 1; i >= 0; --i)
                siftDown(i);
        }
    }

    // ------------------ 8: статический метод isHeap ------------------
    static bool isHeap(const std::vector<T>& data) {
        size_t n = data.size();
        for (size_t i = 0; i <= n / 2; ++i) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < n && data[i] < data[left])
                return false;
            if (right < n && data[i] < data[right])
                return false;
        }
        return true;
    }
};

int main() {
    MaxHeap<int> heap;
    std::cout << "Inserting elements: 10, 20, 5, 30, 25\n";
    heap.push(10);
    heap.push(20);
    heap.push(5);
    heap.push(30);
    heap.push(25);

    std::cout << "Heap after insertions: ";
    heap.printHeap();

    std::cout << "Top element: " << heap.top() << "\n";

    std::cout << "Pop top element\n";
    heap.pop();
    std::cout << "Heap after pop: ";
    heap.printHeap();
    std::cout << "New top element: " << heap.top() << "\n";

    std::vector<int> data = {4, 10, 3, 5, 1};
    MaxHeap<int> heap2(data);
    std::cout << "Heap built from vector: ";
    heap2.printHeap();
    std::cout << "Top element: " << heap2.top() << "\n";

    std::vector<int> testVec1 = {50, 30, 20, 10, 5};
    std::vector<int> testVec2 = {10, 30, 20, 50, 5};

    std::cout << "testVec1 is heap? " << (MaxHeap<int>::isHeap(testVec1) ? "Yes" : "No") << "\n";
    std::cout << "testVec2 is heap? " << (MaxHeap<int>::isHeap(testVec2) ? "Yes" : "No") << "\n";

    size_t idx = 1;
    std::cout << "Parent of index " << idx << ": " << heap2.parent(idx) << "\n";
    std::cout << "Left child of index " << idx << ": " << heap2.leftChild(idx) << "\n";
    std::cout << "Right child of index " << idx << ": " << heap2.rightChild(idx) << "\n";

    return 0;
}

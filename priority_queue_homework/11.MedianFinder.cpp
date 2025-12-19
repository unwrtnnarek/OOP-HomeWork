#include <iostream>
#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right; 

public:
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << "\n"; 

    mf.addNum(3);
    std::cout << mf.findMedian() << "\n"; 

    return 0;
}

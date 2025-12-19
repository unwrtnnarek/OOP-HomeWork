#include <iostream>
#include <queue>
#include <vector>

std::vector<int> kLargest(const std::vector<int>& nums, int n) {
    if (n > nums.size()){
        return nums;
    }
    
    std::priority_queue<int> pq;
    for(int x: nums) {
        pq.push(x);
    }
    
    std::vector<int> temp;
    int count = 0;
    while(count != n) {
        temp.push_back(pq.top());
        pq.pop();
        count++;
    }
    return temp;
}

int main() {
    std::vector<int> nums = {4, 2, 8, 1, 9, 3};
    auto result = kLargest(nums, 9);
    
    for(int x : result) {
        
        std::cout << x;
        
    }
}

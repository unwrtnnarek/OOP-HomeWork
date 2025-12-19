#include <iostream>
#include <queue>
#include <vector>

std::vector<int> heapSort(const std::vector<int>& nums) {
    std::priority_queue<int> pq;
    for(int x: nums) {
        pq.push(x);
    }
    
    std::vector<int> temp(nums.size());
    
   for(int i = nums.size() - 1; i >= 0 ; --i) 
   {    
        temp[i] = pq.top();
        pq.pop();
        
    }
    return temp;
}

int main() {
    std::vector<int> nums = {4, 2, 8, 1, 9, 3};
    auto result = heapSort(nums);
    
    for(int x : result) {
        
        std::cout << x << " ";
        
    }
}

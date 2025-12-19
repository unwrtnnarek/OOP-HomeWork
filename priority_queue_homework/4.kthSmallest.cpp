#include <iostream>
#include <queue>
#include <vector>

int kthSmallest(const std::vector<int>& nums, int k) {
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
    return temp[k - 1];
}

int main() {
    std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
    int k = 3;
    std::cout << kthSmallest(nums, k) << '\n';
}

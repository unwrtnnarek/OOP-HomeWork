#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum += num;

        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }
      
        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    std::vector<int> nums = {1, 1, 1};
    int k = 2;
    int count = subarraySum(nums, k);
    std::cout << count; // 2
}

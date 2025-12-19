#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::map<int, int> freq;

    for (int n : nums) {
        freq[n]++;
    }

    std::vector<std::pair<int, int>> vec(freq.begin(), freq.end());

    std::sort(vec.begin(), vec.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second; 
              });

    std::vector<int> result;
    for (int i = 0; i < k && i < (int)vec.size(); ++i) {
        result.push_back(vec[i].first);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto result = topKFrequent(nums, 2);

    for (int x : result) {
        std::cout << x << " ";
    }

    return 0;
}

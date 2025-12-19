#include <vector>
#include <map>
#include <iostream>

std::map<int, int> countFrequency(const std::vector<int>& nums) {
    std::map<int, int> freq;

    for (int n : nums) {
        freq[n]++;
    }

    return freq;
}

int main() {
    std::vector<int> nums = {4, 2, 3, 4, 2, 3, 4, 3, 1, 4};
    auto result = countFrequency(nums);

    for (const auto& [key, value] : result) {
        std::cout << key << ": " << value << std::endl;
    }

    return 0;
}

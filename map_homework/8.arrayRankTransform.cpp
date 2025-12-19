#include <iostream>
#include <vector>
#include <map>

std::vector<int> arrayRankTransform(const std::vector<int>& arr) {
    std::map<int, int> rankMap;

    for (int x : arr) {
        rankMap[x] = 0; 
    }

    int rank = 1;
    for (auto& [key, value] : rankMap) {
        value = rank++;
    }

  std::vector<int> result;
    result.reserve(arr.size());
    for (int x : arr) {
        result.push_back(rankMap[x]);
    }

    return result;
}

int main() {
    std::vector<int> arr = {40, 10, 20, 30};
    auto result = arrayRankTransform(arr);

    for (int x : result) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> arr2 = {100, 100, 100};
    auto result2 = arrayRankTransform(arr2);

    for (int x : result2) std::cout << x << " ";
    std::cout << "\n";
}

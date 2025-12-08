#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>


std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& words) {
    std::map<std::string, std::vector<std::string>> groups;

    for (const std::string& word : words) {
        std::string key = word;
        std::sort(key.begin(), key.end()); 
        groups[key].push_back(word); 
    }
    std::vector<std::vector<std::string>> result;
    for (auto& [key, vec] : groups) {
        result.push_back(vec);
    }

    return result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(words);

    for (const auto& group : result) {
        std::cout << "[ ";
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}

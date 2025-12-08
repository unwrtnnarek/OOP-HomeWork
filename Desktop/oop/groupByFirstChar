#include <iostream>
#include <vector>
#include <string>
#include <map>

std::map<char, std::vector<std::string>> groupByFirstChar(const std::vector<std::string>& words) {
    std::map<char, std::vector<std::string>> groups;

    for (const std::string& word : words) {
        if (!word.empty()) {
            char first = word[0];
            groups[first].push_back(word); 
        }
    }

    return groups;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    auto result = groupByFirstChar(words);

    for (const auto& [ch, vec] : result) {
        std::cout << ch << ": ";
        for (const auto& w : vec) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

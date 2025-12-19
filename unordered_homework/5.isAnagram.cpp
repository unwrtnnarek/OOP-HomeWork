#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> balance;

    for (int i = 0; i < s.length(); ++i) {
        balance[s[i]]++;
        balance[t[i]]--;
    }

    for (const auto& pair : balance) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    bool res1 = isAnagram("anagram", "nagaram");
    bool res2 = isAnagram("rat", "car");

    std::cout << res1 << std::endl; // 1 (true)
    std::cout << res2 << std::endl; // 0 (false)
}

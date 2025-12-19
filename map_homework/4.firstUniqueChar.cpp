#include <string>
#include <map>
#include <iostream>


int firstUniqueChar(const std::string& s) {
    std::map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < (int)s.size(); ++i) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::string s = "leetcode";
    std::cout << firstUniqueChar(s) << '\n';  // 0 ('l')

    std::string s2 = "loveleetcode";
    std::cout << firstUniqueChar(s2) << '\n';  // 2 ('v')

    return 0;
}

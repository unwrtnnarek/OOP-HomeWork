#include <iostream>
#include <map>
#include <string>

int removeInfrequent(std::map<std::string, int>& freq, int threshold) {
    int removed = 0;

    for (auto it = freq.begin(); it != freq.end(); ) {
        if (it->second < threshold) {
            it = freq.erase(it);
            removed++;
        } else {
            ++it;
        }
    }

    return removed;
}

int main() {
    std::map<std::string, int> freq = {
        {"apple", 5},
        {"banana", 2},
        {"cherry", 8},
        {"date", 1}
    };

    int removed = removeInfrequent(freq, 3);
    std::cout << removed << '\n'; 

    for (const auto& [key, value] : freq) {
        std::cout << key << ": " << value << '\n';
    }

    return 0;
}

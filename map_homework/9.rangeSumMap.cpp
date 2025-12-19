#include <iostream>
#include <map>

int rangeSumMap(const std::map<int, int>& m, int left, int right) {
    int sum = 0;

    auto it = m.lower_bound(left);

    while (it != m.end() && it->first <= right) {
        sum += it->second;
        ++it;
    }

    return sum;
}

int main() {
    std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};

    std::cout << rangeSumMap(m, 3, 7) << '\n';
    std::cout << rangeSumMap(m, 2, 4) << '\n';

    return 0;
}

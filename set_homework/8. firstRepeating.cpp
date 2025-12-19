#include <iostream>
#include <vector>
#include <set>
using namespace std;

int firstRepeating(const vector<int>& nums) {
    set<int> s;

    for (int x : nums) {
        if (s.find(x) != s.end()) {
            return x;
        }
        s.insert(x);
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
    cout << firstRepeating(nums) << '\n';
}

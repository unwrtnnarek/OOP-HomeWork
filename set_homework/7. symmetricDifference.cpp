#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> symmetricDifference(const vector<int>& v1, const vector<int>& v2) {
    set<int> s1(v1.begin(), v1.end());
    set<int> s2(v2.begin(), v2.end());
    vector<int> result;

    for (int x : s1) {
        if (s2.find(x) == s2.end())
            result.push_back(x);
    }

    for (int x : s2) {
        if (s1.find(x) == s1.end())
            result.push_back(x);
    }

    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result.size() - 1 - i; ++j) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {3, 4, 5, 6};

    auto result = symmetricDifference(arr1, arr2);

    for (int x : result){
        cout << x << " ";
    }
    cout << endl;
}

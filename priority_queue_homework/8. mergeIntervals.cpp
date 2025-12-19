#include <vector>
#include <queue>

std::vector<std::pair<int,int>> mergeIntervals(const std::vector<std::pair<int,int>>& intervals) {
    if (intervals.empty()) return {};

    auto cmp = [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
        decltype(cmp)
    > pq(cmp);

    for (auto &p : intervals) {
        pq.push(p);
    }

    std::vector<std::pair<int,int>> merged;
  
    auto current = pq.top();
    pq.pop();

    while (!pq.empty()) {
        auto next = pq.top();
        pq.pop();

        if (next.first <= current.second) {
            current.second = std::max(current.second, next.second);
        } else {
            merged.push_back(current);
            current = next;
        }
    }

    merged.push_back(current);

    return merged;
}

int main() {
    std::vector<std::pair<int,int>> v = {{1,3},{2,6},{8,10},{9,12}};
    auto merged = mergeIntervals(v);

    for (auto &p : merged)
        std::cout << p.first << " " << p.second << "\n";
}

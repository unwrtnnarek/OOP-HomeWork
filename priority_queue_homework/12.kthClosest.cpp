#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct Point {
    int x, y;
};

int dist2(const Point& p) {
    return p.x * p.x + p.y * p.y;
}

std::vector<Point> kClosest(const std::vector<Point>& points, int K) {
    auto cmp = [](const Point& a, const Point& b) {
        return dist2(a) < dist2(b); 
    };
    std::priority_queue<Point, std::vector<Point>, decltype(cmp)> pq(cmp);

    for (auto &p : points) {
        pq.push(p);
        if (pq.size() > K)
            pq.pop();
    }

    std::vector<Point> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::vector<Point> pts = {{1,3}, {-2,2}, {5,8}};
    auto result = kClosest(pts, 2);

    for (auto &p : result)
        std::cout << "{" << p.x << "," << p.y << "} ";
}

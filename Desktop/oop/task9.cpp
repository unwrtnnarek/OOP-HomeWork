#include "iostream"
#include "array"

template <typename T, size_t N>

void shiftLeft(std::array<T, N>& arr, size_t pos) {
    pos == pos % N;
    if(pos == 0) return;
    
    std::array<T, N> temp;
    for(size_t i = 0; i < N; i++) {
        temp[i] = arr[(i + pos) % N];
    }
    arr = temp;
}

int main() {

std::array<int, 5> arr9 = {1, 2, 3, 4, 5};
    shiftLeft(arr9, 2);
    std::cout << "shift left  2: ";
    for (int x : arr9) std::cout << x << " ";
    std::cout << "\n";
}
#include "iostream"
#include "array"
 template<typename T, size_t N, size_t M>
std::array <T, M> copySubArr(const std::array<T, N>& arr, size_t start, size_t count) {
    std::array<T, M> result;
    if(start + count > N || M != count) {
        throw std::out_of_range("Error");
    }
    for(size_t i = 0; i < count; i++) {
        result[i] = arr[start + i];
    }
    return result;
 }





int main()
{
  std::array<int, 10> source = {1,2,3,4,5,6,7,8,9,10};
    auto sub = copySubArr<int, 10, 5>(source, 2, 5);
    std::cout << "copied arr: ";
    for (int x : sub) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
#include "iostream"
#include "array"
 template<typename T, size_t N>
bool comparearr(const std::array<T, N>& a1 , const std::array<T, N>& a2 ) {
    for(size_t i = 0; i < N ; i++) {
        if(a1[i] != a2[i]) {
            return false;
        }
    }
    return true;
}




int main()
{
   std::array<int, 3> a = {1, 2, 3}, b = {1, 2, 3}, c = {3, 2, 1};
   std::cout << "6. compareArrays (a == b): " << comparearr(a, b) << "\n";
   std::cout << "6. compareArrays (a == c): " << comparearr(a, c) << "\n";
   

    return 0;
}
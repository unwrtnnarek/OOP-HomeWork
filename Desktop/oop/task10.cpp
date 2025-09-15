#include "iostream"
#include "array"

template <typename T, size_t R, size_t C, typename F>
std::array<std::array<T, C>, R> process2DArray(
    const std::array<std::array<T, C>, R>& matrix,
    F foo ) {

	std::array<std::array<T, C>, R> result;

	for (size_t i = 0; i < R; ++i) {
		for (size_t j = 0; j < C; ++j) {
			result[i][j] = foo(matrix[i][j]);
		}
	}

	return result;
}


int main () {
	std::array<std::array<int, 3>, 3> mat= {{
			{{1,2,3}}, {{4,5,6}}, {{7,8,9}}
		}
	};
	auto doub = process2DArray(mat, [](int x) {
		return x * 2;

	});
	for (const auto& row : doub ) {
		for (int x : row) std::cout << x << " ";
		std::cout << "\n";
	}
}
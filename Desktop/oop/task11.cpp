#include "iostream"
#include "array"

template <typename T, size_t N>
bool validArray(const std::array<T, N>& arr, T min, T max) {
	for (const auto& val : arr) {
		if (val < min || val > max) {
			return false;
		}
	}
	return true;
}


int main () {
	std::array<int, 4> scores = {85, 92, 78, 96};
	bool valid = validArray(scores, 0, 100);
	std::cout << "0-100: " << (valid ? "true" : "false") << "\n";

	std::array<int, 4> scoresInvalid = {85, 999, 78, -4};
	valid = validArray(scoresInvalid, 0, 100);
	std::cout << "invalid: " << (valid ? "true" : "false") << "\n";

}
#include "iostream"
#include "array"

template <size_t N>
std::array<int, 256> countFreq(const std::array<char, N>& in) {
    
	std::array<int, 256> freq = {0};

	for (char c : in) {
		freq[static_cast<unsigned char>(c)]++;
	}

	return freq;
}



int main() {
	std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
	auto freq = countFreq<5>(text);

	std::cout << freq['h'] << "\n";
	std::cout << freq['e'] << "\n";
	std::cout << freq['l'] << "\n";
	std::cout << freq['o'] << "\n";

	return 0;
}
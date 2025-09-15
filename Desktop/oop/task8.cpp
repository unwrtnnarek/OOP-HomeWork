#include <iostream>
#include <array>

class Matrix3x3 {
private:
	std::array<std::array<int, 3>, 3> data;

public:
	Matrix3x3(int a1, int a2, int a3,
	          int b1, int b2, int b3,
	          int c1, int c2, int c3) {
		data = {{
				{{a1, a2, a3}},
				{{b1, b2, b3}},
				{{c1, c2, c3}}
			}
		};
	}

	int getElem(size_t row, size_t col) const {
		return data.at(row).at(col);
	}

	void setElement(size_t row, size_t col, int value) {
		data.at(row).at(col) = value;
	}

	void transpose() {
		for (size_t i = 0; i < 3; ++i) {
			for (size_t j = i + 1; j < 3; ++j) {
				std::swap(data[i][j], data[j][i]);
			}
		}
	}

	void print() const {
		for (const auto& row : data) {
			for (int x : row) {
				std::cout << x << " ";
			}
			std::cout << "\n";
		}
	}

	const std::array<int, 3>& operator[](size_t row) const {
		return data[row];
	}

	std::array<int, 3>& operator[](size_t row) {
		return data[row];
	}
};

int main() {
	Matrix3x3 matrix(1, 2, 3,
	                 4, 5, 6,
	                 7, 8, 9);

	std::cout << "Matrix3x3 original:\n";
	matrix.print();

	matrix.transpose();

	std::cout << "Matrix3x3 transposed:\n";
	matrix.print();

	std::cout << "by operator[][]: " << matrix[1][2] << "\n";

	return 0;
}

#include "matrix.hpp"
#include <iostream>

int main(){

	int rows = 5;
	int cols = 4;
	Matrix<int> M(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			M(i,j) = i+j;
		}
	}

	std::cout << "The original matrix: " << std::endl;
	M.print();

	std::cout << "Reshaping the matrix: " << std::endl;
	M.reshape(4,5);  // checked for leaks with valgrind
	M.print();   // agrees with Matlab

	std::cout << "Transpose the matrix in place: " << std::endl;
	M.transposeInPlace();
	M.print();

	// what's broken here?
	std::cout << "Transposing and creating a new array " << std::endl;
	Matrix<int> M2 = M.transpose();
	M2.print();

}

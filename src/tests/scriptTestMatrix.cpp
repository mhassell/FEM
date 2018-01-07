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
	M.reshape(2,10);  // checked for leaks with valgrind
	M.print();   	 // agrees with Matlab

	std::cout << "Transpose the matrix in place: " << std::endl;
	M.transposeInPlace();
	M.print();
	
	// this was broken because we needed a copy constructor
	std::cout << "Transposing and creating a new array " << std::endl;
	Matrix<int> M2 = M.transpose();
	M2.print();

	// test copy constructor
	std::cout << "Test copy constructor" << std::endl;
	Matrix<int> M3 = M;
	M3.print();

	// test copy assignment operator (and its effects)
	std::cout << "Test copy assignment operator" << std::endl;
	Matrix<int> M4;
	M4 = M;
	M4.print();

}

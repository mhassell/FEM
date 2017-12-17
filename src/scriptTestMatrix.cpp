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

	M.print();

}

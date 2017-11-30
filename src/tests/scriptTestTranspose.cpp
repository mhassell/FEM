// test the transpose utility

#include "utils.hpp"

int main(){

	int rows = 4;
	int cols = 7;

	int **b;
	b = new int *[rows];
	for(int i = 0; i < rows; i++){
		b[i] = new int[cols];
	}

	int tmp = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			b[i][j] = tmp;
			tmp++;
		}
	}

	printMatrix(b,rows,cols);	

	int** c;

	c = transposeMatrix(b,rows,cols);

	printMatrix(c, cols, rows);

	for(int i = 0; i < rows; i++){
		delete[] b[i];
	}
	delete[] b;

	for(int i = 0; i < cols; i++){
		delete[] c[i];
	}
	delete[] c;


}

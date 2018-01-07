// test the reshape utility

#include "utils.hpp"

int main(){

	int rows = 4;
	int cols = 8;

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

	c = reshapeMatrix(b,rows,cols,2,16);

	printMatrix(c, 2, 16);

	for(int i = 0; i < rows; i++){
		delete[] b[i];
	}
	delete[] b;

	for(int i = 0; i < 2; i++){
		delete[] c[i];
	}
	delete[] c;

	// printMatrix(c, cols, rows);


}

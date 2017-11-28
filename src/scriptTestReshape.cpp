// test the reshape utility

#include "utils.h"

int main(){

	int **b;
	b = new int *[rows];
	for(int i = 0; i < rows; i++){
		b[i] = new int[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			b[i][j] = 2+i+j;
		}
	}

	printMatrix(b,rows,cols);	

	for(int i = 0; i < rows; i++){
		delete[] b[i];
	}
	delete[] b;

	


}

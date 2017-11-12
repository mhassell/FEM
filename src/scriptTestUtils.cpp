#include "utils.hpp"

int main(){

	int rows = 5;
	int cols = 7;

	double **a;
	a = new double*[rows];
	for(int i = 0; i < rows; i++){
		a[i] = new double[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			a[i][j] = 2.0/(i+j+1);
		}
	}

	printMatrix(a,rows,cols);

	for(int i = 0; i < rows; i++){
		delete[] a[i];
	}

	delete[] a;

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

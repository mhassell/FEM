// testing newing and deleting some arrays, verify it works with valgrind

#include <iostream>

int main(){

	int rowcount = 4;
	int colcount = 2;

	double **coordinates = new double*[rowcount];
	for(int i = 0; i < rowcount; i++){
		coordinates[i] = new double[colcount];
	}

	// assign
	for(int i = 0; i < rowcount; i++){
		for(int j = 0; j < colcount; j++){
			coordinates[i][j] = 1+i+j;
		}
	}

	// print
	for(int i = 0; i < rowcount; i++){
		for(int j = 0; j < colcount; j++){
			std::cout << coordinates[i][j] << std::endl;
		}
	}

	// free (need to use both!!)
	for(int i = 0; i < rowcount; i++){
    	delete [] coordinates[i];
	}

	delete [] coordinates;

}
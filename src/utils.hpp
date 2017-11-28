#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cassert>

// a utility header to simplify some code

// print a general matrix
template <typename T>
void printMatrix(T &a, int m, int n){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cout << a[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// print a 1d array
template <typename T>
void printArray(T &a, int m){

	for(int i = 0; i < m; i++){
		std::cout << a[i] << std::endl;
	}
	std::cout << std::endl;

}

// zero a matrix (without uniform initializers)
template <typename T>
void zeroMatrix(T &a, int m, int n){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
				a[i][j] = 0;
		}
	}
	
}

// reshape a matrix, return a pointer to it (do not delete the old one)
template <typename T>
T* reshapeMatrix(T &a, int mold, int nold, int mnew, int nnew){

	assert(mold*nold == mnew*nnew);

	for(int i = 0; i < mold; i++){
		for(int j = 0; j < nold; j++){
			
		}
	}

}

// transpose a matrix, return a pointer to it (do not delete the old one)
template <typename T>
T* transposeMatrix(T &a, int m, int n){
	
	

}

#endif

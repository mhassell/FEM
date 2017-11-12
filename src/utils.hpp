#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

// a utility header to simplify some code

template <typename T>
void printMatrix(T &a, int m, int n){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif

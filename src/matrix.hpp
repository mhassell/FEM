// my attempt at an Eigen-style header-only matrix class

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <cassert>

template <typename T>
class Matrix{

	public:
		int nrows();
		int ncols();

		void transpose();
		void reshape(int, int);
		void print();
		void zero();

		T& operator()(int, int); // access operator

		Matrix();
		Matrix(int, int);
		~Matrix();
		
	private:
		int rows;
		int cols;
		T** elts;
		

};

template <typename T>
Matrix<T>::Matrix(){
	
	rows = 0;
	cols = 0;

};

template <typename T>
Matrix<T>::Matrix(int m, int n){

	rows = m;
	cols = n;

	elts = new T*[m];

	for(int i = 0; i < m; i++){
		elts[i] = new T[n];
	}

}

template <typename T>
Matrix<T>::~Matrix(){

	if(rows!=0){
		for(int i = 0; i < rows; i++){					
			delete[] elts[i];
		}
		delete[] elts;
	}


}

template <typename T>
int Matrix<T>::nrows(){

	return rows;

}

template <typename T>
int Matrix<T>::ncols(){

	return cols;

}

template <typename T>
void Matrix<T>::print(){

	assert(rows*cols != 0); 	// works for null as well

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			std::cout << elts[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

template <typename T>
T& Matrix<T>::operator()(int i, int j){
	// need to return a reference for this to work for assignment
	assert(rows*cols != 0);
	return elts[i][j];

}


#endif

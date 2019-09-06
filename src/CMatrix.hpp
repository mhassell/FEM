// my attempt at an Eigen-style header-only CMatrix class

#ifndef CMatrix_HPP
#define CMATRIX_HPP

#include <iostream>
#include <cassert>

template <typename T>
class CMatrix{

	public:
		int nrows();
		int ncols();

		CMatrix<T> transpose();
		void transposeInPlace();
		void reshape(int, int);
		void print();
		void zero();

		T& operator()(int, int); // access operator
	
		// specialized object methods (rule of 3, etc)
		CMatrix();
		CMatrix(int, int);
		~CMatrix();
		CMatrix(const CMatrix&);  // copy constructor
		CMatrix<T>& operator=(const CMatrix&); // copy assignment op
		CMatrix<T> operator*(const CMatrix&); // matrix mult operator

	private:
		int rows;
		int cols;
		T** elts;
};

template <typename T>
CMatrix<T>::CMatrix(){
	
	rows = 0;
	cols = 0;

};

template <typename T>
CMatrix<T>::CMatrix(int m, int n){

	rows = m;
	cols = n;

	elts = new T*[m];

	for(int i = 0; i < m; i++){
		elts[i] = new T[n];
	}

}

template <typename T>
CMatrix<T>::~CMatrix(){

	if(rows!=0){
		for(int i = 0; i < rows; i++){					
			delete[] elts[i];
		}
		delete[] elts;
	}


}

template <typename T>
int CMatrix<T>::nrows(){

	return rows;

}

template <typename T>
int CMatrix<T>::ncols(){

	return cols;

}

template <typename T>
void CMatrix<T>::print(){

	assert(rows*cols != 0); 	// works for null as well

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			std::cout << elts[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

template <typename T>
T& CMatrix<T>::operator()(int i, int j){

	// need to return a reference (T&) for this to work for assignment
	assert(rows*cols != 0);
	return elts[i][j];

}

template <typename T>
void CMatrix<T>::reshape(int new_rows, int new_cols){


	assert(rows*cols != 0);
	assert(rows*cols == new_rows*new_cols);
	
	T** newMatrix = new T*[new_rows];
	for(int i = 0; i < new_rows; i++){
		newMatrix[i] = new T[new_cols];
	}

	T tmp[rows*cols];

	// it would be nice to do away with this...
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			tmp[i*rows+j] = elts[j][i];
		}
	}

	for(int i = 0; i < new_cols; i++){
		for(int j = 0; j < new_rows; j++){
			newMatrix[j][i] = tmp[i*new_rows+j];
		}
	}

	// reassign the object's array to the newMatrix and delete the old 
	for(int i = 0; i < rows; i++){
		delete[] elts[i];
	}
	delete[] elts;

	elts = newMatrix;
	rows = new_rows;
	cols = new_cols;

}

template <typename T>
void CMatrix<T>::zero(){

	assert(rows*cols != 0);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			elts[i][j] = 0;
		}
	}

}

template <typename T> 
CMatrix<T> CMatrix<T>::transpose(){

	// does not transpose in place

	assert(rows*cols != 0);

	CMatrix<T> transposed(cols,rows);
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			transposed(i,j) = elts[j][i];
		}
	}

	return transposed;

}

template <typename T>
void CMatrix<T>::transposeInPlace(){

	// transposes in place
	assert(rows*cols != 0);

	T temp[rows*cols]; // need temp variable b/c of aliasing

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			temp[i*cols+j] = elts[i][j];
		}
	}

	for(int i = 0; i < rows; i++){
		delete[] elts[i];
	}
	delete[] elts;

	elts = new T*[cols];
	for(int i = 0; i < cols; i++){
		elts[i] = new T[rows];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			elts[j][i] = temp[i*cols+j];
		}
	}

	int swap = rows;
	rows = cols;
	cols = swap;

}

// copy constructor
template <typename T>
CMatrix<T>::CMatrix(const CMatrix &M1){

	rows = M1.rows;
	cols = M1.cols;
	elts = new T*[rows];
	for(int i = 0; i < rows; i++){
		elts[i] = new T[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			elts[i][j] = M1.elts[i][j];
		}
	}
}

// copy assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T> &M1){

	rows = M1.rows;
	cols = M1.cols;
	elts = new T*[rows];
	for(int i = 0; i < rows; i++){
		elts[i] = new T[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			elts[i][j] = M1.elts[i][j];
		}
	}
	
	// why?
	return *this;

}

template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix& other){

	// check the dimensions are compatible
	assert(cols == other.rows);
	int m = rows;
	int n = cols;
	int p = other.cols;

	CMatrix<T> answer(m,p);
	answer.zero();
	
	// can we do away with accessing the underlying elts array?
	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){
			for(int k = 0; k < n; k++){
				answer.elts[i][j] += this->elts[i][k] * other.elts[k][j];
			}
		}
	}
	
	return answer;

}

#endif

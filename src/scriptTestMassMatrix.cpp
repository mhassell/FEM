#include "Matrices.hpp"
#include "triangulation.h"

#include <iostream>
#include <Eigen/Sparse>

int main(){

	Triangulation T(2,2,2,4);

	T.xcoords[0] = 0.0;
	T.xcoords[1] = 1.0;
	T.xcoords[2] = 0.8;
	T.xcoords[3] = 0.2;

	T.ycoords[0] = 0.0;
	T.ycoords[1] = 0.0;
	T.ycoords[2] = 0.7;
	T.ycoords[3] = 1.0;

	T.elements[0][0] = 0;
	T.elements[0][1] = 1;
	T.elements[0][2] = 3;

	T.elements[1][0] = 1;
	T.elements[1][1] = 2;
	T.elements[1][2] = 3;

	T.dirichlet[0][0] = 0;
	T.dirichlet[0][1] = 1;
	T.dirichlet[1][0] = 1;
	T.dirichlet[1][1] = 2;

	T.neumann[0][0] = 2;
	T.neumann[0][1] = 3;
	T.neumann[1][0] = 3;
	T.neumann[1][1] = 0;

	int k = 0;
	Eigen::SparseMatrix<double> Mh = massMatrix(T, k);

	

}
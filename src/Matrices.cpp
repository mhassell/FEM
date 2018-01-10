#include <Eigen/Sparse>

#include "matrix.hpp"
#include "tableQuadTri.hpp"
#include "triangulation.h"
#include "Matrices.hpp"

Eigen::SparseMatrix<double> massMatrix(const Triangulation &T, int k){

	Matrix<double> formula = tableQuadTri(2*k+1);

	Matrix<double> x1(1,T.nPoints);
	Matrix<double> y1(1,T.nPoints);

	for(int i = 0; i < T.nPoints; i++){
		x1(0,i) = T.xcoords[i];
		y1(0,i) = T.ycoords[i];
	}

	Matrix<double> xelts()
	for(int i = 0; i < )

}

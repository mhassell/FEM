#include <Eigen/Sparse>
#include <iostream>
#include <functional>

#include "CMatrix.hpp"           // My header-only matrix class
#include "tableQuadTri.hpp"		 // 
#include "triangulation.h"		 // My CTriangulation
#include "Matrices.hpp"			 // Where FE family matrices are defined

Eigen::SparseMatrix<double> CMmassMatrix(std::function<double(double,double)> c, const Triangulation &T, int k){

	Matrix<double> formula = tableQuadTri(2*k+1);

	Matrix<double> x1(1,T.nPoints);
	Matrix<double> y1(1,T.nPoints);

	for(int i = 0; i < T.nPoints; i++){
		x1(0,i) = T.xcoords[i];
		y1(0,i) = T.ycoords[i];
	}

	Matrix<double> xelts(3,T.nElts);
	Matrix<double> yelts(3,T.nElts);

	for(int i = 0; i < T.nElts; i++){
		xelts(0,i) = x1(0,T.elements[i][0]);
		xelts(1,i) = x1(0,T.elements[i][1]);
		xelts(2,i) = x1(0,T.elements[i][2]);
		yelts(0,i) = y1(0,T.elements[i][0]);
		yelts(1,i) = y1(0,T.elements[i][1]);
		yelts(2,i) = y1(0,T.elements[i][2]);
	}

	Matrix<double> quadPts(formula.nrows(),3);
	for(int i = 0; i < formula.nrows(); i++){
		quadPts(i,0) = formula(i,0);
		quadPts(i,1) = formula(i,1);
		quadPts(i,2) = formula(i,2);
	}

	Matrix<double> x(formula.nrows(),T.nElts);
	Matrix<double> y(formula.nrows(),T.nElts);
	x.zero();
	y.zero();

	x = quadPts*xelts;
	y = quadPts*yelts;

	Matrix<double> cc(formula.nrows(),T.nElts);
	cc.zero();

	for(int i = 0; i < formula.nrows(); i++){
		for(int j = 0; j < T.nElts; j++){
			cc(i,j) = c(x(i,j),y(i,j));
		}
	}

	for(int i = 0; i < formula.nrows(); i++){
		for(int j = 0; j < T.nElts; j++){
			cc(i,j) = cc(i,j)*T.area[j];
		}
	}

	
	
}

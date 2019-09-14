#include <Eigen/Sparse>
#include <iostream>
#include <functional>

#include "CMatrix.hpp"           // My header-only matrix class
#include "tableQuadTri.hpp"		 // 
#include "CTriangulation.hpp"	 // My CTriangulation
#include "CMassMatrix.hpp"		 // Where mass matrix is defined

Eigen::SparseMatrix<double> CMassMatrix(std::function<double(double,double)> c, const CTriangulation &T, int k){

	CMatrix<double> formula = tableQuadTri(2*k+1);

	CMatrix<double> x1(1,T.nPoints);
	CMatrix<double> y1(1,T.nPoints);

	for(int i = 0; i < T.nPoints; i++){
		x1(0,i) = T.xcoords[i];
		y1(0,i) = T.ycoords[i];
	}

	CMatrix<double> xelts(3,T.nElts);
	CMatrix<double> yelts(3,T.nElts);

	for(int i = 0; i < T.nElts; i++){
		xelts(0,i) = x1(0,T.elements[i][0]);
		xelts(1,i) = x1(0,T.elements[i][1]);
		xelts(2,i) = x1(0,T.elements[i][2]);
		yelts(0,i) = y1(0,T.elements[i][0]);
		yelts(1,i) = y1(0,T.elements[i][1]);
		yelts(2,i) = y1(0,T.elements[i][2]);
	}

	CMatrix<double> quadPts(formula.nrows(),3);
	for(int i = 0; i < formula.nrows(); i++){
		quadPts(i,0) = formula(i,0);
		quadPts(i,1) = formula(i,1);
		quadPts(i,2) = formula(i,2);
	}

	CMatrix<double> x(formula.nrows(),T.nElts);
	CMatrix<double> y(formula.nrows(),T.nElts);
	x.zero();
	y.zero();

	x = quadPts*xelts;
	y = quadPts*yelts;

	CMatrix<double> cc(formula.nrows(),T.nElts);
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

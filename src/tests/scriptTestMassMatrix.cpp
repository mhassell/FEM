#include "CMatrix.hpp"
#include "CTriangulation.hpp"
#include "CMassMatrix.hpp"

#include <iostream>
#include <functional>
#include <Eigen/Sparse>
#include <math.h>

auto cc = [] (double x, double y){return 1 + pow(x,2) + pow(y,2);};
std::function<double(double,double)> c = cc;

int main(){

	int k = 0;
	CTriangulation TT(2,2,2,4);

	TT.xcoords[0] = 0.0;
	TT.xcoords[1] = 1.0;
	TT.xcoords[2] = 0.8;
	TT.xcoords[3] = 0.2;

	TT.ycoords[0] = 0.0;
	TT.ycoords[1] = 0.0;
	TT.ycoords[2] = 0.7;
	TT.ycoords[3] = 1.0;

	TT.elements[0][0] = 0;
	TT.elements[0][1] = 1;
	TT.elements[0][2] = 3;

	TT.elements[1][0] = 1;
	TT.elements[1][1] = 2;
	TT.elements[1][2] = 3;

	TT.dirichlet[0][0] = 0;
	TT.dirichlet[0][1] = 1;
	TT.dirichlet[1][0] = 1;
	TT.dirichlet[1][1] = 2;

	TT.neumann[0][0] = 2;
	TT.neumann[0][1] = 3;
	TT.neumann[1][0] = 3;
	TT.neumann[1][1] = 0;

	TT.RedRefinement();

	Eigen::SparseMatrix<double> Mh = CMassMatrix(c, TT, k);

	

}
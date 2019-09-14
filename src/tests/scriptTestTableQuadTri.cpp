#include "tableQuadTri.hpp"
#include "CMatrix.hpp"
#include <Eigen/Dense>
#include <iostream>

int main(){

	int k = 6;
	CMatrix<double> qd = tableQuadTri(k);

	qd.print();

}

#include "tableQuadTri.hpp"
#include "matrix.hpp"
#include <Eigen/Dense>
#include <iostream>

int main(){

	int k = 3;
	Matrix<double> qd = tableQuadTri(k);

	qd.print();

}

#include "tableQuadTri.hpp"
#include "matrix.hpp"
#include <Eigen/Dense>
#include <iostream>

int main(){

	int k = 6;
	Matrix<double> qd = tableQuadTri(k);

	qd.print();

}

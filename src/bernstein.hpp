#ifndef BERNSTEIN_HPP
#define BERNSTEIN_HPP

#include "matrix.hpp"

// make the bernstein-bezier basis

struct bb
{

	Matrix<double> P;
	int*** indices;
	int size1;
	int size2;
	int size3;

};

bb bernstein(Matrix<double> x, Matrix<double> y, int k);

#endif
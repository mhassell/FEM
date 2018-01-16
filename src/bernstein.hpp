#ifndef BERNSTEIN_HPP
#define BERNSTEIN_HPP

#include "matrix.hpp"

// make the bernstein-bezier basis

struct bb
{

	Matrix<double> P;
	Matrix<int> indices;

};

bb bernstein(Matrix<double> x, Matrix<double> y, int k);

#endif
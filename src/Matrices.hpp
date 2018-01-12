#ifndef MATRICES_HPP
#define MATRICES_HPP

#include <Eigen/Sparse>
#include "triangulation.h"

Eigen::SparseMatrix<double> massMatrix(double (*c)(double, double), const Triangulation &T, int k);

#endif



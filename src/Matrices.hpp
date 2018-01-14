#ifndef MATRICES_HPP
#define MATRICES_HPP

#include <Eigen/Sparse>
#include <functional>
#include "triangulation.h"

Eigen::SparseMatrix<double> massMatrix(std::function<double(double,double)>, const Triangulation &T, int k);

#endif



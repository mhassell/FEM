#ifndef CMASSMATRIX_HPP
#define CMASSMATRIX_HPP

#include <Eigen/Sparse>
#include <functional>
#include "CTriangulation.hpp"

Eigen::SparseMatrix<double> CMassMatrix(std::function<double(double,double)>, const CTriangulation &T, int k);

#endif



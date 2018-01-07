// triangular quadrature

#include "matrix.hpp"
#include <Eigen/MatrixXd>

// form=tableQuadTri(k)
//
// Input:
//   k       : degree of the formula
// Output:
//   form    : N x 4 matrix (barycentric coordinates and coefficients)
//             for a formula of degree k in the reference triangle
//             Remark: sum(weights)=1

Matrix<double> tableQuadTri(int k){

	Eigen::MatrixXd eigenForm;

	switch(k)
	{
		
		case 0:
			eigenForm << 1/3, 1/3, 2;
			break;
		
		
	}

	int m = eigenForm.rows();
	int n = eigenFOrm.cols();

	Matrix<double> form(m,n);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			form(i,j) = eigenForm(i,j);
		}
	}

	return form;
	

}

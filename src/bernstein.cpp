#include "bernstein.cpp"
#include "matrix.hpp"
#include <cassert.h>
#include <math.h>

bb bernstein(Matrix<double> x, Matrix<double> y, int k)
{

	assert(x.nrows()==1);

	Matrix<double> lambda1(x.nrows(),k+1);
	Matrix<double> lambda2(x.nrows(),k+1);
	Matrix<double> lambda3(x.nrows(),k+1);

	for(int i = 0; i < x.nrows(); i++)
	{
		for(int j = 0; j < k+1; j++)
		{
			lambda1(i,j) = pow(1-x(i,0)-y(i,0), j);
			lambda2(i,j) = pow(x(i,0), j);
			lambda3(i,j) = pow(y(i,0), j);
		}
	}

}

void location(int k)
{

	if(k==0)
	{

	}
}
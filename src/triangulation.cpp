#include <iostream>
#include <Eigen/Dense>

#include "triangulation.h"

// constructors
Triangulation::Triangulation(int numElts, int numDirichlet, int numNeumann, int nPoints){

	nElts = numElts;
	nDirichlet = numDirichlet;
	nNeumann = numNeumann;

	double *xcoords = new double[nPoints];
	double *ycoords = new double[nPoints];

	// element array
	int **elements = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		elements[i] = new int[3];
	}

	// dirichlet edges
	int **dirichlet = new int*[nDirichlet];
	for(int i = 0; i < nDirichlet; i++){
		dirichlet[i] = new int[2];
	}

	// neumann edges
	int **neumann = new int*[nNeumann];
	for(int i = 0; i < nNeumann; i++){
		neumann[i] = new int[2];
	}

}

// destructor
Triangulation::~Triangulation(){

	delete [] xcoords;
	delete [] ycoords;

	for(int i = 0; i < nElts; i++){
		delete [] elements[i];
	}
	
	delete [] elements;

	for(int i = 0; i < nDirichlet; i++){
		delete [] dirichlet[i];
	}
	
	for(int i = 0; i < nNeumann; i++){
		delete [] neumann[i];
	}
	
	delete [] neumann;
	
}

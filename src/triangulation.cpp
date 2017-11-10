#include "triangulation.h"

// constructors
Triangulation::Triangulation(int nElts, int nDirichlet, int nNeumann, int nPoints){

	this->nElts = nElts;
	this->nDirichlet = nDirichlet;
	this->nNeumann = nNeumann;

	xcoords = new double[nPoints];
	ycoords = new double[nPoints];

	// element array
    elements = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		elements[i] = new int[3];
	}

	// dirichlet edges
	dirichlet = new int*[nDirichlet];
	for(int i = 0; i < nDirichlet; i++){
		dirichlet[i] = new int[2];
	}

	// neumann edges
	neumann = new int*[nNeumann];
	for(int i = 0; i < nNeumann; i++){
		neumann[i] = new int[2];
	}

}

Triangulation::~Triangulation(){

	delete [] xcoords;
	delete [] ycoords;

	for(int i = 0; i < nElts; i++){
		delete[] elements[i];
	}	
	delete[] elements;

	for(int i = 0; i < nNeumann; i++){
		delete[] neumann[i];
	}	
	delete[] neumann;

	for(int i = 0; i < nDirichlet; i++){
		delete[] dirichlet[i];
	}

	delete[] dirichlet;

}

// enhance the geometric data structure
Triangulation::Enhance(){
/*
Output: Enhanced triangulation with:
	int **edges;
	int **edgebyele;
	int *diredge;
	int *neuedge;
	double *area;
	double **normal;
	int **orientation;
*/


}

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

// enhance the Triangulation 
void Triangulation::Enhance(){
/*
Output: Enhanced triangulation with:
	int **edges;
	int **edgebyele;
	int *diredge;
	int *neuedge;
	int *intedge; // interior edges
	double *area;
	double **normal;
	int **orientation;
*/

	// a priori, we don't know how many edges there are, but there are at most
	// 3*nElts edges, so start there and then copy the nonzero ones into the actual object 
	int **tmpEdges;
	tmpEdges = new int*[3*nElts];
	
	for(int i = 0; i < nElts; i++){
		tmpEdges[i] = new int[2];
		tmpEdges[i][0] = 0;
		tmpEdges[i][1] = 0;
	}

	for(int i = 0; i < nElts; i++){
	
		

	}

	
	// free the memory 
	for(int i = 0; i < nElts; i++){
		delete[] tmpEdges[i];
	}
	delete[] tmpEdges;

}

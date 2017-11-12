#include "triangulation.h"
#include <iostream>

// constructors
Triangulation::Triangulation(int nElts, int nDirichlet, int nNeumann, int nPoints){

	this->nElts = nElts;
	this->nDirichlet = nDirichlet;
	this->nNeumann = nNeumann;
	this->nPoints = nPoints;

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
 
	int **interiorEdges;
	interiorEdges = new int*[nPoints];
	
	for(int i = 0; i < nPoints; i++){
		interiorEdges[i] = new int[nPoints];
	}

	for(int i = 0; i < nPoints; i++){
		for(int j = 0; j < nPoints; j++){
			interiorEdges[i][j] = 0;
		}
	}

	for(int i = 0; i < nElts; i++){
		interiorEdges[elements[i][0]][elements[i][1]] = 1;  // first to second
		interiorEdges[elements[i][1]][elements[i][2]] = 1;  // second to third
		interiorEdges[elements[i][2]][elements[i][0]] = 1;  // third to first
	}

	if(nDirichlet>0){
		for(int i = 0; i < nDirichlet; i++){
			interiorEdges[dirichlet[i][0]][dirichlet[i][1]] = 0;	
		}
	}

	if(nNeumann>0){
		for(int i = 0; i < nNeumann; i++){
			interiorEdges[neumann[i][0]][neumann[i][1]] = 0;
		}
	}

	for(int i = 0; i < nPoints; i++){
		for(int j = 0; j < nPoints; j++){
			std::cout << interiorEdges[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	// free the memory 
	for(int i = 0; i < nElts; i++){
		delete[] interiorEdges[i];
	}

	delete[] interiorEdges;

}

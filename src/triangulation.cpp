#include "triangulation.h"
#include "utils.hpp"
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

	for(int i = 0; i < nEdges; i++){
		delete[] edges[i];
	}
	delete[] edges;

}

// enhance the Triangulation 
void Triangulation::Enhance(){
/*
Output: Enhanced triangulation with:
	int **edges;
	int **interiorEdges;
	int nEdges;
	int nInteriorEdges;
	int **edgebyele;
	int *diredge;
	int *neuedge;
	int *intedge; // interior edges
	double *area;
	double **normal;
	int **orientation;
*/

	makeEdges(); 

}

// clean up the constructor with some private methods
void Triangulation::makeEdges(){

	int **tmpEdges;
	tmpEdges = new int*[nPoints];
	
	for(int i = 0; i < nPoints; i++){
		tmpEdges[i] = new int[nPoints];
	}

	for(int i = 0; i < nPoints; i++){
		for(int j = 0; j < nPoints; j++){
			tmpEdges[i][j] = 0;
		}
	}

	for(int i = 0; i < nElts; i++){
		tmpEdges[elements[i][0]][elements[i][1]] = 1;  // first to second
		tmpEdges[elements[i][1]][elements[i][2]] = 1;  // second to third
		tmpEdges[elements[i][2]][elements[i][0]] = 1;  // third to first
	}

	if(nDirichlet>0){
		for(int i = 0; i < nDirichlet; i++){
			tmpEdges[dirichlet[i][0]][dirichlet[i][1]] = 0;	
		}
	}

	if(nNeumann>0){
		for(int i = 0; i < nNeumann; i++){
			tmpEdges[neumann[i][0]][neumann[i][1]] = 0;
		}
	}

	for(int i = 0; i < nPoints; i++){
		for(int j = 0; j < i; j++){
			tmpEdges[i][j] = 0;  // delete duplicates in the lower half
		}
	}

	nInteriorEdges = 0;
	for(int i = 0; i < nPoints; i++){
		for(int j = 0; j < nPoints; j++){
			if(tmpEdges[i][j] > 0)
				nInteriorEdges++;
		}	
	}

	nEdges = nInteriorEdges + nNeumann + nDirichlet;

	edges = new int*[nEdges];
 	for(int i = 0; i < nEdges; i++){
		edges[i] = new int[2];
	}

	for(int i = 0; i < nEdges; i++){
		for(int j = 0; j < 2; j++){
			edges[i][j] = 0;
		}
	}
	
	// fill in the edge array
	int edgecount = 0;
	for(int i = 0; i < nPoints; i++){
		for(int j = i; j < nPoints; j++){
			if(tmpEdges[i][j]){
				edges[edgecount][0] = i;
				edges[edgecount][1] = j;
				edgecount++;
			}
		}
	}

	for(int i = 0; i < nDirichlet; i++){
		edges[edgecount][0] = dirichlet[i][0];
		edges[edgecount][1] = dirichlet[i][1];
		edgecount++;
	}

	for(int i = 0; i  < nNeumann; i++){
		edges[edgecount][0] = neumann[i][0];
		edges[edgecount][1] = neumann[i][1];
		edgecount++;
	}

	printMatrix(edges, nEdges, 2);
	
	for(int i = 0; i < nPoints; i++){
		delete[] tmpEdges[i];
	}
	delete[] tmpEdges;

}


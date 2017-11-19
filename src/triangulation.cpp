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

	enhanced = false;

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

	for(int i = 0; i < nElts; i++){
		delete[] edgebyele[i];
	}
	delete[] edgebyele;

	delete[] diredge;
	delete[] neuedge;

	delete[] area;

	for(int i = 0; i < nElts; i++){
		delete[] orientation[i];
	}
	delete[] orientation;

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
	bool enhanced;
*/

	// don't double enhance - will break things
	if(enhanced){
		// break or except?
	}

	// some methods to clean up the enhance functionality
	makeEdges(); 
	getEdgeByElement();

	// now get lists of dir and neu edges
	diredge = new int[nDirichlet];
	for(int i = 0; i < nDirichlet; i++){
		diredge[i] = nInteriorEdges + i;
	}
	
	neuedge = new int[nNeumann];
	for(int i = 0; i < nNeumann; i++){
		neuedge[i] = nInteriorEdges + nDirichlet + i;
	}

	getAreas();

	// get orientations
	orientation = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		orientation[i] = new int[3];
	}	

	zeroMatrix(orientation, nElts, 3);	

	int **firstnode = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		firstnode[i] = new int[3];
	}

	// restack edgebyele (this is wasteful)
	int *tmp = new int[nElts*3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < nElts; j++){
			tmp[j + 2*i] = edgebyele[j][i];
		}
	}

	for(int i = 0; i < nElts; i++){
		for(int j = 0; j < 3; j++){
			firstnode[i][j] = edges[tmp[i+2*j]][0];
		}
	}

	for(int i = 0; i < nElts; i++){
		for(int j = 0; j < 3; j++){
			if(elements[i][j] == firstnode[i][j]){
				orientation[i][j] = 1;
			}
			else{
				orientation[i][j] = -1;
			}
		}
	}
	
	delete[] tmp;
	
	for(int i = 0; i < nElts; i++){
		delete[] firstnode[i];
	}
	delete[] firstnode;

	enhanced = true;

}

// clean up the constructor with some private methods
void Triangulation::makeEdges(){

	int **tmpEdges;
	tmpEdges = new int*[nPoints];
	
	for(int i = 0; i < nPoints; i++){
		tmpEdges[i] = new int[nPoints];
	}

	zeroMatrix(tmpEdges, nPoints, nPoints);
	
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

	zeroMatrix(edges, nEdges,2);
	
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
	
	for(int i = 0; i < nPoints; i++){
		delete[] tmpEdges[i];
	}
	delete[] tmpEdges;

}

void Triangulation::getEdgeByElement(){

	int **conn;
	conn = new int*[nEdges];
	for(int i = 0; i < nEdges; i++){
		conn[i] = new int[nEdges];
	}

	zeroMatrix(conn, nEdges, nEdges);

	for(int i = 0; i < nEdges; i++){
		conn[edges[i][0]][edges[i][1]] = i;
	}
		
	// can't transpose in place - have aliasing
	int **connt;
	connt = new int*[nEdges];
	for(int i = 0; i < nEdges; i++){
		connt[i] = new int[nEdges];
	}

	zeroMatrix(connt, nEdges, nEdges);
	
	for(int i = 0; i < nEdges; i++){
		for(int j = 0; j < nEdges; j++){
			connt[i][j] = conn[j][i];			
		}
	}
	
	for(int i = 0; i < nEdges; i++){
		for(int j = 0; j < nEdges; j++){
			conn[i][j] += connt[i][j];
		}
	}

	edgebyele = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		edgebyele[i] = new int[3];
	}

	zeroMatrix(edgebyele, nElts, 3);
	
	int *n = new int[3];
	
	for(int i = 0; i < nElts; i++){
		for(int j = 0; j < 3; j++){
			n[j] = elements[i][j];
		}
		edgebyele[i][0] = conn[n[0]][n[1]];
		edgebyele[i][1] = conn[n[1]][n[2]];
		edgebyele[i][2] = conn[n[2]][n[0]];
	}

	delete[] n;

	for(int i = 0; i < nEdges; i++){
		delete[] connt[i];
	}
	delete[] connt;

	for(int i = 0; i < nEdges; i++){
		delete[] conn[i];
	}
	delete[] conn;

}

void Triangulation::getAreas(){

	area = new double[nElts];

	for(int i = 0; i < nElts; i++){
		area[i] = (xcoords[elements[i][1]]-xcoords[elements[i][0]])
				 *(ycoords[elements[i][2]]-ycoords[elements[i][0]])
				 -(ycoords[elements[i][1]]-ycoords[elements[i][0]])
				 *(xcoords[elements[i][2]]-xcoords[elements[i][0]]);
		area[i] *= 0.5;
	}

}

// need to be wary of aliasing and memleaks when overwriting object fields!
void Triangulation::RedRefinement(){

	// check if the triangulation has been enhanced (if so, delete some of the enhanced fields)
	if(enhanced){

		delete[] area;

		for(int i = 0; i < nElts; i++){
			delete[] orientation[i];
		}
		delete[] orientation;

		enhanced = false;

	}
	else{

		makeEdges();
		getEdgeByElement();

	}

	// renumber edges and make new mesh	
	for(int i = 0; i < nElts; i++){
		for(int j = 0; j < 3; j++){
			edgebyele[i][j] += nPoints; // this should be deleted when we're done
		}
	} 

	// store these before overwriting
	double *oldXCoords = new double[nPoints];
	double *oldYCoords = new double[nPoints];

	for(int i = 0; i < nPoints; i++){
		oldXCoords[i] = xcoords[i];
		oldYCoords[i] = ycoords[i];
	}

	delete[] xcoords;
	delete[] ycoords;

	// every old point is still part of the mesh, and every edge gets bisected
	xcoords = new double[nPoints + nEdges];
	ycoords = new double[nPoints + nEdges];

	// fill in old points first
	for(int i = 0; i < nPoints; i++){
		xcoords[i] = oldXCoords[i];
		ycoords[i] = oldYCoords[i];
	}

	// now put the new points in
	for(int i = 0; i < nEdges; i++){
		xcoords[nPoints+i] = 0.5*xcoords[edges[i][0]] + 0.5*xcoords[edges[i][1]];
		ycoords[nPoints+i] = 0.5*ycoords[edges[i][0]] + 0.5*ycoords[edges[i][1]];
	}

	nPoints += nEdges;

	// do the local thing in two steps
	int ** tmp;
	tmp = new int*[nElts];
	for(int i = 0; i < nElts; i++){
		tmp[i] = new int[6];
	}

	for(int i = 0; i < nElts; i++){
		tmp[i][0] = elements[i][0];
		tmp[i][1] = elements[i][1];
		tmp[i][2] = elements[i][2];
		tmp[i][3] = edgebyele[i][0];
		tmp[i][4] = edgebyele[i][1];
		tmp[i][5] = edgebyele[i][2];
	}
	
	// note that this is already transposed
	int **tmp2;
	tmp2 = new int*[12];
	for(int i = 0; i < nElts; i++){
		tmp2[i] = new int[nElts];
	}		

	for(int i = 0; i < 12; i++){
		delete[] tmp2[i];
	}	
	delete[] tmp2;

	for(int i = 0; i < nElts; i++){
		delete[] tmp[i];
	}
	delete[] tmp;	

	delete[] oldXCoords;
	delete[] oldYCoords;

	// delete old edgebyele
	for(int i = 0; i < nElts; i++){
		delete[] edgebyele[i];
	}

	delete[] edgebyele;
	
}

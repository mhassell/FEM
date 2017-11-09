#include <vector>

#include "triangulation.h"

// constructors
Triangulation::Triangulation(int numElts, int numDirichlet, int numNeumann, int nPoints){

	nElts = numElts;
	nDirichlet = numDirichlet;
	nNeumann = numNeumann;

	std::vector<double> xcoords;
	std::vector<double> ycoords;

	// element array
	double elements[nElts][3];

	// dirichlet edges


	// neumann edges

}

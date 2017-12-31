#include "triangulation.h"
#include "utils.hpp"

#include <iostream>

int main()
{

	Triangulation T(2,2,2,4);

	T.xcoords[0] = 0.0;
	T.xcoords[1] = 1.0;
	T.xcoords[2] = 0.8;
	T.xcoords[3] = 0.2;

	T.ycoords[0] = 0.0;
	T.ycoords[1] = 0.0;
	T.ycoords[2] = 0.7;
	T.ycoords[3] = 1.0;

	T.elements[0][0] = 0;
	T.elements[0][1] = 1;
	T.elements[0][2] = 3;

	T.elements[1][0] = 1;
	T.elements[1][1] = 2;
	T.elements[1][2] = 3;

	T.dirichlet[0][0] = 0;
	T.dirichlet[0][1] = 1;
	T.dirichlet[1][0] = 1;
	T.dirichlet[1][1] = 2;

	T.neumann[0][0] = 2;
	T.neumann[0][1] = 3;
	T.neumann[1][0] = 3;
	T.neumann[1][1] = 0;

	// test enhancement
	T.Enhance();

	// test refinement
	T.RedRefinement();

	std::cout << "xcoords: " << std::endl;
	printMatrix(T.xcoords, T.nPoints);

	std::cout << "ycoords: " << std::endl;
	printMatrix(T.ycoords, T.nPoints);

	std::cout << "elements: " << std::endl;
	printMatrix(T.elements, T.nElts, 3);

	std::cout << "dirichlet: " << std::endl;
	printMatrix(T.dirichlet, T.nDirichlet, 2);

	std::cout << "neumann: " << std::endl;
	printMatrix(T.neumann, T.nNeumann, 2);

	std::cout << "edges: " << std::endl;
	printMatrix(T.edges, T.nEdges, 2);

	std::cout << "edgebyele: " << std::endl;
	printMatrix(T.edgebyele, T.nElts,3);

	std::cout << "diredge: " << std::endl;
	printMatrix(T.diredge, T.nDirichlet);

	std::cout << "neuedge: " << std::endl;
	printMatrix(T.neuedge, T.nNeumann);

	std::cout << "intedge: " << std::endl;
	printMatrix(T.intedge, T.nInteriorEdges);

	std::cout << "area: " << std::endl;
	printMatrix(T.area, T.nElts);

	std::cout << "orientation: " << std::endl;
	printMatrix(T.orientation, T.nElts, 3);


}


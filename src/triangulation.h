#ifndef _TRIANGULATION_H_
#define _TRIANGULATION_H_

#include <vector>

class Triangulation{

	public:
		 // attributes
		 int nElts;
		 int nDirichlet;
		 int nNeumann;
		 
		 std::vector<double> xcoords;
		 std::vector<double> ycoords;
		 int **elements;   // nElts x 3
		 int **dirichlet;  // nDirichlet x 2
		 int **neumann;	   // nNeumann x 2

		//methods
		 void RedRefinement();
		 void Enhance();

		// constructors
		 Triangulation(int,int,int,int);
			 
 };

#endif // _TRIANGULATION_H_


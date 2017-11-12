#ifndef _TRIANGULATION_H_
#define _TRIANGULATION_H_

class Triangulation{

	public:
		// attributes
		int nElts;
		int nDirichlet;
		int nNeumann;
		int nPoints;
		 
		// basic fields
		double* xcoords;
		double* ycoords;
		int **elements;   // nElts x 3
		int **dirichlet;  // nDirichlet x 2
		int **neumann;	   // nNeumann x 2

		// enhanced fields
		int **edges;
		int **edgebyele;
		int *diredge;
		int *neuedge;
		int *intedge;
		double *area;
		double **normal;
		int **orientation;	 			

		//methods
		void RedRefinement();
		void Enhance();

		// constructors
		Triangulation(int,int,int,int);
			 
		// destructor
		~Triangulation();

 };

#endif // _TRIANGULATION_H_


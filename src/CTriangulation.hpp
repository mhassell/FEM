#ifndef _TRIANGULATION_H_
#define _TRIANGULATION_H_

class CTriangulation{

	public:
		// attributes
		int nElts;
		int nDirichlet;
		int nNeumann;
		int nPoints;
		int nEdges;
		int nInteriorEdges;
		 
		// basic fields
		double* xcoords;
		double* ycoords;
		int **elements;   	// nElts x 3
		int **dirichlet;  	// nDirichlet x 2
		int **neumann;	   	// nNeumann x 2

		// enhanced fields
		int **edges;
		int **edgebyele;
		int *diredge;
		int *neuedge;
		int *intedge;
		double *area;
		int **orientation;	 			

		//methods
		void RedRefinement();
		void Enhance();

		// constructors
		CTriangulation(int,int,int,int);
			 
		// destructor
		~TCriangulation();

	private:
		void makeEdges();
		void getEdgeByElement();
		void getAreas();
		bool enhanced;
		void unEnhance();

 };

#endif // _TRIANGULATION_H_


/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * triangulation.cpp
 * Copyright (C) 2017  <>
 *
 * FEM is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * FEM is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Eigen/Dense>
#include "triangulation.h"

class Triangulation{

	public:
		 // attributes
		 int nElts;
		 int nDirichlet;
		 int nNeumann;
		 
		 double *xcoords;
		 double *ycoords;
		 int **elements;   // nElts x 3
		 int **dirichlet;  // nDirichlet x 2
		 int **neumann;	   // nNeumann x 2

		//methods
		 RedRefinement();
		 Enhance();

		// constructors
		 Triangulation();

		// destructor
		 ~Triangulation()
			 
 }

// constructors
Triangulation::Triangulation(){

}

// destructor

Triangulation::~Triangulation(){

	delete [] xcoords;
	delete [] ycoords;

	for(int i = 0; i < nElts; i++){
		delete [] elements[i];
	}

	delete [] elements;

	for(int i = 0; i < nDirichlet; i++){
		delete [] dirichlet[i];
	}
	
	delete [] dirichlet;

	for(int i = 0; i < nNeumann; i++){
		delete [] neumann[i];
	}
	
	delete [] neumann;
	
}


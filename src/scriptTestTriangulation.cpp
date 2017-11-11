#include "triangulation.h"

#include <iostream>

int main()
{

	Triangulation T(5,4,3,2);

	// test nElts
	std::cout << T.nElts << std::endl;

	// test xcoords
	for(int i = 0; i < 2; i++){
		T.xcoords[i] = (double) i;
	}
	for(int i = 0; i < 2; i++){
		std::cout << T.xcoords[i] << std::endl;
	}

	// test enhancement
	T.Enhance();
	
	
}


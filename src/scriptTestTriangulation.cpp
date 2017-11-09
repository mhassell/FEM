#include "triangulation.h"

#include <iostream>

int main()
{

	Triangulation T(5,4,3,2);

	std::cout << T.nElts << std::endl;

	for(int i = 0; i < 5; i++){
		T.xcoords.push_back((double)i);
	}

	for(int i = 0; i < 4; i++){

		T.elements[i][0] = 0;
		T.elements[i][1] = 1;
		T.elements[i][2] = 2;

	}

	std::cout << "here" << std::endl;

}


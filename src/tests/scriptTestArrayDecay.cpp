// testing decay of arrays to a pointer

#include <iostream>

void byValue(int a[]){

	std::cout << sizeof(a) << std::endl;

}

void byPointer(int *a){

	std::cout << sizeof(*a) << std::endl;

}

int main(){

	int a[] = {1, 2, 3, 4, 5, 6};

	std::cout << "By value" << std::endl;
	byValue(a);

	std::cout << "By pointer" << std::endl;
	byPointer(a);

	std::cout << "sizeof(int*)" << std::endl;
	std::cout << sizeof(int*) << std::endl;

	std::cout << "sizeof(int)" << std::endl;
	std::cout << sizeof(int) << std::endl;

}

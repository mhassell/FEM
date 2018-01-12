// playing with lambda expressions

#include <iostream>
#include <cmath>

int main(){

	auto lam = [](double x, double y){return 1+pow(x,2)+pow(y,2);};

	std::cout << lam(1.0,1.0) << std::endl;

}
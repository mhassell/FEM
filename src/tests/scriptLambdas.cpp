// playing with lambda expressions

#include <iostream>
#include <functional>
#include <cmath>

void passFunction(std::function<double(double,double)> f){

	std::cout << f(2,3) << std::endl;

}

int main(){

	auto lam = [](double x, double y){return 1+pow(x,2)+pow(y,2);};

	std::cout << lam(1.0,1.0) << std::endl;

	std::function<double(double,double)> f = lam;

	std::cout << f(1,1) << std::endl;

	passFunction(f);

}
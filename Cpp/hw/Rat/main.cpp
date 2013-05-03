#include <iostream>
#include <cmath>
using namespace std;

#include "Rat.h"

int main() {
	Rat rationalOne, rationalTwo;
	
	rationalOne.input();
	cout << "The first rational number is ";
	rationalOne.output();
	cout << ".\n";
	
	rationalTwo.input();
	cout << "The second rational number is ";
	rationalTwo.output();
	cout << ".\n";
	
	Rat sum = rationalOne + rationalTwo;
		
	rationalOne.output();
	cout << " + ";
	rationalTwo.output();
	cout << " = ";
	sum.output();
	cout << ".\n";
	
	Rat dif = rationalOne - rationalTwo;
		
	rationalOne.output();
	cout << " - ";
	rationalTwo.output();
	cout << " = ";
	dif.output();
	cout << ".\n";
	
	Rat prod = rationalOne * rationalTwo;
	rationalOne.output();
	cout << " * ";
	rationalTwo.output();
	cout << " = ";
	prod.output();
	cout << ".\n";	

	return 0;	
}
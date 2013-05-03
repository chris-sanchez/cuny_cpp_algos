#include <iostream>
#include <cmath>
#include "Rat.h"
using namespace std;

//creates a rational number from user input
void Rat::input(){
	cout << "Enter the numerator\n";
	cin >> num;
	cout << "Enter the denominator\n";
	cin >> denom;
	
	if(denom == 0){
		exit(1);
	}
	else if (denom<0){
		denom = -denom;
		num = -num;
	}
}

//displays a rational number
void Rat::output() const{
	if(denom==1){
		cout << num;
	}
	else{
		cout << num << "/" << denom;
	}
}

//takes two integers and returns their greatest common devisor
int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	a = a%b;
	gcd(b, a);
}

//takes two integers and returns their least common multiple
int lcm(int a, int b){
	return a*b/gcd(a,b);
}

//takes a rational number and computes its reduced form
const Rat Rat::reduce() const{
	int greatest = gcd(static_cast<int>(abs(num)), denom);
	
	Rat rr(num/greatest, denom/greatest);
	
	return rr;
}

//accepts rational numbers and returns their sum
const Rat operator +(const Rat& r1, const Rat& r2){
	int denom = lcm(r1.getDenom(), r2.getDenom());
	int num = (r1.getNum()*denom/r1.getDenom()) + (r2.getNum()*denom/r2.getDenom());

	Rat sum = Rat(num, denom);
	
	return sum.reduce();
}

//accepts rational numbers and returns their difference
const Rat operator -(const Rat& r1, const Rat& r2){	
	int denom = lcm(r1.getDenom(), r2.getDenom());
	int num = (r1.getNum()*denom/r1.getDenom()) - (r2.getNum()*denom/r2.getDenom());

	Rat dif = Rat(num, denom);
	
	return dif.reduce();
}

//accepts rational numbers and returns their product
const Rat operator *(const Rat& r1, const Rat& r2){	
	int denom = r1.getDenom() * r2.getDenom();
	int num = r1.getNum() * r2.getNum();

	Rat prod = Rat(num, denom);
	
	return prod.reduce();
}

//constructor
Rat::Rat(int n, int d){
	num = n;
	denom = d;
	
	if(denom==0){
		cout<<"Error"<<"\n";
		exit(1);
	}
	
	if(denom<0){
		denom = - denom;
		num = - num;
	}
}

Rat::Rat(int n){
	num = n;
	denom = 1;
}

Rat::Rat(){
	num = 0;
	denom = 1;
}

//accesors
int Rat::getNum() const{
	return num;
}

int Rat::getDenom() const{
	return denom;
}

//setters
void Rat::setNum(int n){
	num = n;
}

void Rat::setDenom(int d){
	denom = d;
	if(d==0){
		exit(1);
	}
	else if(d<0){
		d = -d;
		num = -num;
	}
}

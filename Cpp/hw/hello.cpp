#include <iostream>
#include <cmath>
using namespace std;


//creates a class named Rat which holds a rational number in the form of two ints
class Rat{
	private:
	int num;
	int denom;
	
	public:
	Rat(int n, int d);			//
	Rat(int n);					//
	Rat();						//

	const Rat reduce() const;	//
	
	void output() const;		//
	Rat input();				//
	
	int getNum() const;			//accessors
	int getDenom() const;		//
	void setNum(int n);			//mutators
	void setDenom(int d);		//
	
	const Rat operator+(const Rat& other) const;	//
	const Rat operator-(const Rat& other) const;	//
	const Rat operator-() const;					//
	const Rat operator*(const Rat& other) const;
	const Rat operator/(const Rat& other) const;
	
	const int operator[](int index) const;
	
	bool operator==(const Rat& other) const;		//
	bool operator!=(const Rat& other) const;		//
	bool operator<(const Rat& other) const;			//
	bool operator>(const Rat& other) const;			//
	bool operator<=(const Rat& other) const;		//
	bool operator>=(const Rat& other) const;		//
	
	friend ostream& operator<<(ostream& out, const Rat& r);		//
	friend istream& operator>>(istream& in, Rat& r);			//
};

Rat add(const Rat& r1, const Rat& r2);


int main() {
	Rat rationalOne, rationalTwo;
	
	cin>>rationalOne;
	cout<<rationalOne<<"\n";
	
	cin>>rationalTwo;
	cout<<rationalTwo<<"\n";
	
	Rat sum = add(rationalOne, rationalTwo);
		
	cout << rationalOne;
	cout << " + ";
	cout << rationalTwo;
	cout << " = ";
	cout << sum;
	cout << ".\n";

	return 0;	
}

ostream& operator<<(ostream& out, const Rat& r){
	out<<r.num<<"/"
	   <<r.denom;
	return out;
}

istream& operator>>(istream& in, Rat& r){
	cout<<"num: ";
	int n;
	in>>n;
	r.num=n;
	
	cout<<"denom: ";
	int d;
	in>>d;
	if(d==0){
		cout<<"Denominator cannot be zero\n";
		exit(1);
	}
	else if(d<0){
		r.num = -r.num;
		r.denom = -d;
	}
	else{
		r.denom = d;
	}
	
	return in;
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
Rat add(const Rat& r1, const Rat& r2){
	Rat sum;
	
	int denom = lcm(r1.getDenom(), r2.getDenom());
	int num = (r1.getNum()*denom/r1.getDenom()) + (r2.getNum()*denom/r2.getDenom());

	sum.setDenom(denom);
	sum.setNum(num);
	
	return sum.reduce();
}

//arithmatic operator overrides
const Rat Rat::operator+(const Rat& other) const{
	Rat sum;
	int sumDenom = lcm(denom, other.denom);
	int sumNum = (num*sumDenom/denom) + (other.num*sumDenom/other.denom);
	
	sum.denom = sumDenom;
	sum.num = sumNum;
	
	return sum.reduce();
}

const Rat Rat::operator-(const Rat& other) const{
	Rat dif;
	int difDenom = lcm(denom, other.denom);
	int difNum = (num*difDenom/denom) - (other.num*difDenom/other.denom);
	
	dif.denom = difDenom;
	dif.num = difNum;
	
	return dif.reduce();
}

const Rat Rat::operator-() const{
	Rat neg;
	neg.num = -num;
	neg.denom = denom;
	
	return neg;
}

const Rat Rat::operator*(const Rat& other) const{
	Rat product;
	
	product.num = num*other.num;
	product.denom = denom*other.denom;
	
	return product;
}

const Rat Rat::operator/(const Rat& other) const{
	Rat quotent;
	
	quotent.num = num*other.denom;
	quotent.denom = denom*other.num;
	
	return quotent;
}

//index operator override
const int Rat::operator[](int index) const{
	if(index < 1 || index > 2){
		cout << "The index " << index << "is out of bounds!\n";
		exit(1);
	}
	else if(index == 1){
		return num;
	}
	else if(index == 2){
		return denom;
	}
	
}

//comparitor operator overrides
bool Rat::operator==(const Rat& other) const{
	return (num*other.denom == other.num*denom);
}

bool Rat::operator!=(const Rat& other) const{
	return (num*other.denom != other.num*denom);
}

bool Rat::operator<(const Rat& other) const{
	return (num*other.denom < other.num*denom);
}

bool Rat::operator>(const Rat& other) const{
	return (num*other.denom > other.num*denom);
}

bool Rat::operator<=(const Rat& other) const{
	return !(num*other.denom > other.num*denom);
}

bool Rat::operator>=(const Rat& other) const{
	return !(num*other.denom < other.num*denom);
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

//input and output
void Rat::output() const{
	cout << num << "/" << denom;
}

Rat Rat::input(){
	int n, d;
	cout << "num: ";
	cin >> n;
	cout << "denom: ";
	cin >> d;
	
	return Rat(n,d);
}
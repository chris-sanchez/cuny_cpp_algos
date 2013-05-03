#include <iostream>
#include <cmath>
using namespace std;

#pragma mark Exercise 1
/*Prints even numbers between 1 and 100*/
void printEvens(){
	cout << "The even numbers between 1 and 100 are\n";
	for(int n=1; n<100; n++){
		if(n%2 == 0){
			cout << n << ", ";
		}
	}
	cout << "100\n";
}

/*Calculates the sums of all multiples of 2 and 7 under 1000*/
void printSum(){
	int sum = 0;
	for(int n=1; n<1000; n++){
		if(n%2 == 0){
			sum+=n;
		}
		else if(n%7 == 0){
			sum+=n;
		}
	}
	cout << "The sum of all multiples of 2 and 7 under 1000 is " << sum << ".\n";
}

/*Prints the first 30 Fibbonachi Numbers*/
void printFib(){
	int n_0 = 1;
	int n_1 = 1;
	int n_hold = 1;
	
	cout << "The first 30 Fibonacci numbers are 0, 1, ";
	
	for(int i=0; i<29; i++){
		cout << n_1;
		if(i<28){cout << ", ";}
		else{cout << ".\n";}
		
		n_hold = n_1;
		n_1 = n_0+n_hold;
		n_0 = n_hold;
	}
}

#pragma mark Exercise 2
/*The function minE takes an array of integers and returns the smallest integer in the array*/
int minE(int array[], int size){
	int min = array[0];
	for(int n=0; n<size; n++){
		if(min>array[n]){
			min = array[n];
		}
	}
	return min;
}

/*The function rev takes an array of integers and reverses the array*/
int rev(int array[], int size){
	int temp[size];
	for(int i=0; i<size; i++){
		temp[i] = array[size - 1 - i];
	}
	for(int i=0; i<size; i++){
		array[i] = temp[i];
	}
}

/*The function isDistinct takes an array of integers and returns true iff the array contains no duplicates*/
bool isDistinct(int array[], int size){
	for(int m=0; m<size; m++){
		for(int n=m+1; n<size; n++){
			if(array[m] == array[n]){
				return false;
			}
		}
	}
	
	return true;
}

#pragma mark Exercise 3
/*The function swapHalves takes an array and swaps the first and second halves of that array*/
void swapHalves(int a[], int size){
	int temp;
	
	for(int n=0; n<size/2; n++){
		temp = a[n];
		a[n] = a[size-(size/2)+n];
		a[size-(size/2)+n] = temp;
	}
}

/*isSubsequence takes two arrays and tests if the second is a subsequence of the first.  it returns true if it is*/
bool isSubsequence(int a[], int sizeA, int b[], int sizeB){
	int counter = 0;
	for(int n=0; n<sizeA; n++){
		cout << "n=" << n << "\n";
		if(a[n]==b[counter]){
			counter++;
		}
		if(counter==sizeB){
			return true;
		}
	}
	return false;
}

#pragma mark Exercise 3 part two
/*the class graph has the following properties
**two doubles that represent a point on the (x,y) plain
**a default constctor that creats a point at the origin
**a two argument constructor setting x and y to the arguments
**two set methods for each data variable
**two get methods for each data variable
**a distance method that returns the distance between two points
**a midpoint method that returns the midpoint of two points*/
class Graph{
	private:
	double x;
	double y;
	
	public:
	Graph();
	Graph(double x, double y);
	
	void setX(double x);
	void setY(double y);
	
	double getX();
	double getY();
	
	double distance(Graph p);
	Graph midpoint(Graph p);
};

//default constructor of Graph class.  point at origin
Graph::Graph(){
	x = 0.0;
	y = 0.0;
}

Graph::Graph(double xVar, double yVar){
	x = xVar;
	y = yVar;
}

void Graph::setX(double xVar){
	x = xVar;
}

void Graph::setY(double yVar){
	y = yVar;
}

double Graph::getX(){
	return x;
}

double Graph::getY(){
	return y;
}

double Graph::distance(Graph p){
	double xDir = x - p.getX();
	double yDir = y - p.getY();
	return sqrt(xDir*xDir + yDir*yDir);
}

Graph Graph::midpoint(Graph p){
	double xDir = (p.getX() + x)/2;
	double yDir = (p.getY() + y)/2;
	
	Graph midpoint(xDir, yDir);
	return midpoint;
}

/*the class book has the following properties
**strings containing the title and author
**an int for the year it was published
**a float for the price of the book
**a default and four argument constructor
**get and set methods for each variable
**a compare method that compares prices
**a toString method that outputs contents of the book*/
class Book{
	private:
	string title;
	string author;
	int year;
	float price;
	
	public:
	Book();
	Book(string bookTitle, string bookAuthor, int bookYear, float bookPrice);
	
	void setTitle(string bookTitle);
	void setAuthor(string bookAuthor);
	void setYear(int bookYear);
	void setPrice(float bookPrice);
	
	string getTitle();
	string getAuthor();
	int getYear();
	float getPrice();
	
	int comparePrice(Book b);
	
	void toString();
};

Book::Book(){
	title = " ";
	author = " ";
	year = 0;
	price = 0.0;
}

Book::Book(string bookTitle, string bookAuthor, int bookYear, float bookPrice){
	title = bookTitle;
	author = bookAuthor;
	year = bookYear;
	price = bookPrice;
}	

void Book::setTitle(string bookTitle){
	title = bookTitle;
}

void Book::setAuthor(string bookAuthor){
	author = bookAuthor;
}

void Book::setYear(int bookYear){
	year = bookYear;
}

void Book::setPrice(float bookPrice){
	price = bookPrice;
}
	
string Book::getTitle(){
	return title;
}

string Book::getAuthor(){
	return author;
}

int Book::getYear(){
	return year;
}

float Book::getPrice(){
	return price;
}	

int Book::comparePrice(Book b){
	if(price==b.price){
		return 0;
	}
	else if(price>b.price){
		return 1;
	}
	else{
		return -1;
	}
}
	
void Book::toString(){
	cout << "The book \""
		<< title
		<< "\" by "
		<< author
		<< " was first printed in "
		<< year
		<< " and costs $"
		<< price
		<< ".\n";
}

#pragma mark Exercise 4 basic sorts
//selection sort
void selectionSort(int a[], int length){
	int temp;
	int iTemp;
	for(int m=0; m<length; m++){
		temp = a[m];
		iTemp = m;
		for(int n=m; n<length; n++){
			if(temp>a[n]){
				temp = a[n];
				iTemp = n;
			}
		a[iTemp] = a[m];
		a[m] = temp;
		}
	}

}

//insertion sort
void insertionSort(int a[], int length){
	int temp;
	
	for(int m=0; m<length; m++){
		for(int n=m; n==0; n--){
			if(a[n]>a[m]){
				temp = a[m];
				a[m] = a[n];
				a[n] = a[m];
			}
		}
	}
}

//bubble sort
void bubbleSort(int a[], int length){
	bool bubble = true;
	int temp;
	
	while(bubble){
		bubble = false;
		for(int m=0; m<length-1; m++){
			if(a[m]>a[m+1]){
				bubble = true;
				temp = a[m+1];
				a[m+1] = a[m];
				a[m] = temp;
			}
		}
	}

}


int main(){
	cout << "hello" << "\n";
	
	/*
	Graph point1(0,3);
	Graph point2(4,0);
		
	cout << "point 1 is at (" << point1.getX() << ", " << point1.getY() << ").\n";
	cout << "point 2 is at (" << point2.getX() << ", " << point2.getY() << ").\n";
	
	cout << "The distance between them is " << point1.distance(point2) << ".\n";
	
	cout << "Their midpoint is at (" << point1.midpoint(point2).getX() << ", " << point1.midpoint(point2).getY() << ")\n";
	*/
	
	/*
	Book book1("White Teeth", "Zadie Smith", 2002, 19.95);
	Book book2("Cat's Craddle", "Kurt Vonnegut", 1972, 19.95);
	
	book1.setAuthor("Z. Smith");
	cout << book2.comparePrice(book1) << "\n";
	
	book1.toString();
	book2.toString();
	
	
	int a[6] = {23,10,213,36,12,1};
	bubbleSort(a, 6);
	
	cout << a[1] << "\n";*/
	int q = 5;
	int *p = &q;
	q = 3+ p;
	cout << p;
	
	return 0;
}
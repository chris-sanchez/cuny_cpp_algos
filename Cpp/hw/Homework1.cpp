#include <iostream>
using namespace std;

/*isPrime takes an integer i and returns true iff i is prime*/
bool isPrime(int i){
	for(int n=2; n<i; n++){
		if(i%n == 0){
			return false;
		}
	}
	return true;
}

/*listPrimes scans in a number and then prints out all of the prime numbers less than it*/
void listPrimes(){
	int i;
	cout << "enter a number, and i'll print out all the primes less than or equal to that number!\n";
	cin >> i;
	for(int n = 1; n <= i; n++){
		if(isPrime(n)){
			cout << n << " is prime! \n";
		}
	}
}

/*isPerfect scans in a number and then responds to weather or not the number is perfect*/
void isPerfect(){
	int i;
	int sum = 0;
	cout << "enter a number, and i'll tell you if it is perfect!\n";
	cin >> i;
	
	for(int n=1; n < i; n++){
		if(i%n == 0){
			sum += n;
		}
	}
	if(sum==i){
		cout << "its perfect!\n";
	}
	else{
		cout << "its not perfect!\n";
	}
	
}

/*isLeapYear scans for a number.  It tells the user if it is a leap year*/
void isLeapYear(){
	int year;
	cout << "Enter a year, and I'll let you know if its a leap year!\n";
	cin >> year;
	
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				cout << year << " is a leap year!\n";
			}
			else{
				cout << year << " isn't a leap year!\n";
			}
		}
		else{
			cout << year << " is a leap year!\n";
		}
	}
	else{
		cout << year << " isn't a leap year!\n";
	}
}

/*reverseInteger scans for a positive number and prints out its reverse (i.e. 123 -> 321)
**reverseInteger terminates when the user enters a negative number*/
void reverseInteger(){
	long i;
	cout << "Enter a positive integer and I will reverse it! \nIf you wish to terminate, enter a negative number!\n";
	cin >> i;
	
	if(i<0)
	{
		return;
	}
	
	int digits = 1;
	int counterUp = 1;
		
	while((i/counterUp)>9){
		counterUp = 10 * counterUp;
		digits ++;
	}
	
	long reverseI = 0;
	long remainder = 0;
	long counterDown = 10;
	int n = 0;
	int add;
	
	while(n<digits){
		add = (i%counterDown - remainder) * 10 * counterUp / counterDown;
		remainder += i%counterDown - remainder;
		reverseI += add;
		counterDown *= 10;
		counterUp /= 10;
		n ++;
	}
	cout << i << " reversed is " << reverseI << "\n";
	
	reverseInteger();
}

int main() {
	cout << "hello!" << "\n";
	listPrimes();
	isPerfect();
	isLeapYear();
	reverseInteger();
	return 0;
}
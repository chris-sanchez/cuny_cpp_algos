/*
 *	main.cpp contains the definitions of operator overrides in the Date class
 *	main.cpp also contains the test driver for the program
 * 
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#include "Student.h"
#include "Roster.h"
#include "Date.h"

//overide << and >> operators for the date class
ostream& operator<<(ostream& out, const Date& theDate){
	out<<Date::toString(theDate)<<"\n";
	return out;
}
istream& operator>>(istream& in, Date& theDate){
	int day, month, year;
	cout<<"Enter the day(int): ";
	in>>day;
	cout<<"Enter the month(int): ";
	in>>month;
	cout<<"Enter the year(int): ";
	in>>year;
	theDate = Date(day, month, year);
	return in;
}

//main method to test out functionality
int main(){
	cout << "hello\n";
	Date whatevs = Date(1,1,1);
		
	Student s1 = Student("Zappitello", "Mike", 123, 3.2, whatevs, whatevs, 1);
	Student s2 = Student("Tabak", "Abby", 124, 3.9, whatevs, whatevs, 2);
	Student s3 = Student("Taylor", "Sam", 122, 3.0, whatevs, whatevs, 3);
	Student s4 = Student("Pletcher", "Joe", 324, 3.1, whatevs, whatevs, 4);
	
	//Roster r1 = Roster("Calculus", 201, 4, "Dr. Samad Iqbal");
	Roster r1 = Roster();

	cin>>r1;
	r1.addStudent(s1);
	r1.addStudent(s2);
	r1.addStudent(s3);
	r1.addStudent(s4);
	
	//r1.sort();
	
	cout << "\n";
	
	cout << r1;
	
	cout << "\n";

	return 0;
}


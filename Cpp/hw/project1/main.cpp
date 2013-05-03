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

#include <vector>
#include <fstream>

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

bool validPassword(string username, string password){
	ifstream passwordFile;
	passwordFile.open("passwrds.txt");
	string line;
	
	while(passwordFile.is_open()){
		passwordFile >> line;
		if(username == line){
			passwordFile >> line;
			passwordFile >> line;
			if(password == line){
				return true;
			}
		}
		passwordFile >> line;
		passwordFile >> line;
	}
	
	passwordFile.close();
	return false;
}

void loadRosters(Roster** rosters, Student** students){
	ifstream rosterFile;
	rosterFile.open("rosters.txt");
}

//main method to test out functionality
int main(){
	cout << "hello\n";
	
	Roster** rosters = new Roster*[10];
	Student** students = new Student*[12];
	/*Date whatevs = Date(1,1,1);
		
	Student s1 = Student("Zappitello", "Mike", 123, 3.2, whatevs, whatevs, 1);
	Student s2 = Student("Tabak", "Abby", 124, 3.9, whatevs, whatevs, 2);
	Student s3 = Student("Taylor", "Sam", 122, 3.0, whatevs, whatevs, 3);
	Student s4 = Student("Pletcher", "Joe", 324, 3.1, whatevs, whatevs, 4);
	
	Roster r1 = Roster("Calculus", 201, 4, "Dr. Samad Iqbal");
	//Roster r1 = Roster();
	

	r1.addStudent(s1);
	r1.addStudent(s2);
	r1.addStudent(s3);
	r1.addStudent(s4);
	
	Roster r2 = r1;
	
	
	r2.sort();
	
	cout << r1;		
	
	cout << "\n";*/
	
	string username = "mzappitello";
	string password = "#spinmove";
	
	cout << validPassword(username, password) << endl;

	return 0;
}


/*
 *  Roster.h contains the Roster Class
 *
 *	@author:mike zappitello
 *	last update 10 oct 2012
 */

#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include "Homework3.h"

const int MAX_CAPACITY = 10;

class Roster{
		private:
		string courseName;
		int courseCode;
		int numberOfCredits;
		string instructor;
		Student classRoster[MAX_CAPACITY];
		int numStudents;
		
		public:
		//Constructors
		Roster();
		Roster(string cn, int cc, int noc, string proff);
		
		//Accessors
		const string getCourseName();
		const int getCourseCode();
		const int getNumberOfCredits();
		const string getInstructor();
		const Student getStudent(int i);
		const int getNumStudent();
		
		//Mutators
		void setCourseName(string name);
		void setCourseCode(int cc);
		void setNumberOfCredits(int noc);
		void setInstructor(string proff);
		
		//Input Functions
		void inputCourseName();
		void inputCourseCode();
		void inputNumberOfCredits();
		void inputInstructor();
		
		//Output Functions
		const void outputCourseName();
		const void outputCourseCode();
		const void outputNumberOfCredits();
		const void outputInstructor();
		
		//Student Roster Functions
		void addStudent(Student s);
		void deleteStudent(Student s);
		Student searchStudent(string s);
		const void printClassRoster();
};


//Constructors
Roster::Roster(){
	numStudents = 0;
}
Roster::Roster(string cn, int cc, int noc, string proff){
	courseName = cn;
	courseCode = cc;
	numberOfCredits = noc;
	instructor = proff;
	numStudents = 0;
}

//Accessors
const string Roster::getCourseName(){return courseName;}
const int Roster::getCourseCode(){return courseCode;}
const int Roster::getNumberOfCredits(){return numberOfCredits;}
const string Roster::getInstructor(){return instructor;}
const Student Roster::getStudent(int i){return classRoster[i];}
const int Roster::getNumStudent(){return numStudents;}
		
//Mutators
void Roster::setCourseName(string name){courseName = name;}
void Roster::setCourseCode(int cc){courseCode = cc;}
void Roster::setNumberOfCredits(int noc){numberOfCredits = noc;}
void Roster::setInstructor(string proff){instructor = proff;}
		
//Input Functions
void Roster::inputCourseName(){
	string cn;
	cout << "Please enter the course name.\n";
	cin >> cn;
	courseName = cn;
}
void Roster::inputCourseCode(){
	int cn;
	cout << "Please enter the course number.\n";
	cin >> cn;
	courseCode = cn;
}
void Roster::inputNumberOfCredits(){
	int noc;
	cout << "Please enter the number of credits the course is worth.\n";
	cin >> noc;
	if(isPositive(noc)){
		numberOfCredits = noc;
	}
}
void Roster::inputInstructor(){
	string proff;
	cout << "Please enter the instructors name.\n";
	cin >> proff;
	instructor = proff;
}
		
//Output Functions
const void Roster::outputCourseName(){cout << courseName;}
const void Roster::outputCourseCode(){cout << courseCode;}
const void Roster::outputNumberOfCredits(){cout << numberOfCredits;}
const void Roster::outputInstructor(){cout << instructor;}
		
//Student Roster Functions
/*adds a student to the roster
**@param: Student s - the student to be added*/
void Roster::addStudent(Student s){
	if(numStudents>10){
		cout << "There are already 10 students registered for " << courseName << ".\n";
	}
	else{
		classRoster[numStudents] = s;
		numStudents++;
	}
}

/*deletes a student from a roster
**@param: Student s - the student to be deleted from the roster*/
void Roster::deleteStudent(Student s){
	for(int n=0; n<numStudents; n++){
		if(s.getFirstName() == classRoster[n].getFirstName() && s.getLastName() == classRoster[n].getLastName()){
			classRoster[n] = classRoster[numStudents-1];
			numStudents--;
		}
	}
}

/*searches for a student
**@param: string s - either the first or last name of a student
**@return: Student	- the first student matching the passed param
**					- if a student is not found, returns a blank student*/
Student Roster::searchStudent(string s){
	for(int n=0; n<numStudents; n++){
		if (s == classRoster[n].getFirstName()){
			return classRoster[n];
		}
		if(s == classRoster[n].getLastName()){
			return classRoster[n];
		}
	}
	return Student();
}

/*prints out the class roster in the console
**each student's name is printed, followed by their total credits, standing, gpa, birthday, and matriculation day*/
const void Roster::printClassRoster(){
	for(int n=0; n<numStudents; n++){
		cout << classRoster[n].getLastName() << "," << classRoster[n].getFirstName() << "\n"; //<< ", " << classRoster[n].getFirstName << ", " << classRoster[n].getGPA;
		cout << "Credits: " << classRoster[n].getCredits() << "\n";
		cout << "Standing: " << classRoster[n].getStanding() << "\n";
		cout << "GPA: " << classRoster[n].getGPA() << "\n";
		cout << "Birthday: " << classRoster[n].getBirthday() << "\n";
		cout << "Matriculation Date: " << classRoster[n].getMatriculationDate() << "\n";
		
		cout << "\n";
	}
}

#endif
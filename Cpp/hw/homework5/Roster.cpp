/*
 *  Roster.cpp contains the fucntion definitions for the Student Class
 *
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#include "Roster.h"

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
const string Roster::getCourseName() const{return courseName;}
const int Roster::getCourseCode() const{return courseCode;}
const int Roster::getNumberOfCredits() const{return numberOfCredits;}
const string Roster::getInstructor() const{return instructor;}
const Student Roster::getStudent(int i) const{return classRoster[i];}
const int Roster::getNumStudent() const{return numStudents;}
		
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
	numberOfCredits = noc;
	
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

/*sorts out a roster using a selection sort algorithm*/
void Roster::sort(){
	Student temp;								//create temp variable
	int iTemp;									//create int temp variable
	for(int m=0; m<numStudents; m++){			//starting at the first place, iterrate through the list
		temp = classRoster[m];					//the temp student is whatever student is at the current place
		iTemp= m;								//the index is whatever index we are currently at
		for(int n=m+1; n<numStudents; n++){		//starting after the current index, iterate through the rest of the array 
			if(temp>classRoster[n]){			//if the current greatest student > the compared student
				temp = classRoster[n];			//the current greatest student is set to the comparted student
				iTemp = n;						//and we update the index of the greatest student
			}
		}										//finish iterating through the rest of the array
		classRoster[iTemp] = classRoster[m];	//swap the greatest student and our starting student
		classRoster[m] = temp;					//finish the swap
	}
}

/*prints out the class roster in the console
**each student's name is printed, followed by their total credits, standing, gpa, birthday, matriculation day, and student id*/
ostream& operator<<(ostream& out, const Roster& rstr){
	out << "Course: " << rstr.getCourseName() << "\n";
	out << "Course ID: " << rstr.getCourseCode() << "\n";
	out << "Course Credit Value: " << rstr.getNumberOfCredits() << "\n";
	out << "Instructor: " << rstr.getInstructor() << "\n";
	out << "Number of Students: " << rstr.getNumStudent() << "\n\n";

	Student temp;
	for(int n=0; n<rstr.getNumStudent(); n++){
		temp = rstr.getStudent(n);
		out << temp.getLastName() << "," << temp.getFirstName() << "\n"; //<< ", " << classRoster[n].getFirstName << ", " << classRoster[n].getGPA;
		out << "Credits: " << temp.getCredits() << "\n";
		out << "Standing: " << temp.getStanding() << "\n";
		out << "GPA: " << temp.getGPA() << "\n";
		out << "Birthday: " << Date::toString(temp.getBirthday()) << "\n";
		out << "Matriculation Date: " << Date::toString(temp.getMatriculationDate()) << "\n";
		out << "Student ID: " << temp.getStudentID() << "\n";
		
		out << "\n";
	}
	return out;
}

/*allows the user to input the info for the class
**Course name, Course ID, etc*/
istream& operator>>(istream& in, Roster& rstr){
	string tempString;
	int tempInt;
	
	cout<<"Course: ";
	in>>tempString;
	rstr.setCourseName(tempString);
	
	cout<<"Course ID: ";
	in>>tempInt;
	rstr.setCourseCode(tempInt);
	
	cout<<"Number of Credits: ";
	in>>tempInt;
	rstr.setNumberOfCredits(tempInt);
	
	cout<<"Instructor: ";
	in>>tempString;
	rstr.setInstructor(tempString);
	
	return in;
}
/*
 *  Roster.cpp contains the fucntion definitions for the Student Class
 *
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#include "Roster.h"

//Constructors
Roster::Roster() : courseName(""), courseCode(0), numberOfCredits(0), instructor(""), numStudents(0), size(0), classRoster(NULL){
	//empty on purpose
}
Roster::Roster(string cn, int cc, int noc, string proff) : courseName(cn), courseCode(cc), numberOfCredits(noc), instructor(proff), numStudents(0), size(0), classRoster(NULL){
	//empty on purpose
}
Roster::Roster(const Roster& other){
	courseName = other.courseName;
	courseCode = other.courseCode;
	numberOfCredits = other.numberOfCredits;
	instructor = other.instructor;
	numStudents = other.numStudents;
	
	size = other.size;
	classRoster = new Student[size];
	for(int i=0; i<size; i++){
		classRoster[i] = other.classRoster[i];
	}
}

//Destructor
Roster::~Roster(){	
	if(classRoster!=NULL){
		delete[] classRoster;
		classRoster = NULL;
	}
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
	if(size==0){
		size = 16;				//if the roster has no students, create a new array
		classRoster = new Student[16];		//of size 16
	}
	
	if(numStudents == size){			//if the array is full of students
		grow();					//grow the array so we can fit a new one
	}

	classRoster[numStudents] = s;			//add the student to the end of the array
	numStudents++;					//increment the number of students
}

/*deletes a student from a roster
**@param: Student s - the student to be deleted from the roster*/
void Roster::deleteStudent(Student s){
	int index = searchStudentIndex(s);
	
	if(index == -1){
		return;					//if the student isn't in our roster class
	}
	
	for(int b=index; b<numStudents-1; b++){		//pull each student in the roster up one place in the array
		classRoster[b] = classRoster[b+1];
	}
	
	classRoster[numStudents-1] = Student();		//add a blank student to the last place in the array
							//might be unnecessary, but just in case
	numStudents --;					//decrement the number of students in the roster
}

/*searches for a student
**@param:	Student s	- either the first or last name of a student
**@return:	Student		- the first student matching the passed param
**				- if a student is not found, returns a blank student*/
Student Roster::searchStudent(Student s){
	for(int n=0; n<numStudents; n++){
		if (s.getStudentID() == classRoster[n].getStudentID()){
			return classRoster[n];
		}
	}
	return Student();
}

/*searches for a student
**@para:	Student s	- the student object we are searching for
**@return:	int n		- the index of the student we searched for
**						or -1 if the student is not in our array*/

int Roster::searchStudentIndex(Student s){
	for(int n=0; n<numStudents; n++){
		if (s.getStudentID() == classRoster[n].getStudentID()){
			return n;
		}
	}
	return -1;
}

Student& Roster::operator[](int index){
	if(index<0 || index>numStudents){
		cout<<"index: "<<index<<" is out of bounds.\n";
		exit(1);
	}
	return classRoster[index];
}

Roster& Roster::operator=(const Roster& other){
	if(this != &other){				//if they aren't the same
		if(classRoster!=NULL){			//if the class roster isn't empty
			delete[] classRoster;		//empty the class roster
			classRoster = NULL;
		}
	}
	
	courseName = other.courseName;
	courseCode = other.courseCode;
	numberOfCredits = other.numberOfCredits;
	instructor = other.instructor;
	numStudents = other.numStudents;
	
	size = other.size;
	classRoster = new Student[size];
	for(int i=0; i<size; i++){
		classRoster[i] = other.classRoster[i];
	}
	
	return *this;
}

/*sorts out a roster using a selection sort algorithm*/
void Roster::sort(){
	Student temp;						//create temp variable
	int iTemp;						//create int temp variable
	for(int m=0; m<numStudents; m++){			//starting at the first place, iterrate through the list
		temp = classRoster[m];				//the temp student is whatever student is at the current place
		iTemp= m;					//the index is whatever index we are currently at
		for(int n=m+1; n<numStudents; n++){		//starting after the current index, iterate through the rest of the array 
			if(temp>classRoster[n]){		//if the current greatest student > the compared student
				temp = classRoster[n];		//the current greatest student is set to the comparted student
				iTemp = n;			//and we update the index of the greatest student
			}
		}						//finish iterating through the rest of the array
		classRoster[iTemp] = classRoster[m];		//swap the greatest student and our starting student
		classRoster[m] = temp;				//finish the swap
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

	for(int n=0; n<rstr.getNumStudent(); n++){
		out << rstr.classRoster[n].getLastName() << "," << rstr.classRoster[n].getFirstName() << "\n"; //<< ", " << classRoster[n].getFirstName << ", " << classRoster[n].getGPA;
		out << "Credits: " << rstr.classRoster[n].getCredits() << "\n";
		out << "Standing: " << rstr.classRoster[n].getStanding() << "\n";
		out << "GPA: " << rstr.classRoster[n].getGPA() << "\n";
		out << "Birthday: " << Date::toString(rstr.classRoster[n].getBirthday()) << "\n";
		out << "Matriculation Date: " << Date::toString(rstr.classRoster[n].getMatriculationDate()) << "\n";
		out << "Student ID: " << rstr.classRoster[n].getStudentID() << "\n";
		
		out << "\n";
	}
	return out;
}

/*takes user input for non student elements of the roster
**eg. courseCode, instructor, numCredits*/
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

/*a helper function for add student that increases the size of the roster to
**when the number of students reaches the size of the array*/
void Roster::grow(){
	 Student* temp = new Student[2*size];
	 
	 for(int n=0; n<size; n++){
		temp[n] = classRoster[n];
	 }
	 
	 delete [] classRoster;
	 classRoster = NULL;
	 
	 classRoster = temp;
	 size = 2*size;
}

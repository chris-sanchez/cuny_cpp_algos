/*
 *  This is the sollution to Homework 2
 *  
 *	@author mzappitello
 */

#include <iostream>
#include "Homework3.h"

using namespace std;

bool isPositive(double x);

class Student{
	private:
		string lastName;
		string firstName;
		string standing;			//is a function of credits. 0-15 freshman
		double credits;
		double gpa;
		string birthday;
		string matriculationDate;
	
	public:
		//Constructors
		Student(string ln, string fn, double cred, double gradePtAvg, string bd, string md);
		Student();
	
		//Acessors
		const string getLastName();
		const string getFirstName();
		const string getStanding();
		const double getCredits();
		const double getGPA();
		const string getBirthday();
		const string getMatriculationDate();
		const int getStudentID();
				
		//Mutators
		void setLastName(string ln);
		void setFirstName(string fn);
		void setCredits(double cred);
		void setGPA(double gradePtAvg);
		void setBirthday(string bd);
		void setMatriculationDate(string md);
		
		//Input Functions
		void inputLastName();
		void inputFirstName();
		void inputCredits();
		void inputGPA();
		void inputBirthday();
		void inputMatriculationDate();
		
		
		//Output Functions
		const void outputLastName();
		const void outputFirstName();
		const void outputStanding();
		const void outputCredits();
		const void outputGPA();
		const void outputBirthday();
		const void outputMatriculationDate();
		
		//Other Functions
		void updateStanding();
};

//Constructors
Student::Student(string ln, string fn, double cred, double gradePtAvg, string bd, string md){
	lastName = ln;
	firstName = fn;
	if(isPositive(cred)){
		credits = cred;
		updateStanding();
	}
	if(isPositive(gradePtAvg)){
		gpa = gradePtAvg;
	}
	birthday = bd;
	matriculationDate = md;
} 
Student::Student(){
	lastName = "LastName";
	firstName = "FirstName";
	credits = 0;
	gpa = 0;
	birthday = "01 January 1900";
	matriculationDate = "01 January 1900";
	updateStanding();
}

//Accessors
const string Student::getLastName(){return lastName;}
const string Student::getFirstName(){return firstName;}
const string Student::getStanding(){return standing;}
const double Student::getCredits(){return credits;}
const double Student::getGPA(){return gpa;}
const string Student::getBirthday(){return birthday;}
const string Student::getMatriculationDate(){return matriculationDate;}

//Mutators
void Student::setLastName(string ln){lastName = ln;}
void Student::setFirstName(string fn){firstName = fn;}		
void Student::setCredits(double cred){
	if(isPositive(cred)){
		credits = cred;
		updateStanding();
	}
}
void Student::setGPA(double gradePtAvg){
	if(isPositive(gradePtAvg)){
		gpa = gradePtAvg;
	}
}
void Student::setBirthday(string bd){birthday = bd;}
void Student::setMatriculationDate(string md){matriculationDate = md;}
		
//Input Functions
void Student::inputLastName(){
	string ln;
	cout << "Please enter the student's last name.\n";
	cin >> ln;
	lastName = ln;
}		
void Student::inputFirstName(){
	string fn;
	cout << "Please enter the student's first name.\n";
	cin >> fn;
	firstName = fn;
}
void Student::inputCredits(){
	double cred;
	cout << "Please enter the number of credits the student has earned.\n";
	cin >> cred;
	if(isPositive(cred)){
		credits = cred;
		updateStanding();
	}
}
void Student::inputGPA(){
	double gradePtAvg;
	cout << "Please enter the student's GPA.\n";
	cin >> gradePtAvg;
	if(isPositive(gradePtAvg)){
		gpa = gradePtAvg;
	}
}
void Student::inputBirthday(){
	string bd;
	cout << "Please enter the student's birthday.\n";
	cin >> bd;
	birthday = bd;
}
void Student::inputMatriculationDate(){
	string md;
	cout << "Please enter the student's matriculation date.\n";
	cin >> md;
	matriculationDate = md;
}

//Output Functions
const void Student::outputLastName(){cout << lastName;}
const void Student::outputFirstName(){cout << firstName;}
const void Student::outputStanding(){cout << standing;}
const void Student::outputCredits(){cout << credits;}
const void Student::outputGPA(){cout << gpa;}
const void Student::outputBirthday(){cout << birthday;}
const void Student::outputMatriculationDate(){cout << matriculationDate;}

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
	for(int n=0; n<10; n++){
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
		
/*set's the students standing based on the number of credits the student has
**is used internally in the class whenever the credits are updated*/
void Student::updateStanding(){
	if(credits <= 15){standing = "Lower Freshman";}
	else if(credits > 15 && credits <= 30){standing = "Upper Freshman";}
	else if(credits > 30 && credits <= 45){standing = "Lower Sophmore";}
	else if(credits > 45 && credits <= 60){standing = "Upper Sophmore";}
	else if(credits > 60 && credits <= 75){standing = "Lower Junior";}
	else if(credits > 75 && credits <= 90){standing = "Upper Junior";}
	else if(credits > 90 && credits <= 105){standing = "Lower Senior";}
	else{standing = "Upper Senior";}
}
		
/*checks to make sure a number is positive
**used to error check to make sure gpa and number of credits are positive
**@param double x: the number to be teseted
**@return false if x is less than 0, true otherwise*/
bool isPositive(double x){
	if(x < 0){return false;}
	return true;
}

int main(){
	cout << "hello\n";
		
	Student s1 = Student("Zappitello", "Mike", 123, 3.2, "7 Nov 1986", "28 Aug 2012");
	Student s2 = Student("Tabak", "Abby", 124, 3.9, "6 March 1984", "29 Aug 2012");
	Student s3 = Student("Taylor", "Sam", 122, 3.0, "31 Dec 1986", "27 Aug 2012");
	Student s4 = Student("Pletcher", "Joe", 324, 3.1, "23 June 1985", "25 Aug 2012");
	
	Roster r1 = Roster("Calculus", 201, 4, "Dr. Samad Iqbal");
	r1.addStudent(s1);
	r1.addStudent(s2);
	r1.addStudent(s3);
	r1.addStudent(s4);
		
	r1.deleteStudent(s3);
		
	r1.printClassRoster();
	cout << "\n";
	return 0;
}
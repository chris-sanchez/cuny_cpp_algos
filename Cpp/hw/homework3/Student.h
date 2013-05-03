/*
 *  Student.h contains the Student Class
 *
 *	@author:mike zappitello
 *	last update 10 oct 2012
 */

#ifndef STUDENT_H
#define STUDENT_H
 
#include "Homework3.h"

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

#endif
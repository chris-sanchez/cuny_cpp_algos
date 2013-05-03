/*
 *  Student.cpp contains the function definitions for the Student Class
 *
 *	@author:mike zappitello
 *	last update 30 nov 2012
 */

#include "Student.h"

/*checks to make sure a number is positive
**used to error check to make sure gpa and number of credits are positive
**@param double x: the number to be teseted
**@return false if x is less than 0, true otherwise*/
bool isPositive(double x){
	if(x < 0){return false;}
	return true;
}

//Constructors
Student::Student(string ln, string fn, double cred, double gradePtAvg, Date bd, Date md, int std){
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
	studentID = std;
} 
Student::Student(){
	lastName = "LastName";
	firstName = "FirstName";
	credits = 0;
	gpa = 0;
	birthday = Date();
	matriculationDate = Date();
	updateStanding();
	studentID = 0;
}

//Accessors
const string Student::getLastName() const{return lastName;}
const string Student::getFirstName() const{return firstName;}
const string Student::getStanding() const{return standing;}
const double Student::getCredits() const{return credits;}
const double Student::getGPA() const{return gpa;}
const Date Student::getBirthday() const{return birthday;}
const Date Student::getMatriculationDate() const{return matriculationDate;}
const int Student::getStudentID() const{return studentID;}

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
void Student::setBirthday(Date bd){birthday = bd;}
void Student::setMatriculationDate(Date md){matriculationDate = md;}
void Student::setStudentID(int std){studentID = std;}
		
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
	int month, day, year;
	cout << "Please enter the student's birthday.\n";
	
	cout << "The day (int): \n";
	cin >> day;
	
	cout << "The month (int): \n";
	cin >> month;
	
	cout << "The year (int): \n";
	cin >> year;
	
	birthday = Date(day, month, year);
}
void Student::inputMatriculationDate(){
	int month, day, year;
	cout << "Please enter the student's matriculation date.\n";
	
	cout << "The day (int): \n";
	cin >> day;
	
	cout << "The month (int): \n";
	cin >> month;
	
	cout << "The year (int): \n";
	cin >> year;
	
	matriculationDate = Date(day, month, year);
}
void Student::inputStudentID(){
	int std;
	cout << "Please enter the student's id. \n";
	cin >> std;
	studentID = std;
}

//Output Functions
const void Student::outputLastName(){cout << lastName;}
const void Student::outputFirstName(){cout << firstName;}
const void Student::outputStanding(){cout << standing;}
const void Student::outputCredits(){cout << credits;}
const void Student::outputGPA(){cout << gpa;}
const void Student::outputBirthday(){cout << Date::toString(birthday);}
const void Student::outputMatriculationDate(){cout << Date::toString(matriculationDate);}
const void Student::outputStudentID(){cout << studentID;}

//Comparators
const bool Student::operator ==(const Student& std2){
	if(lastName == std2.lastName){
		if(firstName == std2.firstName){
			if(studentID == std2.studentID){
				return true;
			}
		}
	}
	return false;
}
const bool Student::operator !=(const Student& std2){
	if(lastName == std2.lastName){
		if(firstName == std2.firstName){
			if(studentID == std2.studentID){
				return false;
			}
		}
	}
	return true;
}
const bool Student::operator <(const Student& std2){
	cout<<lastName<<" < "<<std2.lastName<<"\n";
	if(lastName < std2.lastName){
		cout<<"WTF!\n";
		return true;
	}
	
	else if(lastName == std2.lastName){
		if(firstName < std2.firstName){
			return true;
		}
		else if(firstName == std2.firstName){
			if(studentID < std2.studentID){
				return true;
			}
		}
	}
	
	return false;
}
const bool Student::operator >(const Student& std2){
	if(lastName > std2.lastName){
		return true;
	}
	
	else if(lastName == std2.lastName){
		if(firstName > std2.firstName){
			return true;
		}
		else if(firstName == std2.firstName){
			if(studentID > std2.studentID){
				return true;
			}
		}
	}
	
	return false;
}
const bool Student::operator <=(const Student& std2){
	if(lastName > std2.lastName){
		return false;
	}
	
	else if(lastName == std2.lastName){
		if(firstName > std2.firstName){
			return false;
		}
		else if(firstName == std2.firstName){
			if(studentID > std2.studentID){
				return false;
			}
		}
	}
	
	return true;
}
const bool Student::operator >=(const Student& std2){
	if(lastName < std2.lastName){
		return false;
	}
	
	else if(lastName == std2.lastName){
		if(firstName < std2.firstName){
			return false;
		}
		else if(firstName == std2.firstName){
			if(studentID < std2.studentID){
				return false;
			}
		}
	}
	
	return true;
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

/*overrides the input and output operators for a student*/
ostream& operator<<(ostream& out, const Student& std){
	out<<"Student Name: "<<std.lastName<<", "<<std.firstName<<"\n";
	out<<"Credits: "<<std.credits<<"\n";
	out<<"Standing: "<<std.standing<<"\n";
	out<<"GPA: "<<std.gpa<<"\n";
	out<<"Born: "<<Date::toString(std.birthday)<<"\n";
	out<<"Matriculation: "<<Date::toString(std.matriculationDate)<<"\n";
	out<<"Student ID: "<<std.studentID<<"\n";
	
	return out;
}
istream& operator>>(istream& in, Student& std){
	cout<<"Last Name: ";
	in>>std.lastName;
	
	cout<<"First Name: ";
	in>>std.firstName;
	
	cout<<"Credits: ";
	in>>std.credits;
	
	std.updateStanding();
	
	cout<<"GPA: ";
	in>>std.gpa;
	
	cout<<"Birthday\n";
	in>>std.birthday;
	
	cout<<"Matriculation Date\n";
	in>>std.matriculationDate;

	cout<<"Student ID: ";
	in>>std.studentID;

	return in;
}


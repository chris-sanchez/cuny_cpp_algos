/*
 *  Student.h contains the declerations for the Student Class
 *
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cmath>
using namespace std;
 
#include "Date.h"

class Student{
	private:
		string lastName;
		string firstName;
		string standing;			//is a function of credits. 0-15 freshman
		double credits;
		double gpa;
		Date birthday;
		Date matriculationDate;
		int studentID;
	
	public:
		//Constructors
		Student(string ln, string fn, double cred, double gradePtAvg, Date bd, Date md, int std);
		Student();
	
		//Acessors
		const string getLastName() const;
		const string getFirstName() const;
		const string getStanding() const;
		const double getCredits() const;
		const double getGPA() const;
		const Date getBirthday() const;
		const Date getMatriculationDate() const;
		const int getStudentID() const;
				
		//Mutators
		void setLastName(string ln);
		void setFirstName(string fn);
		void setCredits(double cred);
		void setGPA(double gradePtAvg);
		void setBirthday(Date bd);
		void setMatriculationDate(Date md);
		void setStudentID(int std);
		
		//Input Functions
		void inputLastName();
		void inputFirstName();
		void inputCredits();
		void inputGPA();
		void inputBirthday();
		void inputMatriculationDate();
		void inputStudentID();
		
		
		//Output Functions
		const void outputLastName();
		const void outputFirstName();
		const void outputStanding();
		const void outputCredits();
		const void outputGPA();
		const void outputBirthday();
		const void outputMatriculationDate();
		const void outputStudentID();
		
		//Comparators
		const bool operator ==(const Student& std2);
		const bool operator !=(const Student& std2);
		const bool operator <(const Student& std2);
		const bool operator >(const Student& std2);
		const bool operator <=(const Student& std2);
		const bool operator >=(const Student& std2);
		
		//Other Functions
		void updateStanding();
		
		//insertion and output operator overrides
		friend ostream& operator<<(ostream& out, const Student& std);
		friend istream& operator>>(istream& in, Student& std);
};
#endif



/*
 *  Roster.h contains the declerations for the Roster Class
 *
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"

class Roster{
		public:
			string courseName;
			int courseCode;
			int numberOfCredits;
			string instructor;
			int numStudents;
			
			int size;
			Student* classRoster;
		
			//sorts the list using a selection sort
			void sort();
			//grows the size of the array to accomadate more students
			void grow();
		
		public:
			//Constructors
			Roster();
			Roster(string cn, int cc, int noc, string proff);
			Roster(const Roster& other);
			
			//Destructor
			~Roster();
		
			//Accessors
			const string getCourseName() const;
			const int getCourseCode() const;
			const int getNumberOfCredits() const;
			const string getInstructor() const;
			const Student getStudent(int i) const;
			const int getNumStudent() const;
		
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
			Student searchStudent(Student s);
			int searchStudentIndex(Student s);
			
			//Overload [] and = operators
			Student& operator[](int index);
			Roster& operator=(const Roster& other);

			//Overload input and output operators as friends
			friend ostream& operator<<(ostream& out, const Roster& rstr);
			friend istream& operator>>(istream& in, Roster& rstr);
};

#endif



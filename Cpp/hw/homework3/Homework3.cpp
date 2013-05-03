/*
 *  Homework3.cpp
 *  
 *
 *  Created by mzappitello on 10/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Homework3.h"
#include "Student.h"
#include "Roster.h"

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
		
	//r1.deleteStudent(s3);
	
	r1.printClassRoster();
	cout << "\n";
	return 0;
}


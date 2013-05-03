/*
 *  Homework3.h contains miscelanious functions used in HW3
 *  
 *	@author mike zappitello
 *	last updated 10 oct 2012
 */

#ifndef HOMEWORK3_H
#define HOMEWORK3_H

#include <iostream>
using namespace std;

/*checks to make sure a number is positive
**used to error check to make sure gpa and number of credits are positive
**@param double x: the number to be teseted
**@return false if x is less than 0, true otherwise*/
bool isPositive(double x){
	if(x < 0){return false;}
	return true;
}

#endif
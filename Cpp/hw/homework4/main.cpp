/*
 *  main.cpp contains the fucntion definitions for the assignment
 *	main.cpp also contains the main method for the assignment
 *
 *	@author:mike zappitello
 *	last update 21 nov 2012
 */

#include "main.h"
#include "Date.h"
#include <iostream>

const int dateToInt(const Date& d){
	int day = d.getDay();
	int month;
	int year = d.getYear();
	
	if(d.getMonth()=="January"){
		month = 1;
	}
	else if(d.getMonth()=="February"){
		month = 2;
	}
	else if(d.getMonth()=="March"){
		month = 3;
	}
	else if(d.getMonth()=="April"){
		month = 4;
	}
	else if(d.getMonth()=="May"){
		month = 5;
	}
	else if(d.getMonth()=="June"){
		month = 6;
	}
	else if(d.getMonth()=="July"){
		month = 7;
	}
	else if(d.getMonth()=="August"){
		month = 8;
	}
	else if(d.getMonth()=="September"){
		month = 9;
	}
	else if(d.getMonth()=="October"){
		month = 10;
	}
	else if(d.getMonth()=="November"){
		month = 11;
	}
	else{
		month = 12;
	}
	
	int sum = day%10 + ((day-day%10)/10);
	
	sum += month%10 + ((month-month%10)/10);
	
	while(year > 9){
		sum += year%10;
		year = (year-year%10)/10;
	}
	sum += year;
	
	return sumItUp(sum);
}

int sumItUp(int sum){
	int newSum = 0;
	
	while(sum>9){
		newSum += sum%10;
		sum = (sum-sum%10)/10;
	}
	newSum += sum;

	if(newSum > 9){
		newSum = sumItUp(newSum);
	}

	return newSum;
}

int main(){
	cout << "hello\n";
	
	int length;
	cout << "How many dates are in the list?\n";
	cin >> length;
	
	Date* dateArray = new Date[length];	
	
	int day, month, year;
	for(int i=0; i<length; i++){
		cout << "What is the day (int)?\n";
		cin >> day;
		cout << "What is the month (int)?\n";
		cin >> month;
		cout << "What is the year (int)?\n";
		cin >> year;
		
		dateArray[i] = Date(day, month, year);
	}
	
	int* intArray = new int[length];
	for(int i=0; i<length; i++){
		intArray[i] = dateToInt(dateArray[i]);
	}
	
	for(int i=0; i<length; i++){
		cout << Date::toString(dateArray[i]) << "\n";
		cout << intArray[i] << "\n";
	}
	
	delete []intArray;
	delete []dateArray;

	return 0;
}

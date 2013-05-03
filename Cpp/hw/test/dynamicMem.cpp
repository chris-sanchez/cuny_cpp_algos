/*
 *  dynamicMem.cpp
 *  
 *
 *  Created by mzappitello on 11/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "Date.h"
using namespace std;

class SafeArray{
	public:
		int size;
		Date* array;
		
	public:
		SafeArray();
		SafeArray(int s);
		SafeArray(const SafeArray& other);
		~SafeArray();
		int length() const;
		Date& operator[](int index);
		SafeArray& operator=(const SafeArray& other);
		
};

SafeArray::SafeArray() : size(0), array(NULL){
	//empty
}

SafeArray::SafeArray(int s) : size(s){
	array = new Date[size];
}

SafeArray::SafeArray(const SafeArray& other){
	size = other.size;
	array = new Date[size];
	for(int i=0; i<size; i++){
		array[i] = other.array[i];
	}
}

SafeArray::~SafeArray(){
	if(array!=NULL){
		delete[] array;
		array = NULL;
	}
}

int SafeArray::length() const{
	return size;
}

Date& SafeArray::operator[](int index){
	if(index<0 || index>size){
		cout<<"index: "<<index<<" is out of bounds.\n";
		exit(1);
	}
	return array[index];
}

SafeArray& SafeArray::operator=(const SafeArray& other){
	if(this != &other){
		if(array!=NULL){
			delete[] array;
			array = NULL;
		}
	}
	
	size = other.size;
	array = new Date[size];
	for(int i=0; i<size; i++){
		array[i] = other.array[i];
	}
	
	return *this;
}



int main(){
	cout<<"hello\n";
	
	SafeArray dateArray = SafeArray(7);
	Date t;

	
	//dateArray[1] = t;
	
	for(int y=0; y<dateArray.length(); y++){
		t = Date(y+2, y+1, y+2000);
		dateArray[y] = t;
	}
	
	SafeArray testArray = SafeArray(dateArray);
	
	for(int z=0; z<dateArray.length(); z++){
		cout<<Date::toString(testArray[z])<<"\n";
	}

	cout<<"\n";
		
	return 0;
}
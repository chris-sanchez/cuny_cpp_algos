/*
 *  zappitello_mike_cs211_test2.h
 *  
 *
 *  Created by mzappitello on 12/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
using namespace std;

template <class T>
class MyVector{
	private:
		int capacity;
		int size;
		T* array;
		
	public:
		//Constructors
		MyVector();
		MyVector(const MyVector& other);
		
		//Destructor
		~MyVector();
		
		//Overload [] and = Operators
		T& operator[](int index);
		MyVector& operator=(const MyVector& other);
		
		//Other Methods
		void push_back(int value);
		int getCapacity();
		int getSize();
		void reserve(int newCapacity);
		void resize(int newSize);
		void grow();
};


#endif
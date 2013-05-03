/*
 *  zappitello_mike_cs211_test2.cpp
 *  
 *
 *  Created by mzappitello on 12/6/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "MyVector.h"

template <class T>
MyVector<T>::MyVector(){
	size = 0;
	capacity = 10;
	array = new T[capacity];
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& other){
	size = other.size;
	capacity = other.capacity;
	array = new T[capacity];
	
	for(int e=0; e<size; e++){
		array[e] = other.array[e];
	}
}

template <class T>
MyVector<T>::~MyVector(){
	if(array!=NULL){
		delete [] array;
		array = NULL;
	}
}

template <class T>
T& MyVector<T>::operator[](int index){
	if(index<0 || index>size){
		cout<<"index: "<<index<<" is out of bounds!\n";
		exit(1);
	}
	return array[index];
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other){
	if(this != &other){
		if(array!=NULL){
			delete [] array;
			array = NULL;
		}
	}
	
	size = other.size;
	capacity = other.capacity;
	array = new T[capacity];
	for(int y=0; y<size; y++){
		array[y] = other.array[y];
	}
	
	return *this;
}

template <class T>
void MyVector<T>::push_back(int value){
	if(size == capacity){
		grow();
	}
	
	array[size] = value;
	size++;
}

template <class T>
int MyVector<T>::getCapacity(){
	return capacity;
}

template <class T>
int MyVector<T>::getSize(){
	return size;
}

template <class T>
void MyVector<T>::reserve(int newCapacity){
	T* temp = new T[newCapacity];
	int min = size<newCapacity? size:newCapacity;
	for(int f=0; f<min; f++){
		temp[f] = array[f];
	}
	delete [] array;
	array = temp;
}

template <class T>
void MyVector<T>::resize(int newSize){
	T* temp = new T[capacity];
	for(int g=0; g<newSize; g++){
		temp[g] = array[g];
	}
	delete [] array;
	array = temp;
}

template <class T>
void MyVector<T>::grow(){
	T* temp = new T[capacity*2];
	
	for(int h=0; h<size; h++){
		temp[h] = array[h];
	}
	
	delete [] array;
	array = temp;
	capacity = 2*capacity;
}

int main(){
	MyVector <int>test;
	//test = new MyVector<int>();
	return 0;
}


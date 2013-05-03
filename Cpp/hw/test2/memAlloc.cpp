/*
 *  memAlloc.cpp
 *  
 *
 *  Created by mzappitello on 11/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "memAlloc.h"
#include <iostream>

using namespace std;

MemAlloc::MemAlloc() : rows(0), columns(0), array(NULL){
	//left empty
}

MemAlloc::MemAlloc(int r, int c) : rows(r), columns(c){
	array = new int*[rows];
	for(int p=0; p<rows; p++){
		array[p] = new int[columns];
	}
}

MemAlloc::MemAlloc(const MemAlloc& other){
	rows = other.rows;
	columns = other.columns;
	array = new int*[rows];
	for(int q=0; q<rows; q++){
		array[q] = new int[columns];
		for(int r=0; r<columns; r++){
			array[q][r] = other.array[q][r];
		}
	}
}

MemAlloc::~MemAlloc(){
	if(array!=NULL){
		for(int l=0; l<columns; l++){
			if(array[l] != NULL){
				delete[] array[l];
				array[l] = NULL;
			}
		}
		delete[] array;
		array = NULL;
	}
}

int MemAlloc::numRows() const{
	return rows;
}

int MemAlloc::numCols() const{
	return columns;
}	

int* MemAlloc::operator [](int index){
	if(index<0 || index>rows){
		cout<<"index: " << index
			<<" is out of bounds."
			<<"\n";
		exit(1);
	}
	
	return array[index];
}

MemAlloc& MemAlloc::operator =(const MemAlloc& other){
	if(this != &other){
		if(array != NULL){
			for(int u=0; u<columns; u++){
				if(array[u]!=NULL){
					delete[] array[u];
					array[u] = NULL;
				}
			}
			delete[] array;
			array = NULL;
		}
	}
	
	rows = other.rows;
	columns = other.columns;
	array = new int*[rows];
	for(int w=0; w<rows; w++){
		array[w] = new int[columns];
		for(int v=0; v<columns; v++){
			array[w][v] = other.array[w][v];
		}
	}
	
	return *this;
}

int main(){
	cout<<"hello\n";
	
	MemAlloc first = MemAlloc(5,6);
	
	for(int g=0; g<first.numRows(); g++){
		for(int h=0; h<first.numCols(); h++){
			first[g][h]=g+h;
		}
	}
	
	MemAlloc second = first;
	
	for(int j=0; j<second.numRows(); j++){
		for(int k=0; k<second.numCols(); k++){
			cout<<second[j][k]<<", ";
		}
		cout<<"\n";
	}
		
	return 0;
}
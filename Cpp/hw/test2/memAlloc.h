/*
 *  memAlloc.h
 *  
 *
 *  Created by mzappitello on 11/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef MEMALLOC_H
#define MEMALLOC_H

class MemAlloc{
	private:
		int rows;
		int columns;
		int** array;
		
	public:
		MemAlloc();
		MemAlloc(int r, int c);
		MemAlloc(const MemAlloc& other);
		~MemAlloc();
		int numRows() const;
		int numCols() const;
		int* operator[](int index);
		MemAlloc& operator =(const MemAlloc& other);
};

#endif MEMALLOC_H

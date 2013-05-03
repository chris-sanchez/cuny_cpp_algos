// SafeMatrix.h

#ifndef SAFE_MATRIX_H
#define SAFE_MATRIX_H

#include <iostream>
using namespace std;

template<class T> 
class SafeMatrix{
	private:
		int rows;
		int columns;
		T** array;
		
	public:
		SafeMatrix();
		SafeMatrix(int r, int c);
		SafeMatrix(const SafeMatrix& other);
		~SafeMatrix();
		int numRows() const;
		int numCols() const;
		T* operator[](int index);
		SafeMatrix& operator =(const SafeMatrix& other);
		int length() const;
};
#endif



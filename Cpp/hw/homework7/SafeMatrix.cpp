//SafeMatrix.cpp

#include "SafeMatrix.h"

template<class T>
SafeMatrix<T>::SafeMatrix() : rows(0), columns(0), array(NULL){
	//left empty
}

template<class T>
SafeMatrix<T>::SafeMatrix(int r, int c) : rows(r), columns(c){
	array = new T*[rows];
	for(int p=0; p<rows; p++){
		array[p] = new T[columns];
	}
}

template<class T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix& other){
	rows = other.rows;
	columns = other.columns;
	array = new T*[rows];
	for(int q=0; q<rows; q++){
		array[q] = new T[columns];
		for(int r=0; r<columns; r++){
			array[q][r] = other.array[q][r];
		}
	}
}

template<class T>
SafeMatrix<T>::~SafeMatrix(){
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

template<class T>
int SafeMatrix<T>::numRows() const{
	return rows;
}

template<class T>
int SafeMatrix<T>::numCols() const{
	return columns;
}	

template<class T>
T* SafeMatrix<T>::operator [](int index){
	if(index<0 || index>rows){
		cout<<"index: " << index
			<<" is out of bounds."
			<<"\n";
		exit(1);
	}
	
	return array[index];
}

template<class T>
SafeMatrix<T>& SafeMatrix<T>::operator =(const SafeMatrix& other){
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
	array = new T*[rows];
	for(int w=0; w<rows; w++){
		array[w] = new T[columns];
		for(int v=0; v<columns; v++){
			array[w][v] = other.array[w][v];
		}
	}
	
	return *this;
}

template<class T>
int SafeMatrix<T>::length() const{
	return rows;
}

int main(){
	cout<<"hello\n";
	
	SafeMatrix<int> first = SafeMatrix<int>(5,6);
	
	for(int g=0; g<first.numRows(); g++){
		for(int h=0; h<first.numCols(); h++){
			first[g][h]=g+h;
		}
	}
	
	SafeMatrix<int> second = first;
	
	for(int j=0; j<second.numRows(); j++){
		for(int k=0; k<second.numCols(); k++){
			cout<<second[j][k]<<", ";
		}
		cout<<"\n";
	}
		
	return 0;
}
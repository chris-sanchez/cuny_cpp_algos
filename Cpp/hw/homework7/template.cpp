/*
 *  dynamicMem.cpp
 *  
 *
 *  Created by mzappitello on 11/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T* a, b;
  public:
    mypair (T* first, T* second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  T aPrime = &a;
  if(&a > &b){
	retval = &a;
  }
  else{
	retval = &b;
  }
  return retval;
}

int main () {
  char* a = new char('a');
  char* c = new char('c');
  mypair <char> myobject (a, c);
  cout << myobject.getmax() << endl;
  return 0;
}
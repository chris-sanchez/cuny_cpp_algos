// File.h

#ifndef FILE_H
#define FILE_H

// a partent class for file types

#include <string>
#include <iostream>
using namespace std;

class File{
	private:
		string name;
		string type;
	public:
		File();
		File(const string& t);
		File(const string& n, const string& t);
		string getName() const;
		string getType() const;
		virtual int getSize() const;
		void displayProperties() const;
};

#endif

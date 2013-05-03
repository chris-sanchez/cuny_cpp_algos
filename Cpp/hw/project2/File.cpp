//File.cpp

#include "File.h"

File::File() : name(""), type(""){
	//left empty
}

File::File(const string& t) : name(""), type(t){
	//left empty
}

File::File(const string& n, const string& t) : name(n), type(t){
	//left empty
}

string File::getName() const{
	return name;
}

string File::getType() const{
	return type;
}

void File::displayProperties() const{
	cout << "Name: " << name << "." << type << endl;
}

int File::getSize() const{
	return 0;
}
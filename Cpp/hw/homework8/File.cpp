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

string File::getName(){
	return name;
}

string File::getType(){
	return type;
}

void File::displayProperties(){
	cout << "Name: " << name << "." << type << endl;
}
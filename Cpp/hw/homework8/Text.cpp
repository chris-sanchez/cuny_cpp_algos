//File.cpp

#include "Text.h"

TextFile::TextFile() : File("txt"), numChars(0){
	//left empty
}

TextFile::TextFile(const string& n, const int& numChar) : File(n, "txt"), numChars(numChar){
	//left empty
}

int TextFile::getNumChars(){
	return numChars;
}

void TextFile::displayProperties(){
	cout << "Name: " << getName() << "." << getType() << endl;
	cout << "Size: " << getSize() << endl;
	cout << "Number of Charecters: " << numChars << endl;
}

int TextFile::getSize(){
	return numChars;
}
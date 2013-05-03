//File.cpp

#include "Text.h"

TextFile::TextFile() : File("txt"), numChars(0){
	//left empty
}

TextFile::TextFile(const string& n, const int& numChar) : File(n, "txt"), numChars(numChar){
	//left empty
}

int TextFile::getNumChars() const{
	return numChars;
}

void TextFile::displayProperties() const{
	cout << "Name: " << getName() << "." << getType() << endl;
	cout << "Size: " << getSize() << endl;
	cout << "Number of Charecters: " << numChars << endl;
}

int TextFile::getSize() const{
	return numChars;
}

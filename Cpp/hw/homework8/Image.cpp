//File.cpp

#include "Image.h"

ImageFile::ImageFile() : File("gif"), width(0), height(0), depth(0){
	//left empty
}

ImageFile::ImageFile(const string& n, const int& w, const int& h, const int& d) : File(n, "gif"), width(w), height(h), depth(d){
	//left empty
}

int ImageFile::getWidth(){
	return width;
}

int ImageFile::getHeight(){
	return height;
}

int ImageFile::getDepth(){
	return depth;
}

void ImageFile::displayProperties(){
	cout << "Name: " << getName() << "." << getType() << endl;
	cout << "Size: " << getSize() << endl;
	cout << "Dimensions: " << width << "x" << height << endl;
	cout << "Depth: " << depth << endl;
}

int ImageFile::getSize(){
	return width*height*depth/8;
}
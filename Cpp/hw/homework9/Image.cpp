//File.cpp

#include "Image.h"

ImageFile::ImageFile() : File("gif"), width(0), height(0), depth(0){
	//left empty
}

ImageFile::ImageFile(const string& n, const int& w, const int& h, const int& d) : File(n, "gif"), width(w), height(h), depth(d){
	//left empty
}

int ImageFile::getWidth() const{
	return width;
}

int ImageFile::getHeight() const{
	return height;
}

int ImageFile::getDepth() const{
	return depth;
}

void ImageFile::displayProperties() const{
	cout << "Name: " << getName() << "." << getType() << endl;
	cout << "Size: " << getSize() << endl;
	cout << "Dimensions: " << width << "x" << height << endl;
	cout << "Depth: " << depth << endl;
}

int ImageFile::getSize() const{
	return width*height*depth/8;
}

// Image.h

#ifndef IMAGE_H
#define IMAGE_H

// a class that extends the file type

#include "File.h"

class ImageFile : public File{
	private:
		int width;
		int height;
		int depth;
	public:
		ImageFile();
		ImageFile(const string& n, const int& w, const int& h, const int& d);
		int getWidth() const;
		int getHeight() const;
		int getDepth() const;
		
		virtual int getSize() const;
		void displayProperties() const;
};

#endif

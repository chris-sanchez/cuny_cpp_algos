//main.cpp

#include "main.h"
#include <vector>

void outputFiles(vector<File*> vf){
	File* fp = vf[vf.size()-1];
	if("txt" == fp->getType()){
		((TextFile*)fp)->displayProperties();
	}
	else if("gif" == fp->getType()){
		((ImageFile*)fp)->displayProperties();
	}
	
	if(vf.size()==1){
		return;
	}
	else{
		vf.resize(vf.size()-1);
		outputFiles(vf);
	}
}

vector<File*> filterFiles(vector<File*> vf, string ofType){
	if(vf.size()==0){
		vector<File*> final;
		return final;
	}
	
	File* temp = vf[vf.size()-1];
	vf.resize(vf.size()-1);
	vector<File*> final = filterFiles(vf, ofType);
	if(temp->getType()==ofType){
		final.push_back(temp);
	}
	
	return final;
}

int main(){

	cout << "hello" << endl;
	
	vector<File*> fileVector;
	
	TextFile* t = new TextFile("Hello World", 11);
	File* filePointer = t;
	fileVector.push_back(filePointer);
	
	ImageFile* i = new ImageFile("New Picture", 10, 10, 2);
	filePointer = i;
	fileVector.push_back(filePointer);
	
	vector<File*> filterImages = filterFiles(fileVector, "txt");	
	outputFiles(filterImages);
	
	delete i;
	delete t;

	return 0;
}

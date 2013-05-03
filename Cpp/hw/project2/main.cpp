//main.cpp

#include "main.h"
#include <vector>
#include <fstream>

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

vector<File*> readFromDirectory(vector<File*> fileVector){
	ifstream directoryFile;
	directoryFile.open("files.txt");
	string line;
	
	TextFile* t;
	ImageFile* i;
	int numChar, width, height, depth;
	string name;
	
	if(directoryFile.is_open()){
		while(!directoryFile.eof()){
			directoryFile >> line;
			if(line == "txt"){
				directoryFile >> name;
				directoryFile >> numChar;
				t = new TextFile(name, numChar);
				fileVector.push_back(t);
			}
			else if(line == "gif"){
				directoryFile >> name;
				directoryFile >> width;
				directoryFile >> line;
				directoryFile >> height;
				directoryFile >> depth;
				i = new ImageFile(name, width, height, depth);
				fileVector.push_back(i);
			}
		}
	}
	
	return fileVector;
}


int main(){

	bool isActive = true;
	bool fileLoaded = false;
	char userChar;
	
	vector<File*> vectorFile;
	TextFile* t;
	ImageFile* i;
	int numChar, width, height, depth;
	string name;
	
	while(isActive){
		cout << "What would you like to do?" << endl;
		cout << "enter the number to execute" << endl;
		cout << "1)\tRead from the Directory." << endl;
		cout << "2)\tCreate an Image File." << endl;
		cout << "3)\tCreate a Text File." << endl;
		cout << "4)\tPrint all Files." << endl;
		cout << "5)\tPrint all Image Files." << endl;
		cout << "6)\tPrint all Text Files." << endl;
		cout << "7)\tQuit the Program." << endl;
		
		cin >> userChar;
		
		if(userChar == '1'){
			if(!fileLoaded){
				fileLoaded = true;
				vectorFile = readFromDirectory(vectorFile);
				cout << "The directory was loaded." << endl << endl;
			}
			else{
				cout << "The director has already been loaded." << endl << endl;
			}
		}
		else if(userChar == '2'){
			cout << "Enter the name of the Image File." << endl;
			cin >> name;
			cout << "Enter the width of the Image File." << endl;
			cin >> width;
			cout << "Enter the height of the Image File." << endl;
			cin >> height;
			cout << "Enter the color depth of the Image File." << endl;
			cin >> depth;
			
			i = new ImageFile(name, width, height, depth);
			vectorFile.push_back(i);
			
			cout << "The file has been created." << endl << endl;
		}
		else if(userChar == '3'){
			cout << "Enter the name of the Text File." << endl;
			cin >> name;
			cout << "Enter the number of charecters of the Image File." << endl;
			cin >> numChar;
			
			t = new TextFile(name, numChar);
			vectorFile.push_back(t);
			
			cout << "The file has been created." << endl << endl;		
		}
		else if(userChar == '4'){
			outputFiles(vectorFile);
			cout << endl;
		}
		else if(userChar == '5'){
			outputFiles(filterFiles(vectorFile, "gif"));
			cout << endl;
		}
		else if(userChar == '6'){
			outputFiles(filterFiles(vectorFile, "txt"));
			cout << endl;
		}
		else if(userChar == '7'){
			if(i!=NULL){
				i = NULL;
			}
			if(t!=NULL){
				t = NULL;
			}
			return 0;
		}
		else{
			cout << "You entered an incorrect index" << endl << "Try again" << endl << endl;
		}	
	}
}

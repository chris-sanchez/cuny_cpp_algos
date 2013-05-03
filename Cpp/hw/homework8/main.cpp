//main.cpp

#include "main.h"
int main(){

	cout << "hello" << endl;
	
	TextFile* t = new TextFile("Hello World", 11);
	t->displayProperties();
	
	ImageFile* i = new ImageFile("New Picture", 10, 10, 2);
	i->displayProperties();
	
	

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include "graphic.h"

using namespace std;

graphic::graphic(Info * a) {
	UserData = a;
}

void graphic::draw() {
	int width = UserData->getWidth(), height = UserData->getHeight();
	for(int i = 0;i < width + 2; i++) {
		cout<< "□ ";
	}
	cout<<endl;
	for(int i = 0;i < height;i++) {
		cout<< "□ ";
		for(int j = 0;j < width;j++) {
			if(UserData->data[i][j] == 1) {
				cout<< "□ ";
			}
			else if(UserData->data[i][j] == 2) {
				cout<< "☆ ";
			}
			else {
				cout<< "  ";
			}
		}
		cout<< "□ ";
		cout<<endl;
	}
	for(int i = 0;i < width + 2; i++) {
		cout<< "□ ";
	}
	cout<<endl;

}
void graphic::readfile(string a) {
	ifstream TitleFile(a);
	if(TitleFile.is_open()) {
		while(!TitleFile.eof()) {
			string str;
			getline(TitleFile,str);
			cout<<str<<endl;
		}
		TitleFile.close();
	}
}
void graphic::title() {
	readfile("./graphic/format.txt");
}

void graphic::endTitle() {
	readfile("./graphic/endformat.txt");
}
void graphic::clear() {
	cout << "\x1B[2J\x1B[H";
}
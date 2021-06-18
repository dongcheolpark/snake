#include "info.h"

Info::Info(int width, int height) {
	Width = width;
	Height = height;
	data = new int * [Width];
	for(int i = 0;i<Width;i++) {
		data[i] = new int[Height];
	}
}
/* <getter> */

int Info::getHeight() {
	return Height;
}

int Info::getWidth() {
	return Height;
}

pair<int,int > Info::getbeginPos() {
	return beginPos;
}

pair<int,int > Info::getbeginPos() {
	return endPos;
} 

int Info::getSize() {
	return size;
}
Mv_dir Info::getdir() {
	return mv_dir;
}
/* </getter> */

/* <setter> */
void Info::setbeginPos(int a,int b) {
	beginPos.first = a;
	beginPos.second = b; 
}

void Info::setendPos(int a,int b) {
	endPos.first = a;
	endPos.second = b; 
}
void Info::setsize(int size) {
	this->size = size;
}
/* </setter> */
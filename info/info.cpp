#include "info.h"

Info::Info(int width, int height) {
	Width = width;
	Height = height;
	data = new int * [Width];
	snake_data = new vector<pair<int,int>>;
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
Mv_dir Info::getdir() {
	return mv_dir;
}

vector<pair<int,int>> * Info::getSnakedata() {

}
/* </getter> */

/* <setter> */
void Info::setSnakeData(int x,int y,int value) {
	data[x][y] = value; 
	if(value == 1) {
		snake_data->push_back(make_pair(x,y));
	}
}
/* </setter> */
#include "info.h"

Info::Info() {
	data = new int * [Width];
	for(int i = 0;i<Width;i++) {
		data[i] = new int[Height];
	}
}
int Info::getHeight() {
	return Height;
}
int Info::getWidth() {
	return Height;
}
#ifndef WINDOW_H
#define WINDOW_H
#include "../info/info.h"

class window {
private :
	Info * UserData;
public:
	window(Info * a); 
	void draw();
	void title();
	void clear();
};

#endif
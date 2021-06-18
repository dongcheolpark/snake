#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "../info/info.h"

class graphic {
private :
	Info * UserData;
public:
	graphic(Info * a); 
	void draw();
	void title();
	void clear();
};

#endif
#ifndef MAINGAME_H
#define MAINGAME_H
#include "../info/info.h"
#include "../graphic/graphic.h"

class Maingame {
private:
	graphic * window;
	Info * UserInfo;
public:
	Maingame();
	void init();
	void start();
};
#endif
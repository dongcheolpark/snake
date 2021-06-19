#ifndef MAINGAME_H
#define MAINGAME_H
#include "../info/info.h"
#include "../graphic/graphic.h"

class Maingame {
private:
	graphic * window;
	Info * UserInfo;
	int time;
	void init();
	void mv_snake();
public:
	Maingame();
	void start();
	Mv_dir input();
};
#endif
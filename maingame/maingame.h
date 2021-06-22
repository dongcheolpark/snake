#ifndef MAINGAME_H
#define MAINGAME_H
#include <termios.h>
#include "../info/info.h"
#include "../graphic/graphic.h"

class Maingame {
private:
	graphic * window;
	Info * UserInfo;
	int time_;
	void init();
	void mv_snake();
public:
	Maingame();
	void start();
	int getch();
	Mv_dir input();
	void createRandomGoal();
};
#endif
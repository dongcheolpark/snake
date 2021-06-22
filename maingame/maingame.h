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
	pair<int,int > mv_snake();
	void update_data(pair<int,int > );
	void createRandomGoal();
	bool colidTest(pair<int,int >);
	int getch();
	Mv_dir input();
public:
	Maingame();
	void start();
};
#endif
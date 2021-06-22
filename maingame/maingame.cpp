#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "maingame.h"
#include "../graphic/graphic.h"

Maingame::Maingame() {
	UserInfo = new Info(15,15); //판 사이즈 설정
	window = new graphic(UserInfo);
}

void Maingame::init() {
	int x = UserInfo->getHeight()/2,y = UserInfo->getWidth()/4;

	UserInfo->setSnakeData(x,y-1,1); 
	UserInfo->setSnakeData(x,y,1); 
	UserInfo->setSnakeData(x,y+1,1); 
	//뱀 위치 설정
	UserInfo->setSnakeData(x,y*3+2,2); 
	//먹이 위치 설정
}

int Maingame::getch(void)
{
	int ch;
	struct termios old;
	struct termios newone;
	tcgetattr(0, &old);
	newone = old;
	newone.c_lflag &= ~(ICANON | ECHO);
	newone.c_cc[VMIN] = 1;
	newone.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &newone);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &old);
	return ch;
}

void Maingame::mv_snake() {
	int x,y;
	vector<pair<int,int> > * snakeData = UserInfo->getSnakedata();
	switch(UserInfo->getdir()) {
		case Mv_dir::up:
			x = 1;
			y = 0;
			break;
		case Mv_dir::down:
			x = -1;
			y = 0;
			break;
		case Mv_dir::left:
			x = 0;
			y = -1;
			break;
		case Mv_dir::right:
			x = 0;
			y = 1;
			break;
	}
	x = snakeData->back().first + x;
	y = snakeData->back().second + y;
	if(!(UserInfo->data[x][y] == 2)) {
		pair<int,int> tmp = snakeData->front();
		UserInfo->data[tmp.first][tmp.second] = 0; 
		snakeData->erase(snakeData->begin()); //꼬리 부분 삭제
	}
	else {
		createRandomGoal();
	}
	UserInfo->setSnakeData(x,y,1);//머리부분 이동
}

Mv_dir Maingame::input() {
	while(1) {
		int tmp = getch();
		if(tmp == 91) {
			tmp = getch();
			if(tmp == 68&&this->UserInfo->getdir() != Mv_dir::right) {
				cout<<"left"<<endl;
				return Mv_dir::left;
			}
			else if(tmp == 67&&this->UserInfo->getdir() != Mv_dir::left) {
				cout<<"right"<<endl;
				return Mv_dir::right;
			}
			else if(tmp == 66&&this->UserInfo->getdir() != Mv_dir::down) {
				cout<<"up"<<endl;
				return Mv_dir::up;
			}
			else if(tmp == 65&&this->UserInfo->getdir() != Mv_dir::up) {
				cout<<"down"<<endl;
				return Mv_dir::down;
			}
		}
	}
}

void Maingame::createRandomGoal() {
	srand(unsigned(time(NULL)));
	int x,y;
	do {
		x = rand()%UserInfo->getWidth();
		y = rand()%UserInfo->getHeight(); // 좌표설정
	}while(UserInfo->data[x][y] != 0);

	UserInfo->data[x][y] = 2;
}

void Maingame::start() {
	window->clear(); // 타이틀 생성
	window->title();
	getch();
	init();
	while (1)
	{
		window->clear(); // 게임으로 넘어감
		window->draw();
		UserInfo->setdir(input());
		mv_snake();
	}
}
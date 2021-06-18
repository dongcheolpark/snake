#include <iostream>
#include <unistd.h>
#include "maingame.h"
#include "../graphic/graphic.h"

Maingame::Maingame() {
	UserInfo = new Info(15,15);
	window = new graphic(UserInfo);
}

void Maingame::init() {
	UserInfo->setbeginPos(UserInfo->getHeight()/2,UserInfo->getWidth()/4+1);
	UserInfo->setendPos(UserInfo->getHeight()/2,UserInfo->getWidth()/4-1);

	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4-1] = 1; 
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4] = 1; 
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4+1] = 1; 
	//뱀 위치 설정
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4*3+2] = 2; 
	//먹이 위치 설정
}

void Maingame::mv_snake() {
	int x,y;
	switch(UserInfo->getdir()) {
		case up:
			x = 1;
			y = 0;
			break;
		case down:
			x = -1;
			y = 0;
			break;
		case left:
			x = 0;
			y = -1;
			break;
		case right:
			x = 0;
			y = 1;
			break;
	}
	pair<int,int > begin = UserInfo->getbeginPos();
	pair<int,int > end = UserInfo->getendPos();
	UserInfo->setbeginPos(begin.first + x, begin.second + y);
	data[begin.first + x][begin.second + y] = 1;
}

void Maingame::start() {
	window->clear(); // 타이틀 생성
	window->title();
	getchar();
	init();
	while (1)
	{
		window->clear(); // 게임으로 넘어감
		
		window->draw();
	}
}
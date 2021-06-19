#include <iostream>
#include <unistd.h>
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

void Maingame::mv_snake() {
	int x,y;
	vector<pair<int,int>> * snakeData = UserInfo->getSnakedata();
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
	UserInfo->setSnakeData(x,y,1);//머리부분 이동
	if(!UserInfo->data[x][y] == 2) {
		pair<int,int> tmp = snakeData->front();
		UserInfo->data[tmp.first][tmp.second] = 0; 
		snakeData->erase(snakeData->begin()); //꼬리 부분 삭제
	}
}

Mv_dir Maingame::input() {
	char tmp = getchar();
	while(1) {
		switch (tmp)
		{
			case 75:
				return Mv_dir::left;
			case 77:
				return Mv_dir::right;
			case 72:
				return Mv_dir::up;
			case 80:
				return Mv_dir::down;
		}
	}
}

void Maingame::start() {
	window->clear(); // 타이틀 생성
	window->title();
	getchar();
	init();
	int tmp = 5;
	while (tmp--)
	{
		window->clear(); // 게임으로 넘어감
		input();
		window->draw();
	}
}
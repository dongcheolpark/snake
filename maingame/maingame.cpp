#include <iostream>
#include "maingame.h"
#include "../graphic/graphic.h"

Maingame::Maingame() {
	UserInfo = new Info();
	window = new graphic(UserInfo);
}

void Maingame::init() {
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4-1] = 1; 
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4] = 1; 
	UserInfo->data[UserInfo->getHeight()/2][UserInfo->getWidth()/4+1] = 1; 
	//뱀 위치 설정
}
void Maingame::start() {
	window->clear(); // 타이틀 생성
	window->title();
	getchar();
	init();
	window->clear(); // 게임으로 넘어감
	window->draw();
}
#include <iostream>
#include "./maingame/maingame.h"

using namespace std;

int main() {
	Maingame * game = new Maingame(); 
	game->start();
}
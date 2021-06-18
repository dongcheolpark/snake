#ifndef INFO_H
#define INFO_H
#include <utility>
using namespace std;
enum Mv_dir {up = 1,down = 2,left = 3,right = 4};
class Info {
private : 
	int Width = 15,Height = 15;
	pair<int,int > beginPos,endPos; 
	int size;
	Mv_dir mv_dir;
public:
	int ** data;
	Info(int width,int height);
	int getWidth();
	int getHeight();
	int getSize();
	Mv_dir getdir();
	void setsize(int size);
	void setbeginPos(int a, int b);
	void setendPos(int a, int b);
	pair<int,int > getbeginPos();
	pair<int,int > getbeginPos();
};

#endif
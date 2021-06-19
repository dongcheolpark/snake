#ifndef INFO_H
#define INFO_H
#include <vector>
#include <utility>
using namespace std;
enum Mv_dir {up = 1,down = 2,left = 3,right = 4};
class Info {
private : 
	int Width = 15,Height = 15;
	vector<pair<int,int> > * snake_data;
	Mv_dir mv_dir;
public:
	int ** data;
	Info(int width,int height);
	int getWidth();
	int getHeight();
	vector<pair<int,int>> * getSnakedata();
	Mv_dir getdir();
	void setSnakeData(int x,int y,int value);
};
#endif
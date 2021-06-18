#ifndef INFO_H
#define INFO_H
class Info {
private : 
	const int Width = 15,Height = 15;
public:
	int ** data;
	Info();
	int getWidth();
	int getHeight();
};

#endif
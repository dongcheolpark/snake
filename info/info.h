#ifndef INFO_H
#define INFO_H
class Info {
private : 
	const int Width = 10,Height = 20;
	char ** data;
public:
	Info();
	Info Get_Data();
};

#endif
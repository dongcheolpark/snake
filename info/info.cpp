#include "info.h"

Info::Info() {
	data = new char * [Width];
	for(int i = 0;i<Width;i++) {
		data[i] = new char[Height];
	}
}